#include <iostream>
#include <string>

using namespace std;


class Carte {
private:
char* titlu;
char* autor;
int numar_pagini;
double pret;
bool electronica;
int* numar_cuvinte;


public:
Carte(){}
Carte(char* _titlu, char* _autor, int _numar_pagini, double _pret, bool _electronica, int* _numar_cuvinte) : titlu(_titlu), autor(_autor), numar_pagini(_numar_pagini), pret(_pret), electronica(_electronica), numar_cuvinte(_numar_cuvinte)
{

this->titlu = new char[strlen(_titlu) + 1];
strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);

this->autor = new char[strlen(_autor) + 1];
strcpy_s(this->autor, strlen(_autor) + 1, _autor);

this->numar_cuvinte = new int[_numar_pagini];
for (int index = 0; index < _numar_pagini; index++)
{
this->numar_cuvinte[index] = _numar_cuvinte[index];
}
}

Carte(const Carte& carte) {

this->titlu=new char[strlen(carte.titlu)+1];
this->autor=new char[strlen(carte.autor)+1];
this->numar_pagini = carte.numar_pagini;
this->pret = carte.pret;
this->electronica = carte.electronica;

this->numar_cuvinte = new int[carte.numar_pagini];
for (int index = 0; index < carte.numar_pagini; index++)
{
this->numar_cuvinte[index] = carte.numar_cuvinte[index];
}

}


//setters

void set_titlu(char* _titlu){
  this->titlu =_titlu;
}
void set_autor(char* _autor){
  this->autor=_autor;
}
void set_pret(double _pret){
  this->pret=_pret;
}
void  set_electronica(bool _electronica){
  this->electronica=_electronica;
}
void set_numar_cuvinte(int* _numar_cuvinte, int _numar_pagini){
  this->numar_pagini = _numar_pagini;
  this->numar_cuvinte = new int[_numar_pagini];
  for (int index = 0; index < _numar_pagini; index++)
  {
  this->numar_cuvinte[index] =_numar_cuvinte[index];
  }
}
//getters

char* get_titlu(){ return this->titlu; }
char* get_autor(){ return this->autor; }
double get_pret(){ return this->pret; }
bool get_electronica(){ return this->electronica; }
int* get_numar_cuvinte(){ return this->numar_cuvinte; }
int get_numar_pagini(){ return this->numar_pagini; }

//destructori
~Carte(){
  delete[] this->titlu;
  delete[]  this->autor;
  delete[] this->numar_cuvinte;

}
};



int main()
{
Carte c1;

  c1.titlu = new char[20];
  strcpy_s(c1.titlu, 20, "Carte");

  c1.autor = new char[20];
  strcpy_s(c1.autor, 20, "Autor");

  c1.numar_pagini= 256;
  c1.pret = 49.50;
  c1.electronica = false;
  int numar_cuvinte[6]={120, 130, 124, 135, 126, 123};
  c1.set_numar_cuvinte(6, numar_pagini);


}
