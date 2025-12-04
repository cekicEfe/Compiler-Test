#ifndef MY_SYMBOL_TABLE_H
#define MY_SYMBOL_TABLE_H

#include <string>
#include <unordered_map>

class Data;

namespace sym {

struct Symbol {
  std::string name;
  std::string type;
  Data data ;
  bool immutable = false;
};

class SymbolTable {
private:
  std::unordered_map<std::string, Symbol> symbols;

public:
  SymbolTable();
  ~SymbolTable();

  bool isExist(const std::string &name);
  void defineSymbol(const Symbol &symbol);
  void setSymbol(const std::string &nameOfSymbol, const std::string &newType,
                 const Data newData, const bool newImmutablity);
  void unsetSymbol(const std::string &nameOfSymbol);
};

} // namespace sym

#endif
