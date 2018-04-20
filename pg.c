#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int checa_pg (int vetor[], int tam) //se nao eh PG, retorna -1.
{                                   //se for, retorna a razao
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


int gera_elem (int pos, int razao, int a0) //gera quaisquer elementos
{                                          //de uma PG
    int elem = (int)(a0 * pow ((double) razao, (double) (pos - 1)));
    return elem;                           //retorna o valor do elem.
}

int aux_conf (int vetor[], int e, int d, int razao)
{
    if ((e == d) || (e == d - 1)) //condiçao de saida com exito
    {
        if (vetor[e] == gera_elem(e + 1, razao, vetor[0]))
            return d;
        else
            return e;
    }
    else    //descobre se o erro da PG esta à esq ou dir do centro
    {
        int m = (e + d)/2;
        if (vetor[m] == gera_elem(m + 1, razao, vetor[0]))
            return aux_conf(vetor, m, d, razao);  //erro à direita
        if (vetor[m] != gera_elem(m + 1, razao, vetor[0]))
            return aux_conf(vetor, e, m, razao);  //erro à esquerda
    }

}

int conf_pg (int vetor[], int tam)
{
    int razao1 = 0, razao2 = 0, razao3 = 0, razao =0, aux = 0;
    razao1 = vetor[1] / vetor[0];
    razao2 = vetor[tam/2] / vetor[(tam/2) - 1];
    razao3 = vetor[tam - 1] / vetor[tam - 2];
    if (razao1 == razao2)  //checa a razao da PG
        razao = razao1;
    else if (razao2 == razao3)  //checa a razao da PG
            razao = razao2;
    else if (razao3 == razao1)  //checa a razao da PG
            razao = razao3;
    //printf("\nRazao: %d\n",razao );  //printa a razao da PG (opcional)
    aux = aux_conf(vetor, 0, tam - 1, razao);  //inicia a recursao
    //printf("\n Posição: %d\n",aux );  //printa a pos com elem errado (opcional)
    return gera_elem(aux + 1, razao, vetor[0]); //retorna o elemento correto para a posição cujo elemento esta errado
}


int main ()
{
    int tam = 30;
    int teste[tam];
    teste[0] = 3;
    for (int i = 1; i < tam; i++)
        teste[i] = teste[i - 1] * 2;
    teste[0] = 2;
    int flag = checa_pg(teste, tam);
    for (int i = 0; i < tam; i++)
        printf("%d ", teste[i] );
    printf("\n%d  %d\n",flag, conf_pg(teste, tam) );
    return 0;
}
