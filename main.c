#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SEPARADOR -14

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

typedef struct
{
    int id_piloto;
    char nome[50];
    char marca[50];
    int tempo;

}Tempos;

void ReadPilotos()
{
    int res;
    FILE *file;
    Piloto p;
    printf("\n");
    file = fopen("../Pilotos.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d;%[^;];%s\n",&p.id ,&p.nome ,&p.marca);

        printf("Id -> %d | Nome -> %s | Marca -> %s\n",p.id ,p.nome ,p.marca);

    }

    printf("\n");
    fclose(file);
}

void ReadEtapas()
{
    int res;
    FILE *file;
    Etapa e;

    printf("\n");
    file = fopen("../Etapas.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%[^;];%[^;];%f\n",&e.inicio ,&e.fim ,&e.distancia);

        printf("Inicio -> %s | Fim -> %s | Distancia -> %.2f KM\n",e.inicio,e.fim ,e.distancia);

    }

    printf("\n");
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
    printf("Estao %d pilotos validos",contValidos);
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
    printf("Estao %d pilotos",pilotos);
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


    for (int j = 0; j < (etapas*pilotos); ++j) {
        if (novo[j].id_piloto != 0)
        {
            printf("ID -> %d | Incio -> %s | Fim -> %s | Tempo-> %d \n",novo[j].id_piloto,novo[j].incio,novo[j].fim,novo[j].tempo);
        }

    }
    fclose(file);
}

void medias()
{
    int etapas,pilotos,i=0,tempos[20],as = 0;
    char linha[1024],*inicio[10][10][1024],*fim[10][10][1024],incioString[10],fimString[10];
    float distancia;
    FILE *file,*fileE;
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
            sscanf( linha, "%d;%[^;];%[^;];%d", &c.id_piloto, &c.incio, &c.fim, &c.tempo);
            novo[i-1].id_piloto = c.id_piloto;
            strcpy(novo[i-1].incio,c.incio);
            strcpy(novo[i-1].fim,c.fim);
            novo[i-1].tempo = c.tempo;
        }
        i++;
    }
    fclose(file);



    fileE = fopen("../Etapas.txt","r");
    while (!feof(fileE))
    {
        fscanf(fileE,"%[^;];%[^;];%f\n",incioString ,fimString ,&distancia);

        for(i=0;i<=etapas;i++)
        {
            strcpy(inicio[as][i],incioString);
            strcpy(fim[as][i],fimString);
        }
        as++;

    }
    fclose(fileE);

    for (int k = 0; k < (pilotos*etapas); k++) {
        for (int j = 0; j < etapas; j++) {
            if(strcmp(inicio[j],novo[k].incio) == 0 && strcmp(fim[j],novo[k].fim) == 0 )
            {
                for (int l = 0; l < etapas; l++) {
                    if(strcmp(novo[k].incio,inicio[l]) == 0)
                    {
                        tempos[l] = tempos[l]+novo[k].tempo;
                    }
                }
            }
        }
    }
    float ola;
    for (int i = 0; i < etapas; i++) {
        ola = 0;
        ola = tempos[i]/pilotos;
        printf("Etapa %s-%s -> %.2f\n",inicio[i],fim[i],ola);
    }
}

void tempo_minimo()
{
    int etapas,pilotos,i=0,tempos[20],as = 0;
    char linha[1024],*inicio[10][10][1024],*fim[10][10][1024],incioString[10],fimString[10];
    float distancia;
    FILE *file,*fileE;
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
            sscanf( linha, "%d;%[^;];%[^;];%d", &c.id_piloto, &c.incio, &c.fim, &c.tempo);
            novo[i-1].id_piloto = c.id_piloto;
            strcpy(novo[i-1].incio,c.incio);
            strcpy(novo[i-1].fim,c.fim);
            novo[i-1].tempo = c.tempo;
        }
        i++;
    }
    fclose(file);



    fileE = fopen("../Etapas.txt","r");
    while (!feof(fileE))
    {
        fscanf(fileE,"%[^;];%[^;];%f\n",incioString ,fimString ,&distancia);

        for(i=0;i<=etapas;i++)
        {
            strcpy(inicio[as][i],incioString);
            strcpy(fim[as][i],fimString);
        }
        as++;

    }
    fclose(fileE);

    for (int k = 0; k < (pilotos*etapas); k++) {
        for (int j = 0; j < etapas; j++) {
            if(strcmp(inicio[j],novo[k].incio) == 0 && strcmp(fim[j],novo[k].fim) == 0 )
            {
                for (int l = 0; l < etapas; l++) {
                    if(strcmp(novo[k].incio,inicio[l]) == 0)
                    {
                        tempos[l] = tempos[l]+novo[k].tempo;
                    }
                }
            }
        }
    }


    int min[etapas],soma=0;

    for (int i = 0; i < etapas; i++) {
        min[i] = 214748347;
    }

    for (int k = 0; k < (pilotos*etapas); k++) {
        for (int j = 0; j < etapas; j++) {
            if(strcmp(inicio[j],novo[k].incio) == 0 && strcmp(fim[j],novo[k].fim) == 0)
            {
                for (int l = 0; l < etapas; l++) {
                    if(strcmp(novo[k].incio,inicio[l]) == 0)
                    {

                        if(novo[k].tempo < min[l])
                        {
                            min[l] = novo[k].tempo;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < etapas; i++) {
        soma = soma + min[i];
    }

    printf("Tempo Minimo -> %d\n",soma);

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
    }

    for (int j = 0; j < pilotos; j++) {
        if(tempos[j] < menor)
        {
            menor = tempos[j];
            menorN = j;
        }
    }

    printf("Mais Lento \nTempo -> %d\nID -> %d\n\nMais Rapido \nTempo -> %d\nID -> %d\n",maior,maiorN+1,menor,menorN+1);
    fclose(file);
}

void velocidadeMedia()
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

    int cont =0,contValidos = 0;
    int velocidades[pilotos][etapas];
    i=0;
    for (int j = 0; j < 100; j++) {
        if (novo[j].id_piloto != 0)
        {
            if(novo[j].tempo > 0)
            {
                cont++;
            }

            if(cont == etapas)
            {
                for (int k = 0; k < pilotos; k++) {
                    for (int j = 0; j < etapas; j++) {
                        velocidades[k][j] = 0;
                        velocidades[k][j] = velocidades[k][j] + novo[i].tempo;
                        i++;
                    }
                }
            }
        }
    }

    int velocidadesTotal[pilotos];
    float horas[pilotos];
    for (int k = 0; k < pilotos; k++) {
        velocidadesTotal[k] = 0;
        for (int j = 0; j < etapas; j++) {
            if (velocidades[k][j] != 0)
            {
                velocidadesTotal[k] = velocidadesTotal[k] + velocidades[k][j];
            }
            else
            {
                velocidadesTotal[k] = 0;
                break;
            }

        }
    }

    float distancia,dis;
    FILE *fileE;
    char incioString[10],fimString[10],as=0;

    fileE = fopen("../Etapas.txt","r");
    while (!feof(fileE))
    {
        fscanf(fileE,"%[^;];%[^;];%f\n",incioString ,fimString ,&dis);
        distancia = distancia + dis;
        as++;
    }
    fclose(fileE);

    Piloto p[pilotos];
    FILE *fileP;
    as = 0;
    fileP = fopen("../Pilotos.txt","r");
    while (!feof(fileP))
    {
        fscanf(fileP,"%d;%[^;];%s\n",&p[as].id ,&p[as].nome ,&p[as].marca);
        as++;
    }
    fclose(fileP);



    float velocidadeMedia;
    for (int k = 0; k < pilotos; k++) {
        for (int i = 0; i <= pilotos+1; i++) {
            if (i == p[k].id)
            {
                if(velocidadesTotal[k] != 0)
                {
                    velocidadeMedia = (float)(distancia/(velocidadesTotal[k]*2.7777777777778E-7));
                    printf("%s (%s) -> %.2f KM/H\n",p[k].nome,p[k].marca,velocidadeMedia);
                }
                else
                {
                    printf("%s (%s) -> Tempo Invalido\n",p[k].nome,p[k].marca);
                }

            }
        }
    }
    fclose(file);
}

void Tabela()
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
            sscanf( linha, "%d;%[^;];%[^;];%d", &c.id_piloto, &c.incio, &c.fim, &c.tempo);
            novo[i-1].id_piloto = c.id_piloto;
            strcpy(novo[i-1].incio,c.incio);
            strcpy(novo[i-1].fim,c.fim);
            novo[i-1].tempo = c.tempo;
        }
        i++;
    }
    fclose(file);

    Piloto p[100];
    FILE *fileP;
    int as = 0;
    fileP = fopen("../Pilotos.txt","r");
    while (!feof(fileP))
    {
        fscanf(fileP,"%d;%[^;];%s\n",&p[as].id ,&p[as].nome ,&p[as].marca);
        as++;
    }
    fclose(fileP);

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

    int cont =0;
    Tempos eee[pilotos];

    for (int j = 0; j < pilotos; ++j) {
        eee[j].id_piloto = 0;
        eee[j].tempo = 0;
    }

    i=0;
    char nome[50],marca[50];
    for (int j = 0; j < 100; j++) {
        if (novo[j].id_piloto != 0)
        {
            if(novo[j].tempo > 0)
            {
                cont++;
            }

            if(cont == etapas)
            {
                for (int k = 0; k < pilotos; k++) {
                    for (int j = 0; j < etapas; j++) {
                        eee[k].tempo = eee[k].tempo + novo[i].tempo;
                        eee[k].id_piloto = novo[i].id_piloto;
                        i++;
                    }
                }
            }

        }

    }

    for (int j = 0; j < pilotos; ++j) {
        for (int j = 0; j < as; ++j) {
            if (eee[j].id_piloto == p[j].id)
            {
                strcpy(eee[j].nome,p[j].nome);
                strcpy(eee[j].marca,p[j].marca);
            }
        }
    }

    for (int j = 0; j < pilotos; ++j) {
        printf("%d %s %s %d\n",eee[j].id_piloto,eee[j].nome,eee[j].marca,eee[j].tempo);
    }

    Tempos aux1;

    for (int j = 0; j < pilotos; ++j) {
        for (int i = 0; i < pilotos; ++i) {
             if(eee[i].tempo > eee[j].tempo)
             {
                 aux1 = eee[i];
                 eee[i] = eee[j];
                 eee[j] = aux1;
             }

        }
    }


    printf("%*s | %*s | %*s | %*s | %*s | %*s | %*s \n",
           SEPARADOR, "Posicao",
           SEPARADOR, "Numero",
           SEPARADOR, "Nome",
           SEPARADOR, "Marca",
           SEPARADOR, "Tempo",
           SEPARADOR, "Di.Ant",
           SEPARADOR, "Di.Ldr"
    );

    int z=0;
    int tempAnt,tempLed;
    for (int k = 0; k < pilotos; k++) {
        for (int i = 0; i <= as; i++) {
            if (eee[k].id_piloto == p[i].id)
            {
                if(z == 0)
                {
                    printf("%*d | %*d | %*s | %*s | %*d | %*s | %*s \n",
                           SEPARADOR, z+1,
                           SEPARADOR, eee[k].id_piloto,
                           SEPARADOR, eee[k].nome,
                           SEPARADOR, eee[k].marca,
                           SEPARADOR, eee[k].tempo,
                           SEPARADOR, "0.0",
                           SEPARADOR, "0.0"

                    );
                }
                else
                {
                    tempAnt = eee[k].tempo - eee[k - 1].tempo;
                    tempLed = eee[k].tempo - eee[0].tempo;
                    printf("%*d | %*d | %*s | %*s | %*d | %*d | %*d \n",
                           SEPARADOR, z + 1,
                           SEPARADOR, eee[k].id_piloto,
                           SEPARADOR, eee[k].nome,
                           SEPARADOR, eee[k].marca,
                           SEPARADOR, eee[k].tempo,
                           SEPARADOR, tempAnt,
                           SEPARADOR, tempLed

                    );
                    //printf("%d | Numero -> %d | Nome -> %s | Marca -> %s | Tempo-> %d | Di.Ant -> %d | Di.Ldr -> %d\n",z+1,p[i].id,p[i].nome,p[i].marca,eee[k].tempo,tempAnt,tempLed);
                }
                z++;
            }
        }
    }

    z=0;
    int kk=0;
    if(as != pilotos)
    {
        for (int k = 0; k < as; k++) {
            z=0;
            for (int i = 0; i < pilotos; i++) {

                if (eee[i].id_piloto == p[k].id)
                {
                    z++;
                }
                if(i%pilotos == pilotos-1 && z == 0)
                {
                    printf("%*s | %*d | %*s | %*s | %*s | %*s | %*s \n",
                           SEPARADOR, "-",
                           SEPARADOR, eee[k].id_piloto,
                           SEPARADOR, eee[k].nome,
                           SEPARADOR, eee[k].marca,
                           SEPARADOR, "-",
                           SEPARADOR, "-",
                           SEPARADOR, "-"

                    );
                }
            }
        }
    }

}

int main() {
    int opcao,opcaoE;
    //InsertPiloto();
    //InsertPiloto();

    //ReadPilotos();
    //ReadEtapas();
    //ReadCorridas();

    do {
        printf("1 - Pilotos\n");
        printf("2 - Etapas\n");
        printf("3 - Corrida\n");
        printf("Diga a opcao -> "); scanf("%d",&opcao);

        switch (opcao) {
            case 1: ReadPilotos();break;
            case 2: ReadEtapas();break;
            case 3:                 do {
                    printf("\n\n1 - Todos pilotos\n2 - Validos\n3 - Listar\n4 - Medias\n5 - Mais Rapido/Mais lento\n6 - Tempo minimo\n7 - Velocidade Media\n8 - Tabela Classificatoria\n0 - Voltar\nOpcao -> "); scanf("%d",&opcaoE);
                    printf("\n");
                    switch (opcaoE) {
                        case 1: TodosPilotos(); break;
                        case 2: Validos(); break;
                        case 3: ListarCorridas(); break;
                        case 4: medias(); break;
                        case 5: Rapido_Lento(); break;
                        case 6: tempo_minimo(); break;
                        case 7: velocidadeMedia();break;
                        case 8: Tabela();break;
                    }
                } while (opcaoE < 1 && opcaoE > 7 || opcaoE != 0);
                printf("\n");
                break;
        }
    } while (opcao!=0);
    return 0;
}