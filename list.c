#include"commands.h"

extern struct node* current;
extern struct node* root;

void list(){
  struct node *temp = malloc(sizeof(struct node*));
  temp = current;

  if (temp->childPtr!=NULL){
      temp = temp->childPtr;
      printf("%s\t", temp->name);
      while(temp->sibilingPtr!=NULL){
        temp= temp->sibilingPtr;
        printf("%s\t", temp->name);
      }
      printf("\n");
  }



}
