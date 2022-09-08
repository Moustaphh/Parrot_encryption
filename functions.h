#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {

char source[10],key[10];
int current_key_index;

}Content;



void encrypt(Content*);
void decrypt(Content*);
void display(Content*);

char next_char_encrypt(char,Content*);
char next_char_decrypt(char,Content*);
int flush_input(FILE *fp);

#endif
