#include<stdio.h>

#ifndef node_h
#define node_h

struct node {
  char name[64];
  char type;
  struct node *childPtr;
  struct node *parentPtr;
  struct node *sibilingPtr;
};

#endif
