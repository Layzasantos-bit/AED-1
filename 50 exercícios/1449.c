
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max1 81
#define max2 81

//montar uma tabela hash          

struct node{
    char palavrajapones[max1]; 
    char palavraportugues[max1];
    struct node *prox;
};

typedef struct node no;


char traduzir_palavra(no* )


int main(){
    int t, m, n;
    char *palavra;

    printf("Instancia:\n");
    scanf("%d", &t);
    
    for(int z=0; z<t; z++){
    printf("palavras e linhas:\n");
    scanf("%d %d", &m, &n);
    getchar();

    //alocar o dicionário
    no* dicionario = (no*)malloc(m*sizeof(no));

    for(int i=0; i<m; i++){
        fgets(dicionario[i].palavrajapones, max1, stdin);
        fgets(dicionario[i].palavraportugues, max1, stdin);

        //remove o newline no final da frase

        dicionario[i].palavrajapones[strcspn(dicionario[i].palavrajapones, "\n")] = '\0';
        dicionario[i].palavraportugues[strcspn(dicionario[i].palavraportugues, "\n")] = '\0';


    }
    //salvando a linha da música
    for(int i=0; i<n; i++){
        char linha[max2];
        fgets(linha, max2, stdin);

        linha[strcspn(linha, "\n")] = '\0';

        palavra = strtok(linha, " ");
        int primeira_palavra = 1;

        while(palavra != NULL){
            if(!primeira_palavra){
                printf(" ");
            }
            printf("%s", traduzir_palavra(dicionario, m, palavra));
            primeira_palavra = 0;
            palavra = strtok(NULL, " ");
        }
        
        printf("\n");

    }
    if(z<t-1){
        printf("\n");
    }

    free(dicionario); //libera a memoria do dicionario

}

