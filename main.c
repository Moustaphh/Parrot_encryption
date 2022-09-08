#include"functions.h"



int main(){

    char inp;
    printf("entrez E ou crypter et D decrypter  :  ");
    scanf("%c",&inp);
    Content ct;

    if (inp=='E'){
        printf("entrez le chemin du fichier a crypter :  ");
        flush_input(stdin);
        scanf("%s",ct.source);
        printf("votre ficheir source est %s \n ",ct.source);

        printf("entrez votre perroquet :  ");
        flush_input(stdin);
        scanf("%s",ct.key);

        encrypt(&ct);
    }else if (inp=='D'){

        printf("entrez le chemin du fichier a decrypter :  ");
        flush_input(stdin);
        scanf("%s",ct.source);
        flush_input(stdin);
        printf("entrez votre perroquet :  ");
        scanf("%s",ct.key);
        flush_input(stdin);
        decrypt(&ct);

    }


}
