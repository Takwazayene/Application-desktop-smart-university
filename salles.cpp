#include "salles.h"

salles::salles()
{
  numSalle=0 ;
  nomBloc="" ;
}

salles::salles(int numSalle ,QString nomBloc)
{
  this->numSalle=numSalle ;
 this-> nomBloc=nomBloc ;
}


int salles::get_numSalle() {return numSalle ; }
QString salles::get_nomBloc() {return nomBloc ;}
