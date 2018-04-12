#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int checa_pg (int vetor[], int tam)
{
    int razao = 0,razaoProx = 0;
    if (tam >= 3)
    {
        razao = vetor[1] / vetor[0];
        razaoProx = checa_pg(vetor + 1, tam - 1);

        if (razao != razaoProx)
            return -1;
        else
            return razao;
    }
    else
    {
        razao = vetor[1] / vetor[0];
        return razao;
    }
}

/*
// Esta função recebe um inteiro x e um vetor
// crescente v[e..d] e devolve um índice m
// em e..d tal que v[m] == x. Se tal m
// não existe, devolve -1.

static int
bb (int x, int e, int d, int v[]) {
   if (e > d) return -1;
   else {
      int m = (e + d)/2;
      if (v[m] == x) return m;
      if (v[m] < x)
         return bb (x, m+1, d, v);
      else
         return bb (x, e, m-1, v);
   }
}
*/
int gera_elem (int pos, int razao, int a0)
{
    int elem = (int)(a0 * pow ((double) razao, (double) (pos - 1)));
    return elem;
}

int aux_conf (int vetor[], int e, int d, int razao)
{
    if ((e == d) || (e == d - 1)) //condiçao de saida com exito
    {
        if (vetor[e] == gera_elem(e + 1, razao, vetor[0]))
            return d;
        else return e;
    }

    /*if (vetor[d] == gera_elem(d + 1, razao, vetor[0]))
        return -1;*/
    else
    {
        int m = (e + d)/2;
        if (vetor[m] == gera_elem(m + 1, razao, vetor[0]))
            return aux_conf(vetor, m, d, razao);
        if (vetor[m] != gera_elem(m + 1, razao, vetor[0]))
            return aux_conf(vetor, e, m, razao);

    }

}

int conf_pg (int vetor[], int tam)
{
    int razao1 = 0, razao2 = 0, razao3 = 0, razao =0, aux = 0;
    razao1 = vetor[1] / vetor[0];
    razao2 = vetor[tam/2] / vetor[(tam/2) - 1];
    razao3 = vetor[tam - 1] / vetor[tam - 2];
    if (razao1 == razao2)
        razao = razao1;
    else if (razao2 == razao3)
            razao = razao2;
    else if (razao3 == razao1)
            razao = razao3;
    printf("%d\n",razao );
    aux = aux_conf(vetor, 0, tam - 1, razao);
    printf("%d\n",aux );
    return gera_elem(aux + 1, razao, vetor[0]);
}


int main ()
{
    int tam = 10;
    int teste[tam];
    teste[0] = 1;
    for (int i = 1; i < tam; i++)
        teste[i] = teste[i - 1] * 2;
    teste[8] = 2;
    int flag = checa_pg(teste, tam);
    for (int i = 0; i < tam; i++)
        printf("%d ", teste[i] );
    printf("\n%d  %d\n",flag, conf_pg(teste, tam) );
    return 0;
}
