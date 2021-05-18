#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"node.h"

#ifndef commands_h
#define commands_h

void mkDir(char* pathname);
void rmDir(char* pathname);
void creatf(char* pathname);
void list();
void menu();
void pwd();
void removefile(char *pathname);
void reload();
void cd(char* pathname);
void preOrder(struct node *temp, FILE *fptr, char* pathData);
void save();

#endif
