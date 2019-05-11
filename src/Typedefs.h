#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct typedef_list
{
  char *type_id;
  struct typedef_list *next;
} *g_typedefs = NULL;

struct typedef_list *addtype(char const *newtype);
int existstype(char const *xtype);

#endif // !__TYPEDEFS_H__

