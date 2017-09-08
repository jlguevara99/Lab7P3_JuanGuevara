#include "CorazasDuras.h"

#include <string>

using namespace std;

CorazasDuras::CorazasDuras(string nomb, string ciud, int pedad,int pdureza, int planzas){
	nombre = nomb;
	ciudad = ciud;

	edad = pedad;
	dureza = pdureza;
	lanzas = planzas;
}

int CorazasDuras::getDureza(){
	return dureza;
}

int CorazasDuras::getLanzas(){
	return lanzas;
}

void CorazasDuras::setDureza(int pdure){
	dureza = pdure;
}

void CorazasDuras::setLanzas(int planz){
	lanzas = planz;
}
