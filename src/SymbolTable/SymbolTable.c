#include "SymbolTable.h"
#include <malloc.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*
  Create symbol with given str and type
  Returns NULL if memory allocations fail
*/
symbol *create_symbol(const char *const str, const size_t str_len,
                      const size_t type) {
  symbol *result = (symbol *)malloc(sizeof(symbol));
  if (result != NULL) {
    //                                  vvvvvvvvvvvvv->to include null char
    result->symbol_str = (char *)malloc((str_len + 1) * sizeof(char));
    if (result->symbol_str != NULL) {
      result->symbol_str_len = str_len;
      strncpy(result->symbol_str, str, str_len);
      result->symbol_type = type;
    }
  }
  return result;
}

/*
  Safely frees the symbol and its resources
*/
void destroy_symbol(symbol *symbol) {
  free(symbol->symbol_str);
  free(symbol);
}

/*
  Copies current symbol to dest
  Returns 0 if succeeds
  Returns 1 if any memory allocation fails
*/
int copy_symbol(const symbol *const src, symbol *dest) {
  char *hold = (char *)malloc((src->symbol_str_len + 1) * sizeof(char));
  if (hold != NULL) {
    free(dest->symbol_str);
    dest->symbol_str = hold;
    dest->symbol_str_len = src->symbol_str_len;
    strncpy(dest->symbol_str, src->symbol_str, src->symbol_str_len);
    dest->symbol_type = src->symbol_type;
  } else {
    return 1;
  }
  return 0;
}

symbol_table *create_symbol_table(size_t bucket_size);
void destroy_symbol_table(symbol_table *table);
int add_to_symbol_table(symbol_table *table, symbol *symbol);

void remove_symbol_from_symbol_table(symbol_table *table, symbol *symbol);
int check_symbol_from_symbol_table(symbol_table *table, symbol *symbol);
