#include"commands.h"

extern struct node* current;
extern struct node* root;

void mkDir(char* pathname){
  int s=0,n = strlen(pathname);
  int flag = 0;
  char basename[64][64], dirname[64];
  char *token;
  // char subs[64];
  // int pi;
  int found = 1, i=0, count =0, t2, notfound =0, check =0;

  struct node *temp = malloc(sizeof(struct node*));
  temp = current;

  struct node *assign = malloc(sizeof(struct node*));

  struct node *tempParent = malloc(sizeof(struct node*));
  tempParent = current;

  /* get the first token */
  token = strtok(pathname, "/");

  /* walk through other tokens */
  while( token != NULL ) {
      strcpy(basename[flag], token);
      flag = flag + 1;
     token = strtok(NULL, "/");
  }

  assign->type = 'D';
  strcpy(assign->name, basename[flag-1] );
 // assign->parentPtr = current;
  assign->childPtr = NULL;
  assign->sibilingPtr = NULL;

  // printf("here %s", assign->name);
  // printf("%d", flag );
  if(flag>1 && temp->childPtr != NULL){
      temp = temp->childPtr;
      while(i<(flag-1) && found ==1){
          t2 = 1;
          while(temp != NULL && t2 == 1){
              if (strcmp(temp->name, basename[i]) == 0 && temp->type =='D'){
                  tempParent = temp;
                  if(temp->childPtr != NULL ){

                      temp = temp->childPtr;
                      if ((i+2)==flag){
                          check = 1;
                      }
                  }
                  count = count + 1;
                  t2 = 0;
              }
              else{
                  if(temp->sibilingPtr != NULL){
                  temp = temp->sibilingPtr;
                    }
                    else{
                        notfound = 1;
                        break;
                    }
              }
          }
          i = i + 1;
      }
}

    if (notfound == 1 || (flag > 1 && temp->childPtr == NULL && count < (flag-1) ) ){
        printf("%s not found \n", pathname);
        return;
    }
    assign->parentPtr = tempParent;

  if (temp->childPtr == NULL && check != 1){
      temp->childPtr = assign;
  }
  else if (check ==1){
      temp = tempParent;
      temp = temp ->childPtr;


      while(temp->sibilingPtr!=NULL){
        temp = temp->sibilingPtr;
      }
      temp->sibilingPtr = assign;
  }
  else{

        temp = temp ->childPtr;


        while(temp->sibilingPtr!=NULL){
          temp = temp->sibilingPtr;
        }
        temp->sibilingPtr = assign;
  }

}
