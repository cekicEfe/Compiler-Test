#include "SymbolTable.h"
#include <malloc.h>

/*
  Create symbol with given str and type
  Returns NULL if memory allocations fail
*/
symbol *create_symbol(const char *const str, const size_t str_len,
                      const size_t type) {
  symbol *result = (symbol *)malloc(sizeof(symbol));
  result->symbol_str = 
}

/*
  Safely frees the symbol and its resources
*/
void destroy_symbol(symbol *symbol) {}

/*
  Copies current symbol to dest
  Frees dest so dont use it at r values!!!
  returns 1 if any memory allocation fails
*/
int copy_symbol(const symbol *const src, symbol *dest) {}
