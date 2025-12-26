#ifndef LISP_JIT_HPP
#define LISP_JIT_HPP

#include <libgccjit++.h>
#include <libgccjit.h>
#include <optional>

namespace list::backend {

class Jit {
private:
  gccjit::context parent_context;

  //primitive types for ease of use
  gccjit::type int_type; 
  gccjit::type float_type;
  gccjit::type char_type;
  gccjit::type bool_type;
  gccjit::type array_type;

public:
  Jit();
  ~Jit();

  void init_context();
  void create_types();
  std::optional<gcc_jit_result *> compile_context();
  void release_context();
};

} // namespace list::backend

#endif
