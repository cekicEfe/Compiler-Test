#include "SymbolTable.h"
#include <stdexcept>

using namespace sym;

SymbolTable::SymbolTable() {}
SymbolTable::~SymbolTable() {}

bool SymbolTable::isExist(const std::string &name) {
  auto it = this->symbols.find(name);
  if (it != this->symbols.end()) {
    return true;
  } else
    return false;
}

void SymbolTable::defineSymbol(const Symbol &sym) {
  if (!this->isExist(sym.name))
    this->symbols[sym.name] = sym;
  else
    throw std::invalid_argument("Given symbol already exists");
}

void SymbolTable::setSymbol(const std::string &nameOfSymbol,
                            const std::string &newType, const Data newData,
                            const bool newImmutablity) {
  if (this->isExist(nameOfSymbol)) {
    if (this->symbols[nameOfSymbol].immutable != true)
      this->symbols[nameOfSymbol] =
          Symbol{nameOfSymbol, newType, newData, newImmutablity};
    else
      throw std::invalid_argument("Given symbol is not mutable");
  } else
    throw std::invalid_argument("Given symbol does not exists");
}

void SymbolTable::unsetSymbol(const std::string &nameOfSymbol) {
  if (auto pos = this->symbols.find(nameOfSymbol); pos != this->symbols.end()) {
    this->symbols.erase(pos);
  } else {
    throw std::invalid_argument("Given symbol does not exists");
  }
}
