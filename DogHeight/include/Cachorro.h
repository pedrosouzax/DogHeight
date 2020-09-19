#ifndef CACHORRO_H
#define CACHORRO_H
#include <iostream>

class Cachorro
{
    public:
        Cachorro();
        virtual ~Cachorro();
        void set_atributos(int tamanho, float rabo, float nariz, float lingua, float orelha);
        void get_atributos(int *, float *, float *, float *, float *);


    protected:

    private:
        int tamanho;
        float rabo, nariz, lingua, orelha;
};

#endif // CACHORRO_H
