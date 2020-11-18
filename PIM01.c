//Arquivo contendo código referente ao PIM01
//Aqui será criado o código conforme sugerido.

//TODO: Anotar principais comandos do Git e GitHub
//Para poder manipular branches locais e remotos.

//Para iniciar o trabalho, é preciso fazer um pull
//a partir do GitHub, então criar um novo branch local,
//fazer um push de volta pra o GitHub, fazer as alteracões
//nesse branch e, por fim, fazer um merge de volta
//para o GitHub. Por fim, é necessário deletar os
//branches não utilizados.

//É necessário também buscar um tamplate para o
//Overleaf com as regras ABNT e buscra no AVA
//quais as exigências e recomendacões para o 
//PIM01.

//Para trabalhar com arquivos, utilizamos:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_string(char *st)
{
    char *s = malloc(100);
    printf(st);
     if (fgets(s, 99, stdin))
     {
            char *p;
            if(p=strchr(s, '\n'))
            {//check exist newline
                *p = 0;
            } else {
                scanf("%*[^\n]");
                scanf("%*c");//clear upto newline
            }
        return s;
     }
     return s;
} 

int get_int(char *st){
    int i, y;
    printf(st);
    scanf("%d", &y);
    while ((y = getchar()) != '\n' && y != EOF)
    {i = y;}
    return i;
}

int main(void)
{
    
    char *nome = get_string("Nome: ");
    //printf("Seu nome é: %s", nome);

    int idade = get_int("Idade: ");
    //printf("Sua idade é: %d", idade);
    FILE *file = fopen("build/agenda.txt", "a");
    fprintf(file, "%s,%d\n", nome, idade);

    fclose(file);
    return 0;
}