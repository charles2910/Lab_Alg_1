#include <stdio.h>
#include <stdlib.h>

void  selection_sort(int  num[],  int  tam)  {
    int  i,  j,  max,  aux;
    for  (i  =  0;  i  <  (tam - 1);  i++)
    {
          max  =  i;
          for  (j  =  (i+1);  j  <  tam;  j++)  {
              if(num[j]  >  num[max])
                  max  =  j;
          }
          if  (num[i]  !=  num[max])  {
              aux  =  num[i];
              num[i]  =  num[max];
              num[max]  =  aux;
          }
    }
}


int main ()
{
    int tam = 10;  //tamanho da input, "n".
    int vetor[tam];
    long int custo = 0;   //variavel que representa o numero de iteraçoes do "for"; Obs.: para n = 100000, foi preciso alterar pra long int.
    for (int m = 0; m < 1; m++)  //realiza as 10 iterações necessárias
    {
        int pos = 0;
        custo = 0;
        srand(time(NULL));  //reseta a sequencia aleatoria
        for (int i = 0; i < tam; i++)  //atribui valores aleatorios
        {
            vetor[i] = rand() % tam; //ao vetor de entrada
            printf("%d ", vetor[i]);
        }
        selection_sort(vetor,tam);
        for (int i=0;i<tam; i++)
            printf("%d ", vetor[i]);
        return 0;
    }
}
