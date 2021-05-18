#include"commands.h"

extern struct node* current;
extern struct node* root;

void cd(char* pathname){
    struct node *temp = malloc(sizeof(struct node*));
    temp = current;

    if(temp->childPtr!=NULL){
        temp = temp->childPtr;
    }
    else{
        printf("NO DIR");
        return;
    }

    while(temp!=NULL){
        if(strcmp(temp->name, pathname)==0 && temp->type=='D'){
            current = temp;
            break;
        }
        else if(strcmp(temp->name, pathname)==0 && temp->type=='F'){
            printf("%s is a file not a directory \n", pathname);
            return;
        }
        else{
            temp = temp->sibilingPtr;
        }
    }

}
