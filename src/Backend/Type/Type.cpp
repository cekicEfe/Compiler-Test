#include "Type.hpp"

using namespace lisp::backend;

Type::Type(std::variant<Type::type, Type::type_primitive> type) {
  this->currentType = type;
}
Type::~Type() {}

std::variant<Type::type, Type::type_primitive> Type::getType() {
  return this->currentType;
}
void Type::setType(std::variant<Type::type, Type::type_primitive> type) {
  this->currentType = type;
}
