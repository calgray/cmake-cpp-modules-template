FROM kernelci/clang-17:latest

#libclang-17-dev
RUN apt update && apt install -y libc++-17-dev libc++abi-17-dev python3-pip git ninja-build



RUN apt install wget && wget https://github.com/Kitware/CMake/releases/download/v3.26.4/cmake-3.26.4-linux-x86_64.sh
RUN bash ./cmake-3.26.4-linux-x86_64.sh --prefix=/usr/local --exclude-subdir --skip-license

RUN pip3 install conan==1.60.0

# replace broken symlink
# /usr/lib/clang/17/include -> ../../llvm-17/lib/clang/17.0.0/include
# /usr/lib/clang/17/lib -> ../../llvm-17/lib/clang/17.0.0/lib
RUN cd /usr/lib/clang/17 && ln -s ../../llvm-17/lib/clang/17/include include --force
RUN cd /usr/lib/clang/17 && ln -s ../../llvm-17/lib lib --force

# apt install nano && nano /root/.conan/settings.yml
RUN apt install -y jq && pip3 install yq
RUN conan config init
RUN yq '.compiler.clang.version += [ "17" ]' /root/.conan/settings.yml -i -Y

COPY . /cmake-cpp-modules-template
WORKDIR cmake-cpp-modules-template
RUN mkdir -p build/clang

RUN conan install . -g cmake_multi -if build/clang -s build_type=Release --build=missing --profile=profile-clang.txt

# RUN cmake -B build/clang -G "Ninja Multi-Config" -DCMAKE_CXX_COMPILER=/usr/lib/llvm-17/bin/clang++ -DCONAN_COMPILER=clang -DCONAN_COMPILER_VERSION=17
# RUN cmake --build build/clang --config Release -j8
