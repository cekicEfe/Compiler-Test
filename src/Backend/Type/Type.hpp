#ifndef TYPE_H
#define TYPE_H

#include <variant>
namespace lisp::backend {

class Type {

public:
  enum class type {
    //
    CLASS,
    CLASS_METHOD,
    ADT
  };

  enum class type_primitive {
    //
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    ARRAY,
    REF,
    FUNCTION
  };

  Type(std::variant<type, type_primitive> type);
  ~Type();

  std::variant<type, type_primitive> getType();
  void setType(std::variant<type, type_primitive> type);

private:
  std::variant<type, type_primitive> currentType;
};

} // namespace lisp::backend

#endif
