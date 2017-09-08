#ifndef ASESINO_H
#define ASESINO_H
#include "Soldado.h"
class Asesino : public Soldado{
	private:
		int asesinatos;
		int sigilo;
	public:
		Asesino(string,string,int,int,int);
		
		int getAsesinatos();
		int getSigilo();

		void setAsesinatos(int);
		void setSigilo(int);
};

#endif
