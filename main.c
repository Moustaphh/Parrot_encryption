#include"functions.h"



int main(){

    char inp;
    printf("\n  ===============================================  \n\n");
    printf("Entrez E ou crypter et D decrypter  ===>   ");
    scanf("%c",&inp);

    Content ct;

    if (inp=='E'){
        printf("\n  ===============================================  \n\n");
        printf("Entrez le chemin du fichier a crypter ===>   ");
        flush_input(stdin);
        scanf("%s",ct.source);
        // printf("votre fichier source est %s \n ",ct.source);
        printf("\n  ===============================================  \n\n");
        printf("Entrez votre perroquet ===>  ");
        flush_input(stdin);
        scanf("%s",ct.key);

        encrypt(&ct);
        create_perroc(ct.key);

    }else if (inp=='D'){

        printf("\n  ===============================================  \n\n");
        printf("Entrez le chemin du fichier a decrypter :  ");
        flush_input(stdin);
        scanf("%s",ct.source);
        flush_input(stdin);
        printf("\n  ===============================================  \n\n");
        printf("Entrez votre perroquet :  ");
        scanf("%s",ct.key);
        flush_input(stdin);

        if(is_key(ct.key)){
        printf("confirmation de l acces  \n\n ");
        printf("\n  ===============================================  \n\n");
        decrypt(&ct);
        printf("\n  ===============================================  \n\n");

        }else{
        printf("\n  ===============================================  \n\n");
        printf(" mauvaise cle ");
        printf("\n  ===============================================  \n\n");
        }


    }
    return EXIT_SUCCESS;


}
