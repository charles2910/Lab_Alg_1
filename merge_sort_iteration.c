#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Esta função rearranja o vetor v[0..n-1]
// em ordem crescente.

void
mergesort_i (int n, int v[])
{
   int p, r;
   int b = 1;
   while (b < n) {
      p = 0;
      while (p + b < n) {
         r = p + 2*b;
         if (r > n) r = n;
         intercala (p, p+b, r, v);
         p = p + 2*b;
      }
      b = 2*b;
   }
}


int main ()
{
    int tam = 100000;  //tamanho da input ("n")
    int vetor[tam];
    clock_t start, end;   //variavel que representa o numero de iteraçoes do "for"; Obs.: para n = 100000, foi preciso alterar pra long int.
    double tempo;
    for (int m = 0; m < 10; m++)  //realiza as 10 iterações necessárias
    {
        start = 0; end = 0.0; tempo = 0.0;
        srand(rand() % 10000);  //reseta a sequencia aleatoria
        for (int i = 0; i < tam; i++)  //atribui valores aleatorios
            vetor[i] = rand() % tam; //ao vetor de entrada
        start = clock();
        mergesort_i(tam, vetor);
        end = clock();
        tempo = ((double) end - start) / CLOCKS_PER_SEC;
        printf ("%f\n", tempo);
    }
}
