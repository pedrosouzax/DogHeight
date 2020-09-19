#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "include/Cachorro.h"
#include "perceptron.h"

using namespace std;

int main()
{
    int i,j,m, t_tam,tam_ptr, saida_desejada,result;
    float t_rab,t_nariz,t_lingua,t_orelha,rabo_ptr,nariz_ptr,lingua_ptr,orelha_ptr,erro;
    float entrada[4],ws[4];
    srand(time(0));
    int tam_train = 1000;
    int epochs = 1000;
    Cachorro dog[tam_train];

    //Populando o dataset de cachorros
    for (i=0; i <tam_train; i++)
    {
        if(i<50) //Cachorro pequeno
        {
            t_tam = -1;
            t_rab = ((float)(2+rand()% 13 - 2));
            t_nariz = ((float)(2+rand()% 5 - 2));
            t_lingua = ((float)(3+rand()% 4 - 3));
            srand(time(NULL));
            t_orelha = ((float)(2+rand()% 5 - 2));

            dog[i].set_atributos(t_tam,t_rab,t_nariz,t_lingua,t_orelha);
        }
        else //Cachorro  grande
        {
            t_tam = 1;
            srand(time(NULL));

            t_rab = ((float)(15+rand()% 25 - 15));
            t_nariz = ((float)(7+rand()% 8 - 7));
            t_lingua = ((float)(7+rand()% 8 - 7));
            srand(time(0));
            t_orelha = ((float)(7+rand()% 8 - 7));

            dog[i].set_atributos(t_tam,t_rab,t_nariz,t_lingua,t_orelha);
        }

    }
/* Verifando os dados dos objetos criados
        for(j=47; j<55; j++)
        {
            dog[j].get_atributos(&tam_ptr,&rabo_ptr,&nariz_ptr,&lingua_ptr,&orelha_ptr);
            cout<<"Dog "<<j<< ":"<<endl;
            cout<<"rabo: "<<rabo_ptr<<endl;
            cout<<"orelha: "<<rabo_ptr<<endl;
            cout<<"lingua: "<<lingua_ptr<<endl;
            cout<<"nariz: "<<nariz_ptr<<endl;
            cout<<" "<<endl;
        }
*/

    //Inicializar os pesos
    for(int i=0; i<4; i++)
    {
        ws[i] = 0;
    }

    for(m=0;m<epochs;m++)
    {
        std::cout<<"Train "<< m << "/"<<epochs<<std::endl;
        for(int n=0;n<tam_train;n++)
        {
            dog[n].get_atributos(&tam_ptr,&rabo_ptr,&nariz_ptr,&lingua_ptr,&orelha_ptr);
            saida_desejada = tam_ptr;
            entrada[0] = rabo_ptr;
            entrada[1] = nariz_ptr;
            entrada[2] = lingua_ptr;
            entrada[3] = orelha_ptr;
            erro = train(0.0100, entrada, saida_desejada, ws);
            if(n%100==0){
                cout<<"*";
            }

        }

        cout<<" Erro: "<< erro<<endl;

    }

    dog[45].get_atributos(&tam_ptr,&rabo_ptr,&nariz_ptr,&lingua_ptr,&orelha_ptr);

    entrada[0] = rabo_ptr;
    entrada[1] = nariz_ptr;
    entrada[2] = lingua_ptr;
    entrada[3] = orelha_ptr;


   /* for(int y =0; y<4; y++)
    {
        cout<<"Entrada "<< y <<": " <<entrada[y] <<endl;
        cout<<"W "<< y <<": " <<ws[y] <<endl;
    }*/

    result = percept(entrada, ws);

    if(result==-1)
    {
        cout<<"\nCachorro Pequeno"<<endl;
    }
    else
        cout<<"\nCachorro Grande"<<endl;


    return 0;
}
