#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

typedef struct {

char source[10],dest[10],key[10];

int bool_reading_mode;
int bool_crypting_mode;

}Content;

void encrypt(Content*);
void decrypt(Content*);
void display(Content*);
void content_init(Content *,char *src, char *dest);
#endif
