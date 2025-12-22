#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include "Data.hpp"

namespace lisp::backend {

struct Symbol {
  std::string name;
  std::string type; // class , method or other primitive types like 
  jit_data::Data data ;
  bool immutable = false;
};

class SymbolTable {
private:
  std::unordered_map<std::string, Symbol> symbols;

public:
  SymbolTable();
  ~SymbolTable();

  bool isExist(const std::string &nameOfSymbol);
  bool isMutable(const std::string &nameOfSymbol);
  void setSymbol(const std::string &nameOfSymbol,
                 const jit_data::Data newData, const bool newImmutablity);
  void unsetSymbol(const std::string &nameOfSymbol);
};

} // namespace sym

#endif
