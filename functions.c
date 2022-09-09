#include"functions.h"



void encrypt(Content*ct){
    //takes a content object pointer and perfoms an encryption using the key.

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
    //opens dest.crt files and create it if it doesnt exist, and overrides the content.

    if (target == NULL) {
      fclose(source);
      printf("Appuyez sur une touche pour sortir...\n");
      exit(EXIT_FAILURE);
    }

    int i =0;//counter that will allow to loop over the key.
    int keylen =strlen(ct->key);

    printf("fichier crypté : \n");
    while ((ch = fgetc(source)) != EOF){
    
        code_char=(ch-(ct->key[i%keylen]));
        //the code char is generated by substracting the ith element of the key.
        // loops over the key indexes and goes back to 0 when i is equal to keylen.

        fprintf(target, "%c",code_char);
        i++;
        
    }
    printf("votre fichier a bien ete crypte.\n");

    fclose(source);
    fclose(target);
    remove_file(ct->source);//removes the source file after the encryption
    
};

void decrypt(Content*ct){
    //takes a content object pointer and perfoms a decryption using the key.
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
    //saves the decrypted code in  source.txt

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
    //when decrypting we need to know the file size, if some characters are encrypted to -1 whick is the EOF.
    
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