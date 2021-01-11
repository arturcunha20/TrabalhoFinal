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
    int etapas,pilotos,i=0;
    char linha[1024];
    FILE *file;
    Corrida c,novo[100],aux;

    for (int j = 0; j < 100; ++j) {
            novo[j].id_piloto = 0;
    }

    file = fopen("../Corridas.txt","r");
    while (!feof(file))
    {
        fscanf(file,"%s\n",&linha);
        c.id_piloto = 0;
        c.tempo = 0;
        strcpy(c.incio,"-");
        strcpy(c.fim,"-");
        if(i == 0)
        {
            sscanf( linha, "%d;%d", &etapas,&pilotos);
            printf("Etapas -> %d | Pilotos -> %d\n",etapas,pilotos);
        }
        else
        {
            sscanf( linha, "%d;%[^;];%[^;];%d", &c.id_piloto, &c.incio, &c.fim, &c.tempo );
            //printf("ID -> %d | Incio -> %s | Fim -> %s | Tempo-> %d\n",c.id_piloto,c.incio,c.fim,c.tempo);
            novo[i-1].id_piloto = c.id_piloto;
            strcpy(novo[i-1].incio,c.incio);
            strcpy(novo[i-1].fim,c.fim);
            novo[i-1].tempo = c.tempo;
        }
        i++;
    }





    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            for (int i = 0; i < 100; ++i) {
                if (novo[i].id_piloto != 0)
                {
                    if(novo[i].id_piloto >= novo[j].id_piloto)
                    {
                        aux = novo[i];
                        novo[i] = novo[j];
                        novo[j] = aux;
                    }
                }
            }
        }
    }

    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            for (int i = 0; i < 100; ++i) {
                if (novo[i].id_piloto != 0)
                {
                    if(novo[i].id_piloto == novo[j].id_piloto)
                    {
                        if(novo[i].tempo >= novo[j].tempo)
                        {
                            aux  = novo[i];
                            novo[i] = novo[j];
                            novo[j] = aux;
                        }
                    }
                }
            }
        }
    }

    int cont =0,contValidos = 0;
    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            if(novo[j].tempo > 0)
            {
                cont++;
            }

            if(cont == etapas)
            {
                contValidos++;
                cont = 0;
            }
        }
    }

    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            printf("ID -> %d | Incio -> %s | Fim -> %s | Tempo-> %d \n",novo[j].id_piloto,novo[j].incio,novo[j].fim,novo[j].tempo);
        }
    }

    printf("\n\nEstao %d pilotos \n",pilotos);
    printf("Estao %d pilotos validos",contValidos);
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

        printf("Id -> %d | Nome -> %s | Marca -> %s\n",p.id ,p.nome ,p.marca);

    }

    printf("\n\n");
    fclose(file);
}
int main() {
    int opcao;
    //InsertPiloto();
    //InsertPiloto();

    //ReadPilotos();
    //ReadEtapas();
    //ReadCorridas();

    printf("Pilotos\n");
    printf("Etapas\n");
    printf("Corrida\n");

    do {
        printf("Diga a opcao -> "); scanf("%d",&opcao);

        switch (opcao) {
            case 1: ReadPilotos();break;
            case 2: ReadEtapas();break;
            case 3: ReadCorridas();break;
        }
    } while (opcao!=0);

    return 0;
}