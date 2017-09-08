#include "Asesino.h"

Asesino::Asesino(string pNom, string pCiu, int pedad, int pasesi, int psigilo){
	nombre = pNom;
	ciudad = pCiu;
	edad = pedad;
	asesinatos = pasesi;
	sigilo = psigilo;
}

int Asesino::getAsesinatos(){
	return asesinatos;
}

int Asesino::getSigilo(){
	return sigilo;
}

void Asesino::setAsesinatos(int pAsesi){
	asesinatos = pAsesi;
}

void Asesino::setSigilo(int psigilo){
	sigilo = psigilo;
}

double Asesino::ataque(){
	return asesinatos;
}

double Asesino::defensa(){
	return sigilo*10;
}
