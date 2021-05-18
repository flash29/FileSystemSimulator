#include"commands.h"

extern struct node* current;
extern struct node* root;

void preOrder(struct node *temp, FILE *fptr, char* pathData){

    char pd1[64];
    char pd2[64];
    char tempStore[64];

    strcpy(tempStore, pathData);
    strcat(tempStore, temp->name);

    fprintf(fptr,"%c %s\n", temp->type,tempStore);

    if (temp->childPtr != NULL){
        strcpy(pd1,tempStore);
        strcat(pd1,"/");
        preOrder(temp->childPtr, fptr, pd1);
    }
    if (temp->sibilingPtr != NULL){

        strcpy(pd2,pathData);
        strcat(pd2,"/");
        preOrder(temp->sibilingPtr, fptr, pd2);
    }

}

void save(){
    struct node *temp = malloc(sizeof(struct node*));

    FILE *fptr;
    fptr = fopen("system.txt", "w+");

    temp = root;
    temp = temp->childPtr;
    preOrder(temp, fptr, "/" );
    fclose(fptr);
}
