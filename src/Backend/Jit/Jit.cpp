#include "Jit.hpp"
#include <libgccjit++.h>
#include <libgccjit.h>
#include <optional>

using namespace list::backend;

Jit::Jit() {}

Jit::~Jit() {}

void Jit::init_context() { this->parent_context = gccjit::context::acquire(); }

void Jit::create_types() {

  auto int_type = this->parent_context.get_type(GCC_JIT_TYPE_INT);
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
