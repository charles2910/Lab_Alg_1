#include <stdio.h>
#include <stdlib.h>

void  bubble_sort_4  (int  vetor[],  int  n)  {
    int  k,  j,  aux;
    for  (k = n - 1; k > 0; k--)  {
        for  (j = 0; j < k; j++)  {
            if  (vetor[j] < vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
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
        bubble_sort_4(vetor,tam);
        for (int i=0;i<tam; i++)
            printf("%d ", vetor[i]);
        return 0;
    }
}
