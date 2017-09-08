#ifndef ESCUADRON_H
#define ESCUADRON_H
#include "Soldado.h"
#include "Arquero.h"
#include "CorazasDuras.h"
#include "Asesino.h"
#include <string>
#include <vector>
using namespace std;
class Escuadron{
	private:
		string Enombre;
		vector<Soldado*> soldados;
	public:
		Escuadron(string);
		string getEnombre();
		vector<Soldado*> getSoldiers();

		void setEnombre(string);
		void setSoldiers(vector<Soldado*>);
};

#endif
