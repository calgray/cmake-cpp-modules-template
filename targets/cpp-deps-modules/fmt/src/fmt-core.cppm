// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

module;

#include <fmt/core.h>
#include <fmt/xchar.h>
#include <fmt/ranges.h>

export module fmt.core;


export namespace fmt {
  // [format.context], class template basic_format_context
  using fmt::basic_format_context;
  using fmt::format_context;
  using fmt::wformat_context;

  // [format.args], class template basic_format_args
  using fmt::basic_format_args;
  using fmt::format_args;
  using fmt::wformat_args;

  // [format.fmt.string], class template basic_format_string
  using fmt::basic_format_string;
  using fmt::format_string;
  using fmt::wformat_string;

  // [format.functions], formatting functions
  using fmt::format;
  using fmt::format_to;
  using fmt::vformat;
  using fmt::vformat_to;

  using fmt::format_to_n;
  using fmt::format_to_n_result;
  using fmt::formatted_size;

  // [format.formatter], formatter
  using fmt::formatter;

  // [format.formattable], concept formattable
  // using fmt::formattable;
  using fmt::is_formattable;

  // [format.parse.ctx], class template basic_format_parse_context
  using fmt::basic_format_parse_context;
  using fmt::format_parse_context;
  using fmt::wformat_parse_context;

  // [format.range], formatting of ranges
  // [format.range.fmtkind], variable template format_kind
  // using fmt::format_kind;
  using fmt::range_format_kind;
  using fmt::range_format;

  // [format.range.formatter], class template range_formatter
  using fmt::range_formatter;

  // [format.arg], class template basic_format_arg
  using fmt::basic_format_arg;
  // using fmt::visit_format_arg;

  // [format.arg.store], class template format-arg-store
  using fmt::make_format_args;
  using fmt::make_wformat_args;

  // [format.error], class format_error
  using fmt::format_error;

  // [fmt]
  using fmt::runtime;
  using fmt::arg;
  using fmt::print;
  using fmt::println;
  using fmt::vprint;
  // using fmt::format_arg_store;
  // using fmt::dynamic_format_arg_store;

  // fmt format
} // namespace fmt
