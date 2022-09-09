#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {

    char source[10];
    char key[10];

}Content;



void encrypt(Content*);
void decrypt(Content*);
void display(Content*);

int flush_input(FILE *fp);

void remove_file(char *);

#endif
