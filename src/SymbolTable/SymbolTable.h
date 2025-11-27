#ifndef MY_SYMBOL_TABLE_H
#define MY_SYMBOL_TABLE_H

#include "gc/gc.h"
#include <stddef.h>

// The symbols must be immortal values in gc!

struct symbol {
  char *symbol_str;
  size_t symbol_str_len;

  symbol_type type;
} typedef symbol;

struct symbol_node {
  int id;

  struct symbol_node *next_node;
} typedef symbol_node;

struct symbol_list {
  symbol_node *root;
} typedef symbol_list;

symbol_list *create_symbol_list(void);
int push_symbol(symbol_list *list, );

#endif
