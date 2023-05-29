module;
#include "async.h"
#include <pybind11/buffer_info.h>
#include <pybind11/functional.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>

export module pybind11;

export namespace pybind11
{
    using pybind11::buffer_protocol;
    using pybind11::buffer_info;
    using pybind11::format_descriptor;

    using pybind11::init;
    using pybind11::arg;
    using pybind11::slice;
    using pybind11::class_;
    using pybind11::enum_;
    using pybind11::array_t;
    using pybind11::array;
    using pybind11::exception;
    using pybind11::object;
    using pybind11::capsule;

    using pybind11::module_;
};

export namespace pybind11::detail
{
    using pybind11::detail::f_strides;
    using pybind11::detail::op_id;
};

export namespace pybind11::async
{
    using pybind11::async::enable_async;
    using pybind11::async::class_async;
};
