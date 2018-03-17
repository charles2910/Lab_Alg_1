#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A função abaixo recebe um inteiro x e um vetor
// desordenado v[0..n-1]. Ela devolve um índice m
// em 0..n-1 tal que v[m] == x. Se tal m não existe,
// a função devolve -1.

int
buscaSequencial (int x, int n, int v[], long int* custo) {
    for (int m = 0; m < n; m++)
    {
        *custo = *custo + 1;
        if (v[m] == x)
            return m;
    }
    return (-1);
}

int main ()
{
    int tam = 100000;  //tamanho da input, "n".
    int vetor[tam];
    long int custo = 0;   //variavel que representa o numero de iteraçoes do "for"; Obs.: para n = 100000, foi preciso alterar pra long int.
    for (int m = 0; m < 10; m++)  //realiza as 10 iterações necessárias
    {
        int pos = 0;
        custo = 0;
        srand(rand() % 10000);  //reseta a sequencia aleatoria
        for (int i = 0; i < tam; i++)  //atribui valores aleatorios
            vetor[i] = rand() % tam; //ao vetor de entrada
        buscaSequencial(rand() % (2*tam), tam, vetor, &custo);
        printf ("%ld\n", custo);
    }
}
