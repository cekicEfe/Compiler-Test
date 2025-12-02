/* Smoketest example for libgccjit.so
   Copyright (C) 2014-2024 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "Parser.tab.hh"
#include "gc/gc.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  GC_enable_incremental();
  GC_INIT();

  FooLexer lexer;
  yy::parser parser(lexer);
  return parser();  
}
