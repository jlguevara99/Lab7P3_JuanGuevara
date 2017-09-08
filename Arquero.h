#ifndef ARQUERO_H
#define ARQUERO_H
#include "Soldado.h"

class Arquero : public Soldado{
	private:
		int flechas;
		int precision;
	public:
		Arquero(string,string,int,int,int);

		int getFlechas();
		int getPrecision();

		void setFlechas(int);
		void setPrecision(int);
		
		double ataque();
		double defensa();
	
};



#endif
