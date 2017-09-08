#include <string>
#include <iostream>
#include "Soldado.h"
#include "Arquero.h"
#include "CorazasDuras.h"
#include "Asesino.h"
#include "Escuadron.h"
using namespace std;

int main(){
	Soldado* m = new Arquero("s","d",1,2,2);
	Soldado* x = new CorazasDuras("s","d",1,2,2);
	Soldado* c = new Asesino("d","d",2,2,2);
	Escuadron* s = new Escuadron("d");
	cout<<"si"<<endl;
	delete m;
	delete x;
	delete c;
	delete s;
	return 0;
}
