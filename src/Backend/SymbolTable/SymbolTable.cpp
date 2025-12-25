#include "SymbolTable.hpp"
#include <stdexcept>

using namespace lisp::backend;

SymbolTable::SymbolTable() {}
SymbolTable::~SymbolTable() {}

bool SymbolTable::isExist(const std::string &name) {
  auto it = this->symbols.find(name);
  if (it != this->symbols.end()) {
    return true;
  } else
    return false;
}

bool SymbolTable::isMutable(const std::string &nameOfSymbol){
  bool exist = this->isExist(nameOfSymbol);
  if(exist){
    return this->symbols[nameOfSymbol].immutable;
  }else{
    throw std::invalid_argument("Given symbol : " + nameOfSymbol + " -> Does not exists");
  }
}
