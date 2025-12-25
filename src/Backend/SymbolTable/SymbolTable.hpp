#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <unordered_map>


namespace lisp::backend {

struct Symbol {
  std::string name;
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
                 const bool newImmutablity);
  void unsetSymbol(const std::string &nameOfSymbol);
};

} // namespace sym

#endif
