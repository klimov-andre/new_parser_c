#include "Typedefs.h"

struct typedef_list *addtype(char const *newtype)
{
  struct typedef_list *tmp = (struct typedef_list*)malloc(sizeof(struct typedef_list));
  
  tmp->type_id = (char*)malloc(strlen(newtype)+1);
  strcpy(tmp->type_id, newtype);
  tmp->next = NULL;
  
  if (!g_typedefs)
  {
    g_typedefs = tmp;
  }
  else
  {
    tmp->next = g_typedefs;
    g_typedefs = tmp;
  }
}


int existstype(char const *xtype)
{
  struct typedef_list *tmp;

  tmp = g_typedefs;
  while (tmp)
  {
    if (0 == strcmp(xtype, tmp->type_id))
    {
      return 1;
    }
    tmp = tmp->next;
  }
  return 0;
}


void printall()
{
  struct typedef_list *tmp;

  tmp = g_typedefs;
  while (tmp)
  {
    printf("%s\n",tmp->type_id);
    tmp = tmp->next;
  }
}

//
//int main()
//{
//  printall();
//  addtype("void");
//  addtype("int");
//  addtype("char");
//  addtype("tyyyoe");
//  addtype("wadawdawd");
//  printall();
//  printf("%d\n", checktype("dint"));
//  return 0;
//}
