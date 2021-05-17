#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node {
  char name[64];
  char type;
  struct node *childPtr;
  struct node *parentPtr;
  struct node *sibilingPtr;
};

struct node *root;
struct node *current;



char* cmd[] ={"mkdir", "rmdir","ls", "cd", "pwd","creat","rm","reload", "save","menu","quit",NULL};



int findCmd(char* command){
  int i=0;
  while(cmd[i]){
    if(!strcmp(command,cmd[i])){
      return i;
    }
    i++;
  }
  return -1;
}

void initiate(){

    root = malloc(sizeof(struct node*));

    strcpy(root->name, "/home");
    root->type = 'D';
    root->parentPtr = NULL;
    root->childPtr = NULL;
    root->sibilingPtr = NULL;
    current = root;


}


void mkdir(char* pathname){
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

void creat(char* pathname){
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

  assign->type = 'F';
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

void error(){
    fprintf(stderr, "No dir found \n EXITING Program\n");
}

void rmdir(char *pathname){
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
        error();
    }



}

void rm(char *pathname){
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
          if(strcmp(temp->name, pathname)==0 && temp->type=='F'){
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
        error();
    }



}

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

void menu(){
    printf("Commands that can be used: \n");
    printf("mkdir   - create a directory \n");
    printf("rmdir   - remove a directory\n");
    printf("ls      - list all files in present directory \n");
    printf("cd      - change directory\n");
    printf("pwd     - present working directory \n");
    printf("creat   - create a file \n");
    printf("rm      - remove a file\n");
    printf("reload  - reload previously created filesystem \n");
    printf("save    - save the filesystem created \n");
    printf("menu    - list of all commands to use \n");
    printf("quit    - Exit the simulation \n");
}

void pwd(){
    struct node *temp = malloc(sizeof(struct node*));
    temp = current;

    while(temp != NULL){
        printf("%s/", temp->name);
        temp = temp->parentPtr;
    }
}

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

void reload(){
    FILE *fptr;
    fptr = fopen("system.txt", "r");
    char type, path[256];
    int c;

    if (fptr == NULL){
        printf("No filesystem previously saved\n");
        return;
    }
    c = getc(fptr);
    while(c != EOF){
        fscanf(fptr,"%c %s",&type, path);
        if(type == 'D' || c == 'D'){
            // printf("%s\n", path);
            mkdir(path);
        }
        else{
            // printf("%s\n", path);
            creat(path);
        }
        c= getc(fptr);
    }
    printf("Recreated the filesystem");
    fclose(fptr);

}


int main(){
  char line[128], pathname[64], command[16];
  int commandEntered;
  int condition = 1;




  initiate();

  while(condition){

      printf("linux@ranjeet$- ");
      fgets(line,128,stdin);
      line[strlen(line)-1]=0;
      sscanf(line,"%s %s",command,pathname);

      commandEntered = findCmd(command);

      switch(commandEntered){
          case 0:
            mkdir(pathname);
            break;
          case 1:
            rmdir(pathname);
            break;
          case 2 :
            list();
            break;
          case 3 :
            cd(pathname);
            break;
          case 4 :
            pwd();
            break;
          case 5:
            creat(pathname);
            break;
          case 6:
            rm(pathname);
            break;
          case 7:
            reload();
            break;
          case 8 :
            save();
            break;
          case 9 :
            menu();
            break;
          case 10 :
            condition =0;
            break;
          default :
            printf("Invalid Command Entered \n");
            menu();
            break;

      }
}

}
