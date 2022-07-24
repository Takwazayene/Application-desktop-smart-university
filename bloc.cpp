#include "bloc.h"

bloc::bloc()
{
  nomBloc="" ;
  etage=0 ;
  idEtudiant=0 ;
}


bloc::bloc(QString nomBloc ,int etage ,int idEtudiant )
{
  this->nomBloc=nomBloc;
  this->etage=etage ;
  this->idEtudiant=idEtudiant ;
}

QString bloc::get_nomBloc() {return nomBloc ;}
int bloc::get_idEtudiant(){return idEtudiant ;}
int bloc::get_etage(){return idEtudiant ;}
