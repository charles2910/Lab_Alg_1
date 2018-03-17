#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Esta função rearranja o vetor v[0..n-1]
// em ordem crescente.

void
insercao (int n, int v[])
{
    int i, j, x;
    for (j = 1; j < n; ++j) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; --i)
            v[i+1] = v[i];
        v[i+1] = x;
    }
}


// A função abaixo recebe um inteiro x e um vetor
// crescente v[0..n-1]. Ela devolve um índice m
// tal que v[m] == x ou devolve -1 se tal m não
// existe.

int
buscaBinaria (int x, int n, int v[], int *custo) {
    int e, m, d;                              // 1
    e = 0; d = n-1;                           // 2
    while (e <= d) {                          // 3
        (*custo)++;
        m = (e + d)/2;                        // 4
        if (v[m] == x) return m;              // 5
        if (v[m] < x) e = m + 1;              // 6
        else d = m - 1;                       // 7
    }                                         // 8
    (*custo)++;
    return -1;                                // 9
}


int main ()
{
    int tam = 100000;  //tamanho da input ("n")
    int vetor[tam];
    int custo = 0;   //variavel que representa o numero de iteraçoes do "for"; Obs.: para n = 100000, foi preciso alterar pra long int.
    for (int m = 0; m < 10; m++)  //realiza as 10 iterações necessárias
    {
        int pos = 0;
        custo = 0;
        srand(rand() % 10000);  //reseta a sequencia aleatoria
        for (int i = 0; i < tam; i++)  //atribui valores aleatorios
            vetor[i] = rand() % tam; //ao vetor de entrada
        insercao(tam, vetor);
        buscaBinaria(rand() % (2*tam), tam, vetor, &custo);
        printf ("%d\n", custo);
    }
}
