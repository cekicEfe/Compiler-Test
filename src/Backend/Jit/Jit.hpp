#ifndef LISP_JIT_HPP
#define LISP_JIT_HPP

#include <libgccjit++.h>
#include <libgccjit.h>
#include <optional>

namespace list::backend {

class Jit {
private:
  gccjit::context parent_context;

  void init_context();
  void create_types();
  std::optional<gcc_jit_result *> compile_context();
  void release_context();

public:
  Jit();
  ~Jit();
};

} // namespace list::backend

#endif
