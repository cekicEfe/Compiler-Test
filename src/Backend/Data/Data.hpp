#ifndef DATA_HPP
#define DATA_HPP

#define USING_GCC_JIT

#ifdef USING_GCC_JIT
#include <libgccjit++.h>
#include <libgccjit.h>
#endif

namespace lisp::backend {

class Data {

private:
#ifdef USING_GCC_JIT
  gcc_jit_result *heldData;
  gccjit::type type;
#endif

public:
#ifdef USING_GCC_JIT
  Data(gccjit::context &cxt, const std::string &symbol_name , const std::string &type);
#endif
  ~Data();
};
} // namespace jit_data

#endif
