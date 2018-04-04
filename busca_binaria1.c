#include <stdio.h>
#include <stdlib.h>


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

int
buscaBinaria (int* contador, int x, int n, int v[]) {
    int esq, meio, dir;
    esq = 0; dir = n-1;
    while (esq <= dir) {
        (*contador)++;
        meio = (esq + dir)/2;
        if (v[meio] == x) return meio;
        if (v[meio] < x) esq = meio + 1;
        else dir = meio - 1;
    }
    (*contador)++;
    return -1;
}


int main ()
{
    int tam = 100;  //tamanho do vetor
    int vetor[tam];
    int contador = 0;   //variavel que representa o numero de iteraçoes do "for"
    for (int m = 0; m < 10; m++)  //realiza as 10 iterações
    {
        int retorno = 0;
        contador = 0;
        srand(rand() % 10000);
        for (int i = 0; i < tam; i++)  //atribui valores aleatorios
            vetor[i] = rand() % tam; //ao vetor de entrada
        insercao(tam, vetor);
        retorno = buscaBinaria(&contador, rand() % (2*tam), tam, vetor);
        printf ("%d\n", contador);
    }
}
