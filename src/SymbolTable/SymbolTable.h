#ifndef MY_SYMBOL_TABLE_H
#define MY_SYMBOL_TABLE_H

#include "gc/gc.h"
#include <stddef.h>

// The symbols must be immortal values in gc!

// djb2
// this algorithm (k=33) was first reported by dan bernstein many years ago in
// comp.lang.c. another version of this algorithm (now favored by bernstein)
// uses xor: hash(i) = hash(i - 1) * 33 ^ str[i]; the magic of number 33 (why it
// works better than many other constants, prime or not) has never been
// adequately explained.

//     unsigned long
//     hash(unsigned char *str)
//     {
//         unsigned long hash = 5381;
//         int c;
//         while (c = *str++)
//             hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
//         return hash;
//     }

struct symbol {
  char *symbol_str;
  size_t symbol_str_len;

  size_t symbol_type;
} typedef symbol;

/*
  Create symbol with given str and type
  Returns NULL if memory allocations fail
*/
extern symbol *create_symbol(const char *const str, const size_t str_len,
                             const size_t type);

/*
  Safely frees the symbol and its resources
*/
extern void destroy_symbol(symbol *symbol);

/*
  Copies current symbol to dest
  Returns 0 if succeeds
  Returns 1 if any memory allocation fails
*/
extern int copy_symbol(const symbol *const src, symbol *dest);

struct symbol_table_node {
  int in_use;
  symbol symbol;
  struct symbol_table_node *next_node;
} typedef symbol_table_node;

struct symbol_table {
  int bucket_count;
  symbol_table_node *key_values;
} typedef symbol_table;

extern symbol_table *create_symbol_table(size_t bucket_size);

extern void destroy_symbol_table(symbol_table *table);

extern int add_to_table(symbol_table *table, symbol *symbol);

extern void remove_from_table(symbol_table *table,
                                            symbol *symbol);

extern int check_from_table(symbol_table *table, symbol *symbol);

#endif
