#include <stdio.h>
#include <stdlib.h>


int
buscaSequencial (long int* contador,int x, int n, int v[]) {
    for (int m = 0; m < n; m++)
    {
        *contador = *contador + 1;
        if (v[m] == x)
            return m;
    }
    return (-1);
}

int main ()
{
    int tam = 100000;  //tamanho do vetor
    int vetor[tam];
    long int contador = 0;   //variavel que representa o numero de iteraçoes do FOR
    for (int m = 0; m < 10; m++)  //realiza as 10
    {
        int retorno = 0;
        contador = 0;
        srand(rand() % 10000);  //reseta a sequencia aleatoria
        for (int i = 0; i < tam; i++)  //atribui valores aleatorios
            vetor[i] = rand() % tam; //ao vetor de entrada
        retorno = buscaSequencial(&contador, rand() % (2*tam), tam, vetor);
        printf ("%ld\n", contador);
    }
}
