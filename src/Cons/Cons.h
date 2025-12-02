#ifndef CONS_H
#define CONS_H

struct cell_struct;

struct cons_cell{
  struct cell_struct* current;
  struct cons_cell* dereference;
}typedef cons_cell ;

#endif
