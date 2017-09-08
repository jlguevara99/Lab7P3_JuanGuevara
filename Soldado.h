#ifndef SOLDADO_H
#define SOLDADO_H

#include <string>
using namespace std;

class Soldado{

	protected:
		string nombre;
		string ciudad;
		int edad;

	public:
		Soldado();
		Soldado(string,string,int);
		
		string getNombre();
		string getCiudad();
		int getEdad();

		void setNombre(string);
		void setCiudad(string);
		void setEdad(int);

		//funciones polimorficas
		virtual double ataque();
		virtual double defensa();
};


#endif
