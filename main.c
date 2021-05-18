#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"commands.h"
#include"node.h"

// struct node {
//   char name[64];
//   char type;
//   struct node *childPtr;
//   struct node *parentPtr;
//   struct node *sibilingPtr;
// };

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
            mkDir(pathname);
            break;
          case 1:
            rmDir(pathname);
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
            creatf(pathname);
            break;
          case 6:
            removefile(pathname);
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
