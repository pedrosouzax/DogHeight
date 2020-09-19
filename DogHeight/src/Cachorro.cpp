#include "Cachorro.h"
#include <iostream>

Cachorro::Cachorro()
{

    //cout<<"One Dog has been created!" << endl;
}

Cachorro::~Cachorro()
{
    //dtor
}

void Cachorro::set_atributos(int tamanho, float rabo, float nariz, float lingua, float orelha)
{
    this->tamanho = tamanho;
    this->rabo = rabo;
    this->nariz = nariz;
    this->lingua = lingua;
    this->orelha = orelha;
}

void Cachorro::get_atributos(int *tam_ptr, float *rabo_ptr, float *nariz_ptr, float *lingua_ptr, float *orelha_ptr)
{
    *tam_ptr = this->tamanho;
    *rabo_ptr = this->rabo;
    *nariz_ptr = this->nariz;
    *lingua_ptr = this->lingua;
    *orelha_ptr = this->orelha;

}
