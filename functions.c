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
    target = fopen("dest.crt", "w");

    if (target == NULL) {
      fclose(source);
      printf("Appuyez sur une touche pour sortir...\n");
      exit(EXIT_FAILURE);
    }

    int i =0;
    int keylen =strlen(ct->key);

    printf("fichier crypté : \n");
    while ((ch = fgetc(source)) != EOF){
        code_char=(ch-(ct->key[i%keylen]));

        fprintf(target, "%c",code_char);
        i++;
        
    }
    printf("votre fichier a bien ete crypte.\n");

    fclose(source);
    fclose(target);
    remove_file(ct->source);
    
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

    int i =0;
    int keylen =strlen(ct->key);
    fseek(source, 0L, SEEK_END);//seek to the end of the file;
    int sz = ftell(source);//get the current position of the cursor
    // printf("the file size is %d \n",sz);
    rewind(source);//seek to the beginning 

    printf("fichier en clair : \n\n");
    while ((ftell(source)!=sz)){
        ch = fgetc(source); 
        decoded_char=(ch+(ct->key[i%keylen]));

        printf("%c",decoded_char);
        fprintf(target, "%c",decoded_char);
        i++;
         
    }
    printf("votre fichier a bien ete decrypte.\n");
    fclose(source);
    fclose(target);
    
};


int flush_input(FILE *fp) {
    int c;
    while ((c = getc(fp)) != EOF && c != '\n')
        continue;
    return c;
}

void remove_file(char *filename){
   if (remove(filename) == 0) {
        printf("Le fichier source a ete supprime \n");
    } else {
        printf("Le fichier source n a pas ete supprime. \n");
    }

}