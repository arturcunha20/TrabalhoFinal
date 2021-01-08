#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char inicio[50];
    char fim[50];
    float distancia;
}Etapa;

typedef struct
{
    int id;
    char nome[50];
    char marca[50];

}Piloto;

typedef struct
{
    int id_piloto;
    char incio[10];
    char fim[10];
    int tempo;
}Corrida;

void InsertPiloto()
{
    FILE *file;
    int res,contPiloto;
    Piloto p;
    fflush(stdin);

    file = fopen("../Pilotos.txt","r");
    while (!feof(file)) // feof devolve 0 ou 1
    {
        res = fscanf(file,"%d;%[^;];%[^;];\n",&p.id,&p.nome,&p.marca);
    }

    if(res<0)
    {
        contPiloto = 0;
    }
    else{
        contPiloto = p.id;
    }
    fclose(file);
    fflush(stdin);
    printf("Diga o nome do piloto  -> "); gets(p.nome);

    printf("\nDiga a marca do carro -> "); gets(p.marca);

    p.id = contPiloto + 1;
    printf("\n\n");
    file = fopen("../Pilotos.txt","a");
    fprintf(file,"%d;%s;%s;\n",p.id,p.nome,p.marca);
    fclose(file);
}

void ReadEtapas()
{
    int res;
    FILE *file;
    Etapa e;

    file = fopen("../Etapas.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%[^;];%[^;];%f\n",&e.inicio ,&e.fim ,&e.distancia);

        printf("Inicio -> %s | Fim -> %s | Distancia -> %.5f\n\n",e.inicio,e.fim ,e.distancia);

    }

    printf("\n\n");
    fclose(file);
}


void ReadCorridas()
{
    int res,res1,etapas,pilotos,i=0;
    FILE *file;
    Corrida c;
    char linha[1024],token[1024];

    file = fopen("../Corridas.txt","r");
    while (!feof(file))
    {
        fscanf(file,"%s\n",&linha);
        if(i == 0)
        {
            strcpy(token, strtok(linha, ";"));
            etapas = atoi(token);
            strcpy(token, strtok(NULL, ";"));
            pilotos = atoi(token);
            printf("Etapas -> %d | Pilotos -> %d\n",etapas,pilotos);
            //res = fscanf(file,"%d;%d\n",&etapas,&pilotos);
        }
        else
        {
            strcpy(token, strtok(linha, ";"));
            c.id_piloto = atoi(token);
            //printf("%s\n",linha);
            strcpy(c.incio, strtok(NULL, ";"));
            strcpy(c.fim, strtok(NULL, ";"));

            strcpy(token, strtok(NULL, ";"));
            c.tempo = atoi(token);
            //printf("%s\n",linha);
            //res1 = fscanf(file,"%d;%[^;];%[^;];%d\n",&c.id_piloto,&c.incio,&c.fim,&c.tempo);
            printf("ID -> %d | Incio -> %s | Fim -> %s | Tempo-> %d\n\n",c.id_piloto,c.incio,c.fim,c.tempo);
        }
        i++;
    }
    fclose(file);
}


void ReadPilotos()
{
    int res;
    FILE *file;
    Piloto p;

    file = fopen("../Pilotos.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d;%[^;];%[^;];\n",&p.id ,&p.nome ,&p.marca);

        printf("Id -> %d | Nome -> %s | Marca -> %s\n\n",p.id ,p.nome ,p.marca);

    }

    printf("\n\n");
    fclose(file);
}
int main() {
    //InsertPiloto();
    //InsertPiloto();

    //ReadPilotos();
    //ReadEtapas();
    ReadCorridas();
    return 0;
}