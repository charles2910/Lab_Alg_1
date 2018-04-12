#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checa_pg (int vetor[], int tam)
{
    int razao = 0,razaoProx = 0;
    if (tam >= 3)
    {
        razao = vetor[1] / vetor[0];
        razaoProx = checa_pg(vetor + 1, tam - 1);

        if (razao != razaoProx)
            return -1;
        else
            return razao;
    }
    else
    {
        razao = vetor[1] / vetor[0];
        return razao;
    }
}

/*
int conf_pg (int vetor[], int tam)
{

}
*/

int main ()
{
    int tam = 10;
    int teste[tam];
    teste[0] = 1;
    for (int i = 1; i < tam; i++)
        teste[i] = teste[i - 1] * 3;
    teste[6] = 8;
    int flag = checa_pg(teste, tam);
    for (int i = 0; i < tam; i++)
        printf("%d ", teste[i] );
    printf("\n%d\n",flag );
    return 0;
}
