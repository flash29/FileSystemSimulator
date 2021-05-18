#include"commands.h"

extern struct node* current;
extern struct node* root;

void pwd(){
    struct node *temp = malloc(sizeof(struct node*));
    temp = current;

    while(temp != NULL){
        printf("%s/", temp->name);
        temp = temp->parentPtr;
    }
}
