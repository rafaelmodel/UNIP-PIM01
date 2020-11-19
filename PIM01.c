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

char *cadastro = "build/agenda.txt";

int isNumeric(const char *str)
{
    while(*str != '\0')
    {
        if(*str < '0' || *str > '9')
            return 0; // falso
        str++;
    }
    return 1; //verdadeiro
}

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

int *get_int(char *st)
{
    int *i = malloc(100*sizeof(int));
    printf(st);
    scanf("%d", &i);    
    fflush(stdin);
    return i;
}

typedef struct grupo_de_risco
{
    int id;
    char *nome;
    char *cep;
}Grupo_de_risco;

typedef struct paciente 
{
    int id ;
    char *nome;
    char *cpf;
    char *telefone;
    char *endereco;
    char *nasc;
    char *email;
    char *datadiag;
    char *comorbidade;
}Paciente;

char* get_date(char *st)
{    
    char* str = (char*)malloc(100);
    int *dd = malloc(2*sizeof(int));
    int *mm = malloc(2*sizeof(int));
    int *yy = malloc(4*sizeof(int));
    printf(st);
    scanf("%d/%d/%d",dd,mm,yy);
    
    //check year
    if(*yy>=1900 && *yy<=9999)
    {     
        //check month
        if(*mm>=1 && *mm<=12)
        {
            //check days
            if((*dd>=1 && *dd<=31) && (*mm==1 || *mm==3 || *mm==5 || *mm==7 || *mm==8 || *mm==10 || *mm==12))
            {
                
            }
            else if((*dd>=1 && *dd<=30) && (*mm==4 || *mm==6 || *mm==9 || *mm==11))
            {
                
            }
            else if((*dd>=1 && *dd<=28) && (*mm==2))
            {
               
            }
            else if(*dd==29 && *mm==2 && (*yy%400==0 ||(*yy%4==0 && *yy%100!=0)))
            {
               
            }
            else
            {
                printf("\n erro DIA \n");
                get_date(st);
            }
        }
        else
        {
            printf("\n erro MÊS \n");
            get_date(st);
        }
    }
    else
    {
        printf("\n erro ANO \n");
        get_date(st);
    }

    sprintf(str, "%d/%d/%d", *dd, *mm, *yy);   
    char *p;
    if(p=strchr(str, '\n'))
    {//check exist newline
        *p = 0;
    } else {
        scanf("%*[^\n]");
        scanf("%*c");//clear upto newline
    }        
    return str;
}

char* get_name(char *str)
{
    char* tmp_nome = get_string(str);
    if (isNumeric(tmp_nome) == 0)
    {
        return tmp_nome;
    }
    else
    {   
        printf("Nome inválido.\n");
        get_name(str);
    }
    
}

Paciente* novo_cadastro(void)
{
    Paciente* p = (Paciente*)malloc(sizeof(Paciente));
    p->id = 0;    
    p->nome = get_name("Nome: ");    
    p->cpf = get_string("CPF: ");
    p->telefone = get_string("Telefone: ");
    p->endereco = get_string("Endereco: ");
    p->nasc = get_date("Data de nascimento no formato (DD/MM/AAAA) ");
    p->email = get_string("E-mail: ");
    p->datadiag = get_date("Data do diagnóstico no formato (DD/MM/AAAA): ");
    p->comorbidade = get_string("Comorbidade: ");
    return p;
}

void salva_cadastro(Paciente* p, char *path)
{        
    FILE *file = fopen(path, "a");
    fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s\n",
        p->id,
        p->nome,
        p->cpf,
        p->telefone,
        p->endereco,
        p->nasc,
        p->email,
        p->datadiag,
        p->comorbidade
    );
    fclose(file);
}

int main(void)
{
    char *n_c = get_string("Novo cadastro?: y\n");
   
    if (strcmp(n_c, "y") != 0)
    { return 0; }

    Paciente *nc = novo_cadastro();
    salva_cadastro(nc, cadastro);
    //char* datt = get_date("data");
   // printf("\n testandoMAIN \n");
    //printf("test%s",datt);    
    return 0;
}