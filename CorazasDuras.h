#ifndef CORAZASDURAS_H
#define CORAZASDURAS_H
#include "Soldado.h"
class CorazasDuras : public Soldado{
	private:
		int dureza;
		int lanzas;
	public:
		CorazasDuras(string,string,int,int,int);
		
		int getDureza();
		int getLanzas();

		void setDureza(int);
		void setLanzas(int);

		double ataque();
		double defensa();

};

#endif
