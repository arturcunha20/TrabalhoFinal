#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    char marca[50];
}Piloto;

int main() {
    Piloto p;

    p.id = 1;
    strcpy("Artur Cunha",p.nome);
    strcpy("Subaru",p.nome);

    printf("%d %s %s\n",p.id,p.nome,p.marca);
    return 0;
}