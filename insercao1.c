#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
insercao (long int* contador, int n, int vetor[])
{
    int i, j, x;
    for (j = 1; j < n; ++j) {
        x = vetor[j];
        for (i = j-1; i >= 0 && vetor[i] > x; --i)
            {vetor[i+1] = vetor[i]; (*contador)++;}
        vetor[i+1] = x;
    }
}
int main ()
{
    int tam = 100000;  //tamanho da input ("n")
    int vetor[tam];
    long int custo;
    clock_t start, end;   //variavel que representa o numero de iteraçoes do "for"; Obs.: para n = 100000, foi preciso alterar pra long int.
    double tempo;
    for (int m = 0; m < 10; m++)  //realiza as 10 iterações necessárias
    {
        start = 0; end = 0.0; tempo = 0.0; custo = 0;
        srand(rand() % 10000);  //reseta a sequencia aleatoria
        for (int i = 0; i < tam; i++)  //atribui valores aleatorios
            vetor[i] = rand() % tam; //ao vetor de entrada
        start = clock();
        insercao(&custo, tam, vetor);
        end = clock();
        tempo = ((double) end - start) / CLOCKS_PER_SEC;
        printf ("%f\n", tempo);
    }
}
