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
  Creates a fresh heap allocated uninitialized symbol
  Must be freed via free_symbol()
  Returns NULL if it fails to allocate ANY memory
 */
extern symbol *create_symbol();

/*
  Initializes the symbol
  Returns 1 if it fails
  Returns 0 if it succeeds
  Can be used on both heap and stack allocated symbols
 */
extern int init_symbol(symbol *symbol, char *str, size_t str_len, size_t type);

/*
  Destroys the symbol
  Can be used on both heap and stack allocated symbols
  Only releases its used resources not itself
 */
extern void destroy_symbol(symbol *symbol);

/*
  Destroys the symbol
  Can be ONLY used on heap allocated symbols
  Only releases itself not its resources so pair it with
  destroy_symbol() if you want to get rid of it
 */
extern void free_symbol(symbol *symbol);

//
//
//
// This exists to stop formatter
//
//
//

/*
  This is used in symbol_table dont use this,
  on its own
*/
struct symbol_table_node {
  symbol symbol;
  struct symbol_table_node *next_node;
} typedef symbol_table_node;

/*
  Creates a fresh heap allocated uninitialized symbol_node
  Must be freed via free_symbol_node()
  Returns NULL if it fails to allocate ANY memory
 */
extern symbol_table_node *create_symbol_node();

/*
  Initializes the symbol_node
  Returns 1 if it fails
  Returns 0 if it succeeds
  Can be used on both heap and stack allocated symbols
 */
extern int init_symbol_node(symbol_table_node *symbol_node, char *str,
                            size_t str_len, size_t type);

/*
  Chains child to parent node.
  If Parent has a children fails then returns 1.
  Returns 0 if succeeds.
*/
extern int chain_symbol_node(symbol_table_node *parent,
                             symbol_table_node *child);

/*
  Drops the child node.
  Returns child node if it exists,
  Returns NULL if it doesn't
*/
extern symbol_table_node *symbol_node_drop_chain(symbol_table_node *parent);

/*
  Destroys Parents node and its all LINEAGE <-- dumb word but you get the point.
  If you want the bloodline to continue drop child first
*/
extern void destroy_symbol_node_chain(symbol_table_node *parent);

/*
  Frees symbol_node does NOT releases its child,
  use destroy_symbol_node_chain() first
*/
extern void free_symbol_node(symbol_table_node *parent);

//
//
//
// This exists to stop formatter
//
//
//

/*
  This is a basic chained hashtable
*/
struct symbol_table {
  size_t bucket_count;
  symbol_table_node *symbol_nodes;
} typedef symbol_table;

extern symbol_table* create_symbol_table();
extern void init_symbol_table(symbol_table* table,size_t bucket_size);
extern void destroy_symbol_table(symbol_table* table);
extern void free_symbol_table(symbol_table* table);

extern int add_symbol(symbol_table* table,char* str,size_t str_len,size_t type);
extern int remove_symbol(symbol_table* table,char* str,size_t str_len);
extern int check_symbol(symbol_table* table,char* str,size_t str_len);

#endif
