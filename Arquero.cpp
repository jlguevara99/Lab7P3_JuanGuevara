#include "Arquero.h"

Arquero::Arquero(string pNom, string pCiudad, int pedad, int pflecha, int pprecision){
	nombre = pNom;
	ciudad = pCiudad;
	edad = pedad;
	flechas = pflecha;
	precision = pprecision;
}

int Arquero::getFlechas(){
	return flechas;
}

int Arquero::getPrecision(){
	return precision;
}

void Arquero::setFlechas(int numero){
	flechas = numero;
}

void Arquero::setPrecision(int numero){
	precision = numero;
}
