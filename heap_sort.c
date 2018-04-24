#include <stdio.h>
#include <stdlib.h>


void swap (int vetor[], int i, int j)
{
    int aux;
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void heapify(int arr[], int n, int i)
{
    int smaller = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smaller])
        smaller = l;
    if (r < n && arr[r] < arr[smaller])
        smaller = r;
    if (smaller != i)
    {
        swap(arr, i, smaller);
        heapify(arr, n, smaller);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr, 0, i);
        heapify(arr, i, 0);
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
        heapSort (vetor, tam);
        for (int i=0;i<tam; i++)
            printf("%d ", vetor[i]);
        return 0;
    }
}
