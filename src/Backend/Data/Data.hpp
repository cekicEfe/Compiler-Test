#ifndef DATA_HPP
#define DATA_HPP

#define USING_GCC_JIT 1

#ifdef USING_GCC_JIT
#include <libgccjit++.h>
#define WITH_GCCJIT_BACKEND(x) x
#endif

namespace jit_data {

class Data {
  WITH_GCCJIT_BACKEND(public : gccjit::type type;)
};

} // namespace jit_data

#endif
