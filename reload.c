#include"commands.h"

extern struct node* current;
extern struct node* root;


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
            mkDir(path);
        }
        else{
            // printf("%s\n", path);
            creatf(path);
        }
        c= getc(fptr);
    }
    printf("Recreated the filesystem");
    fclose(fptr);

}
