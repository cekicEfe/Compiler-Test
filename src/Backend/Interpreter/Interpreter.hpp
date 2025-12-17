#ifndef INTERPRETTER_CPP
#define INTERPRETTER_CPP

#include "SymbolTable.h"

namespace intpr {

class ConsCell {
  ConsCell *car;
  ConsCell *cdr;
};

class Interpeter {
private:
  sym::SymbolTable symbolTable;
public:
};

} // namespace intpr

#endif
