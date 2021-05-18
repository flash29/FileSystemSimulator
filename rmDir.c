#include"commands.h"

extern struct node* current;
extern struct node* root;

// void error(){
//     fprintf(stderr, "No dir found \n EXITING Program\n");
// }

void rmDir(char *pathname){
    struct node *temp = malloc(sizeof(struct node*));
    struct node *prev = malloc(sizeof(struct node*));
    struct node *next = malloc(sizeof(struct node*));
    int flag =0;
    temp = current;
    prev = current;



    if(temp->childPtr!=NULL){
      temp = temp ->childPtr;
    //  strcmp(temp->name, pathname);

      while(temp){
          flag = flag +1;
          next = temp->sibilingPtr;
          if(strcmp(temp->name, pathname)==0 && temp->type=='D'){
              if (flag ==1){
                  prev->childPtr = next;
              }
              else{
                  prev->sibilingPtr = next;
              }

          }
          prev = temp;
          temp = temp->sibilingPtr;
        }
    }
    else{
         fprintf(stderr, "No dir found \n EXITING Program\n");
    }



}
