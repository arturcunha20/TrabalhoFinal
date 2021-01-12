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

void Validos()
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
    /*
    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            printf("ID -> %d | Incio -> %s | Fim -> %s | Tempo-> %d \n",novo[j].id_piloto,novo[j].incio,novo[j].fim,novo[j].tempo);
        }
    }
    */
    printf("Estao %d pilotos validos\n\n",contValidos);
    fclose(file);

}

void TodosPilotos()
{
    int etapas,pilotos,i=0;
    char linha[1024];
    FILE *file;
    Corrida c,novo[100];

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

    /*
    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            printf("ID -> %d | Incio -> %s | Fim -> %s | Tempo-> %d \n",novo[j].id_piloto,novo[j].incio,novo[j].fim,novo[j].tempo);
        }
    }
    */
    printf("Estao %d pilotos\n\n",pilotos);
    fclose(file);

}


void ListarCorridas()
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
    fclose(file);
}

void medias()
{
    int etapas,pilotos,i=0;
    char linha[1024];
    FILE *file,*fileE;
    Corrida c,novo[100],aux;
    char *inicio[10][10][1024],*fim[10][10][1024];

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
        }
        else
        {
            sscanf( linha, "%d;%[^;];%[^;];%d", &c.id_piloto, &c.incio, &c.fim, &c.tempo );
            novo[i-1].id_piloto = c.id_piloto;
            strcpy(novo[i-1].incio,c.incio);
            strcpy(novo[i-1].fim,c.fim);
            novo[i-1].tempo = c.tempo;
        }
        i++;
    }
    fclose(file);

    int as = 0;
    float distancia;
    char incioString[10],fimString[10];


    fileE = fopen("../Etapas.txt","r");
    while (!feof(fileE))
    {
        fscanf(fileE,"%[^;];%[^;];%f\n",incioString ,fimString ,&distancia);


        for(i=0;i<3;i++)
        {
            strcpy(inicio[as][i],incioString);
            strcpy(fim[as][i],fimString);
        }
        /*
        for(i=0;i<2;i++)
        {
            printf("%s",inicio[as][i]);
            //fim[i][as] = fimString[i];
        }
        printf(" ");

        for(i=0;i<2;i++)
        {
            printf("%c",fim[as][i]);
            //fim[i][as] = fimString[i];
        }

        printf("\n");
        */
        //printf("\n\n\n",inicio[i][as]);
        //printf("%s %s\n",incioString[i],fimString[i]);
        as++;

    }
    fclose(fileE);

    for (int k = 0; k < as; k++) {
            printf("%s %s",inicio[k],fim[k]);
            printf("\n");
    }
}

void Rapido_Lento()
{
    int etapas,pilotos,i=0,tempos[pilotos],ola,cont =0,maior=1,menor=214748347,maiorN=0,menorN=0;
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
            cont = cont + novo[j].tempo;
            if((j+1)%etapas == 0)
            {
                ola = novo[j].id_piloto;
                tempos[ola-1] = cont;
                cont = 0;
            }
        }
    }
    for (int j = 0; j < pilotos; j++) {
        if(tempos[j] > maior)
        {
            maior = tempos[j];
            maiorN = j;
        }
        if(tempos[j] < menor)
        {
            menor = tempos[j];
            menorN = j;
        }
    }
    printf("Maior \nTempo -> %d\nID -> %d\n\nMenor \nTempo -> %d\nID -> %d\n",maior,maiorN+1,menor,menorN+1);
    fclose(file);

}

int main() {
    int opcao,opcaoE;
    //InsertPiloto();
    //InsertPiloto();

    //ReadPilotos();
    //ReadEtapas();
    //ReadCorridas();

    printf("1 - Pilotos\n");
    printf("2 - Etapas\n");
    printf("3 - Corrida\n");

    do {
        printf("Diga a opcao -> "); scanf("%d",&opcao);

        switch (opcao) {
            case 1: ReadPilotos();break;
            case 2: ReadEtapas();break;
            case 3:                 do {
                    printf("\n\n1 - Todos pilotos\n2 - Validos\n3 - Listar\n4 - Medias\n5 - Mais Rapido/Mais lento\n0 - Voltar\nOpcao -> "); scanf("%d",&opcaoE);
                    printf("\n");
                    switch (opcaoE) {
                        case 1: TodosPilotos(); break;
                        case 2: Validos(); break;
                        case 3: ListarCorridas(); break;
                        case 4: medias(); break;
                        case 5: Rapido_Lento(); break;
                    }
                } while (opcaoE < 1 && opcaoE > 5 || opcaoE != 0);
                printf("\n");
                break;
        }
    } while (opcao!=0);
    return 0;
}