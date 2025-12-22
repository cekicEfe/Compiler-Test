#ifndef INTERPRETTER_CPP
#define INTERPRETTER_CPP

#include "SymbolTable.h"
#include <memory>
#include <variant>

namespace lisp::backend {

class ConsCell {
private:
  std::variant<std::unique_ptr<ConsCell>,
               std::unique_ptr<void>>
      mCar; // I am sorry for my warcrimes then and till hereafter
  std::unique_ptr<ConsCell> mCdr;

public:
  ConsCell();
  ~ConsCell();
  std::variant<std::unique_ptr<ConsCell>, std::unique_ptr<void>> car();
  std::unique_ptr<ConsCell> cdr();
};

class Interpeter {
private:
  lisp::backend::SymbolTable symbolTable;

public:
};

} // namespace intpr

#endif
