#include "Jit.hpp"
#include <libgccjit++.h>
#include <libgccjit.h>
#include <optional>

using namespace list::backend;

Jit::Jit() {}

Jit::~Jit() {}

void Jit::init_context() {
  this->parent_context = gccjit::context::acquire();
  // to create child context
  // gccjit::context child =
  //   this->parent_context.new_child_context();
}

void Jit::create_types() {
  this->int_type = this->parent_context.get_type(GCC_JIT_TYPE_INT);
  this->float_type = this->parent_context.get_type(GCC_JIT_TYPE_FLOAT);
  this->char_type = this->parent_context.get_type(GCC_JIT_TYPE_CHAR);
  this->bool_type = this->parent_context.get_type(GCC_JIT_TYPE_BOOL);
  this->array_type = this->parent_context.get_type(GCC_JIT_TYPE_VOID_PTR);
}

std::optional<gcc_jit_result *> Jit::compile_context() {
  gcc_jit_result *result = this->parent_context.compile();
  if (result == nullptr) {
    return std::nullopt;
  } else {
    return std::make_optional<gcc_jit_result *>(result);
  }
}

void Jit::release_context() { this->parent_context.release(); }
