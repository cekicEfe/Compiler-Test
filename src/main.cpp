#include "Parser.hpp"
#include <FlexLexer.h>
#include "Scanner.hpp"
#include "gc/gc.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  GC_enable_incremental();
  GC_INIT();

  // std::istringstream is("( this is an sexp )"); <-- use this if you want to input string
  calc::Scanner scanner{ std::cin, std::cerr };
  calc::Parser parser{ &scanner };
  std::cout.precision(10);
  parser.parse();
}
