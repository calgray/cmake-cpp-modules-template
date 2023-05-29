FROM debian:bookworm

# LLVM 7
RUN apt update && apt install -y lsb-release wget software-properties-common gnupg
RUN wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc
RUN add-apt-repository -y 'deb http://apt.llvm.org/unstable/  llvm-toolchain main'
RUN add-apt-repository -y 'deb http://apt.llvm.org/unstable/  llvm-toolchain main'
RUN apt update && apt install -y clang-17 clang-tools-17 libc++-17-dev libc++abi-17-dev

# CMake 3.26
RUN apt install wget && wget https://github.com/Kitware/CMake/releases/download/v3.26.4/cmake-3.26.4-linux-x86_64.sh
RUN bash ./cmake-3.26.4-linux-x86_64.sh --prefix=/usr/local --exclude-subdir --skip-license
# replace broken symlinks
# /usr/lib/clang/17/include -> ../../llvm-17/lib/clang/17.0.0/include
# /usr/lib/clang/17/lib -> ../../llvm-17/lib/clang/17.0.0/lib
RUN cd /usr/lib/clang/17 && ln -s ../../llvm-17/lib/clang/17/include include --force
RUN cd /usr/lib/clang/17 && ln -s ../../llvm-17/lib/clang/17/lib lib --force

# Extra Packages
RUN apt update && apt install -y python3-pip ninja-build pipx

# Patch Conan settings
RUN pipx run conan==1.60.0 config init
RUN apt install -y jq
RUN pipx run yq '.compiler.clang.version += [ "17" ]' /root/.conan/settings.yml -i -Y

# Build Conan packages
WORKDIR cmake-cpp-modules-template
COPY conanfile.txt profile-clang-debian.txt /cmake-cpp-modules-template/
RUN mkdir -p build/clang
RUN pipx run conan==1.60.0 install . -g cmake_multi -if build/clang -s build_type=Release --build=missing --profile=profile-clang-debian.txt

# Build Project
COPY . /cmake-cpp-modules-template
RUN cmake -B build/clang -G "Ninja Multi-Config" -DCMAKE_CXX_COMPILER=/usr/bin/clang++-17 -DCONAN_COMPILER=clang -DCONAN_COMPILER_VERSION=17
RUN cmake --build build/clang --config Release -j8

CMD ./build/clang/foobar/tests/Release/foobar_tests
