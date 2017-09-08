#include "Escuadron.h"

Escuadron::Escuadron(string nEnom){
	Enombre = nEnom;
	
}

string Escuadron::getEnombre(){
	return Enombre;
}

vector<Soldado> Escuadron::getSoldiers(){
	return soldados;
}

void Escuadron::setEnombre(string pNom){
	Enombre = pNom;
}

void Escuadron::setSoldiers(vector<Soldado> psol){
	soldados = psol;
}
