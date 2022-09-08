#include"functions.h"



void encrypt(Content*ct){

    FILE *source=NULL;
    FILE *target=NULL;
    char ch;
    char code_char;

    source = fopen(ct->source, "r");
    if (source == NULL) {
      printf("Appuyez sur une touche pour sortir...\n");
      exit(EXIT_FAILURE);
    }
    target = fopen("dest.txt", "w");

    if (target == NULL) {
      fclose(source);
      printf("Appuyez sur une touche pour sortir...\n");
      exit(EXIT_FAILURE);
    }
    ct->current_key_index=0;
    while ((ch = fgetc(source)) != EOF){

        code_char=next_char_encrypt(ch,ct);
        fprintf(target, "%c",code_char);
        
    }
    printf("votre fichier a bien ete crypte.\n");
    fclose(source);
    fclose(target);
    
};

void decrypt(Content*ct){
    FILE *source=NULL;
    FILE *target=NULL;
    char ch;
    char decoded_char;

    source = fopen(ct->source, "r");
    if (source == NULL) {
      printf("Appuyez sur une touche pour sortir...\n");
      exit(EXIT_FAILURE);
    }
    target = fopen("source.txt", "w");

    if (target == NULL) {
      fclose(source);
      printf("Appuyez sur une touche pour sortir...\n");
      exit(EXIT_FAILURE);
    }
    ct->current_key_index=0;

    printf("fichier en claire : \n\n");
    while ((ch = fgetc(source)) != EOF){

        decoded_char=next_char_decrypt(ch,ct);

        printf("%c",decoded_char);

        fprintf(target, "%c",decoded_char);
        
    }
    printf("\n\n");
    printf("votre fichier a bien ete decrypte.\n");
    fclose(source);
    fclose(target);
    
};

char next_char_encrypt(char ch,Content *ct){
    if(ct->current_key_index%strlen(ct->key)==0){
        ct->current_key_index=0;
    }
    ct->current_key_index++;

    return ch-(ct->key[ct->current_key_index]);

};

char next_char_decrypt(char ch,Content *ct){ 
    if(ct->current_key_index%strlen(ct->key)==0){
        ct->current_key_index=0;
    }
    ct->current_key_index++;

    return ch+(ct->key[ct->current_key_index]);

};


int flush_input(FILE *fp) {
    int c;
    while ((c = getc(fp)) != EOF && c != '\n')
        continue;
    return c;
}