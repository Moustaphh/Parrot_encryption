#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {

    char source[10];
    char key[20];

}Content;



void encrypt(Content*);
void decrypt(Content*);
void display(Content*);

void create_perroc(char* key);
int flush_input(FILE *fp);
int is_key(char *key);
void remove_file(char *);

#endif
