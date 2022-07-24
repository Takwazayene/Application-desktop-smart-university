#include "universite.h"

universite::universite()
{
    nbre_bloc=0 ;
    nbre_classe=0 ;
    idUniversite=0 ;
}

universite::universite(int nbre_bloc ,int nbre_classe, int idUniversite)
{
   this->nbre_bloc=nbre_bloc;
    this->nbre_classe=nbre_classe ;
    this->idUniversite=idUniversite;
}


int universite::get_nbre_classe() {return nbre_classe  ;}
int universite::get_nbre_bloc(){return  nbre_bloc;}
int universite::get_idUniversite(){return  idUniversite ;}
