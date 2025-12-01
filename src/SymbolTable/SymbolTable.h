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

struct symbol_table_node {
  int in_use;
  symbol symbol;
  struct symbol_table_node *next_node;
} typedef symbol_table_node;

struct symbol_table {
  int bucket_count;
  symbol_table_node *key_values;
} typedef symbol_table;

#endif
