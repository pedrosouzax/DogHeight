#include <iostream>
#include<math.h>
#include<cmath>

float func_ativac(float soma)
{
    if(soma >= 1)
    {
        return 1;
    }
    else if(soma <= -1)
    {
        return -1;
    }
    else
    {
        return tanh(soma);
    }
}

float percept(float entrada[4],float w[4])
{
    float camada_1[4], soma_result;
    float saida;
    int i;

    for(i=0;i<4;i++)
    {
        camada_1[i] = entrada[i]*w[i];
        soma_result = camada_1[i]+soma_result;
    }

    saida = func_ativac(soma_result);

    return saida;
}

float train(float tx_aprendizado, float entrada[4],int saida_desejada, float w[4])
{
    int i,j;
    float saida,erro;
    float w_last[4];

    saida = percept(entrada,w);

    erro =((float)(saida_desejada))-saida;

    for(i=0;i<4;i++)
    {
        w_last[i] = w[i];
        w[i] = w_last[i]+(tx_aprendizado*erro*entrada[i]);
    }

    return erro;

}
