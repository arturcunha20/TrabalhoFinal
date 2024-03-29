#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SEPARADOR -14
#define SEPARADORID -6

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
    printf("%*s | %*s | %*s \n",
           SEPARADORID, "ID",
           SEPARADOR, "Nome",
           SEPARADOR, "Marca"

    );
    while (!feof(file))
    {
        res = fscanf(file,"%d;%[^;];%s\n",&p.id ,&p.nome ,&p.marca);
        printf("%*d | %*s | %*s \n",
               SEPARADORID, p.id,
               SEPARADOR, p.nome,
               SEPARADOR, p.marca

        );
        //printf("Id -> %d | Nome -> %s | Marca -> %s\n",p.id ,p.nome ,p.marca);

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
    printf("%*s | %*s | %*s \n",
           SEPARADORID, "Inicio",
           SEPARADOR, "Fim",
           SEPARADOR, "Distancia (KM)"

    );
    while (!feof(file))
    {
        res = fscanf(file,"%[^;];%[^;];%f\n",&e.inicio ,&e.fim ,&e.distancia);
        printf("%*s | %*s | %*.2f \n",
               SEPARADORID, e.inicio,
               SEPARADOR, e.fim,
               SEPARADOR, e.distancia

        );
        //printf("Inicio -> %s | Fim -> %s | Distancia -> %.2f KM\n",e.inicio,e.fim ,e.distancia);

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
    printf("Etapas -> %d | Pilotos -> %d\n\n",etapas,pilotos);
    printf("%*s | %*s | %*s | %*s \n",
           SEPARADORID, "ID",
           SEPARADOR, "Inicio",
           SEPARADOR, "Fim",
           SEPARADOR, "Tempo"

    );
    for (int j = 0; j < (etapas*pilotos); ++j) {
        if (novo[j].id_piloto != 0)
        {
            printf("%*d | %*s | %*s | %*d \n",
                   SEPARADORID, novo[j].id_piloto,
                   SEPARADOR, novo[j].incio,
                   SEPARADOR, novo[j].fim,
                   SEPARADOR, novo[j].tempo
            );
            //printf("ID -> %d | Incio -> %s | Fim -> %s | Tempo-> %d \n",novo[j].id_piloto,novo[j].incio,novo[j].fim,novo[j].tempo);
        }
        if((j+1)%etapas == 0 )
        {
            if(j != etapas*pilotos-1)
            {
                printf("\n\n");
                printf("%*s | %*s | %*s | %*s \n",
                       SEPARADORID, "ID",
                       SEPARADOR, "Inicio",
                       SEPARADOR, "Fim",
                       SEPARADOR, "Tempo"
                );
            }

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
    printf("\n");
    int etapas,pilotos,i=0,tempos[pilotos],ola = 0,cont =0,maior=1,menor=214748347,maiorN=0,menorN=0;
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
    int cont123 =0,contValidos = 0;
    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            if(novo[j].tempo > 0)
            {
                cont123++;
            }

            if(cont123 == etapas)
            {
                contValidos++;
                cont123 = 0;
            }
        }
    }

    Tempos novoT[contValidos];

    int cont22=0,temp=0,ash=0;
    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            if(novo[j].tempo > 0)
            {
                cont22++;
                temp = temp + novo[j].tempo;
            }

            if ((j+1)%etapas == 0)
            {
                if (cont22 == etapas)
                {
                    novoT[ash].tempo = temp;
                    novoT[ash].id_piloto = novo[j].id_piloto;
                    ash++;
                }
                temp = 0;
                cont22 = 0;
            }

        }
    }

    for (int j = 0; j < contValidos; ++j) {
        for (int k = 0; k < as; ++k) {
            if (novoT[j].id_piloto == p[k].id)
            {
                strcpy(novoT[j].nome,p[k].nome);
                strcpy(novoT[j].marca,p[k].marca);
            }
        }
    }

    for (int j = 0; j < pilotos; j++) {
        if(novoT[j].tempo > maior)
        {
            maior = novoT[j].tempo ;
            maiorN = novoT[j].id_piloto;
        }
    }

    for (int j = 0; j < pilotos; j++) {
        if(novoT[j].tempo  < menor)
        {
            menor = novoT[j].tempo ;
            menorN = novoT[j].id_piloto;
        }
    }



    for (int j = 0; j < pilotos; ++j) {
        if (novoT[j].id_piloto == maiorN)
        {
            printf("Mais Lento \nTempo -> %d\nID -> %d | Nome -> %s\n\n",maior,maiorN,novoT[j].nome);
        }
    }


    for (int j = 0; j < pilotos; ++j) {
        if (novoT[j].id_piloto == menorN)
        {
            printf("Mais Rapido \nTempo -> %d\nID -> %d | Nome -> %s",menor,menorN,novoT[j].nome);
        }
    }
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

    int cont123 =0,contValidos = 0;
    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            if(novo[j].tempo > 0)
            {
                cont123++;
            }

            if(cont123 == etapas)
            {
                contValidos++;
                cont123 = 0;
            }
        }
    }

    Tempos novoT[contValidos];

    int cont22=0,temp=0,ash=0;
    for (int j = 0; j < 100; ++j) {
        if (novo[j].id_piloto != 0)
        {
            if(novo[j].tempo > 0)
            {
                cont22++;
                temp = temp + novo[j].tempo;
            }

            if ((j+1)%etapas == 0)
            {
                if (cont22 == etapas)
                {
                    novoT[ash].tempo = temp;
                    novoT[ash].id_piloto = novo[j].id_piloto;
                    ash++;
                }
                temp = 0;
                cont22 = 0;
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



    for (int j = 0; j < as; ++j) {
        for (int k = 0; k < as; ++k) {
            if (eee[j].id_piloto == p[k].id)
            {
                strcpy(eee[j].nome,p[k].nome);
                strcpy(eee[j].marca,p[k].marca);
            }
        }
    }

    for (int j = 0; j < contValidos; ++j) {
        for (int k = 0; k < as; ++k) {
            if (novoT[j].id_piloto == p[k].id)
            {
                strcpy(novoT[j].nome,p[k].nome);
                strcpy(novoT[j].marca,p[k].marca);
            }
        }
    }


    Tempos ola123;

    for (int j = 0; j < contValidos; ++j) {
        for (int i = 0; i < contValidos; ++i) {
            if(novoT[i].tempo > novoT[j].tempo)
            {
                ola123 = novoT[i];
                novoT[i] = novoT[j];
                novoT[j] = ola123;
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
    FILE *fileTabela;

    for (int k = 0; k < contValidos; k++) {
        for (int i = 0; i <= as; i++) {
            if (novoT[k].id_piloto == p[i].id)
            {
                if(z == 0)
                {
                    printf("%*d | %*d | %*s | %*s | %*d | %*s | %*s \n",
                           SEPARADOR, z+1,
                           SEPARADOR, novoT[k].id_piloto,
                           SEPARADOR, novoT[k].nome,
                           SEPARADOR, novoT[k].marca,
                           SEPARADOR, novoT[k].tempo,
                           SEPARADOR, "0.0",
                           SEPARADOR, "0.0"

                    );
                }
                else
                {
                    tempAnt = novoT[k].tempo - novoT[k - 1].tempo;
                    tempLed = novoT[k].tempo - novoT[0].tempo;
                    printf("%*d | %*d | %*s | %*s | %*d | %*d | %*d \n",
                           SEPARADOR, z + 1,
                           SEPARADOR, novoT[k].id_piloto,
                           SEPARADOR, novoT[k].nome,
                           SEPARADOR, novoT[k].marca,
                           SEPARADOR, novoT[k].tempo,
                           SEPARADOR, tempAnt,
                           SEPARADOR, tempLed

                    );
                    //printf("%d | Numero -> %d | Nome -> %s | Marca -> %s | Tempo-> %d | Di.Ant -> %d | Di.Ldr -> %d\n",z+1,p[i].id,p[i].nome,p[i].marca,eee[k].tempo,tempAnt,tempLed);
                }
                z++;
            }
        }
    }
    Tempos OLA;
    for (int j = 0; j < contValidos; ++j) {
        for (int i = 0; i < contValidos; ++i) {
            if(novoT[i].id_piloto > novoT[j].id_piloto)
            {
                OLA = novoT[i];
                novoT[i] = novoT[j];
                novoT[j] = OLA;
            }
        }
    }
    Tempos kkkl;
    for (int j = 0; j < pilotos; ++j) {
        for (int i = 0; i < pilotos; ++i) {
            if(eee[i].id_piloto > eee[j].id_piloto)
            {
                kkkl = eee[i];
                eee[i] = eee[j];
                eee[j] = kkkl;
            }
        }
    }

    z=0;
    if(pilotos != contValidos)
    {
        for (int k = 0; k < pilotos; k++) {
            z=0;
            for (int i = 0; i < contValidos; i++) {

                if (novoT[i].id_piloto == eee[k].id_piloto)
                {
                    z++;
                    //printf("%d %d  %d   ",novoT[i].id_piloto,eee[k].id_piloto,z);
                }
                if((i+1)%contValidos == 0 && z == 0)
                {
                    printf("%*s | %*d | %*s | %*s | %*s | %*s | %*s \n",
                           SEPARADOR, "-",
                           SEPARADOR, p[k].id,
                           SEPARADOR, p[k].nome,
                           SEPARADOR, p[k].marca,
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