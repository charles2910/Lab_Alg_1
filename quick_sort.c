#include <stdio.h>
#include <stdlib.h>

void Quicksort(int vetor[], int inicio, int fim){
    int  pivo, aux, i, j, meio;
    i = inicio;  //esquerda
    j = fim;     //direita
    meio = (int) ((i + j) / 2);
    pivo = vetor[meio];
    do
    {
        while (vetor[i] > pivo)
            i = i + 1;
        while (vetor[j] < pivo)
            j = j - 1;

        if(i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }  while(j > i);
    if(inicio < j)
        Quicksort(vetor, inicio, j);
    if(i < fim)
        Quicksort(vetor, i, fim);
}

int main ()
{
    int tam = 10;  //tamanho da input, "n".
    int vetor[tam];
    for (int m = 0; m < 1; m++)  //realiza as 10 iterações necessárias
    {
        srand(time(NULL));  //reseta a sequencia aleatoria
        for (int i = 0; i < tam; i++)  //atribui valores aleatorios
        {
            vetor[i] = rand() % tam; //ao vetor de entrada
            printf("%d ", vetor[i]);
        }
        Quicksort(vetor, 0, tam);
        for (int i=0;i<tam; i++)
            printf("%d ", vetor[i]);
        return 0;
    }
}
