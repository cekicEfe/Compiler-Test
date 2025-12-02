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
