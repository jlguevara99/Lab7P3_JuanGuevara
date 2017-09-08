#include <string>
#include <iostream>
#include "Soldado.h"
#include "Arquero.h"
#include "CorazasDuras.h"
#include "Asesino.h"
#include "Escuadron.h"
#include <vector>
using namespace std;
int menu();


int main(){
	vector<Escuadron*> escuadrones;
	bool salir = true;
	
	cout<<">>>>LAB 7 -- JUAN GUEVARA.<<<<"<<endl<<endl;
	do {
		int opcion = menu();
		if(opcion == 1){
			cout<<"Ingresar Escuadron"<<endl<<endl;
			string nombre;
			cout<<"Ingrese el Nombre: "<<endl;
			cin>>nombre;
			Escuadron* temporal = new Escuadron(nombre);
			escuadrones.push_back(temporal);

		cout<<"Escuadron creado"<<endl<<endl;
		}else if(opcion == 2){

			cout<<"	LISTA DE ESCUADRONES"<<endl;

			for(int i = 0; i < escuadrones.size(); i++) {
				cout<<i<<". "<<escuadrones[i]->getEnombre()<<endl<<endl;
			}

			cout<<"Ingrese el numero del escuadron a cual le añadirá soldados"<<endl;
			int escuadron;
			cin>>escuadron;
			while(escuadron<0 || escuadron>=escuadrones.size()){
				cout<<"Ha ingresado una posicion invalida"<<endl;
				cout<<"Ingrese de nuevo"<<endl;
				cin>>escuadron;
			}
			bool seguir = false;
			do {
				cout<<"Ingrese el nombre del soldado: "<<endl;
				string nombreS;
				cin>>nombreS;
				cout<<"Ingrese la ciudad del soldado: "<<endl;
				string ciudads;
				cin>>ciudads;
				cout<<"Ingrese la edad del soldado: "<<endl;
				int edads;
				cin>>edads;
				cout<<"Que es el soldado?"<<endl<<"1. Arquero"<<endl<<"2. Coraza Dura"<<endl<<"3. Asesino Oculto"<<endl;
				int tipo;
				cin>>tipo;
				while(tipo<1 || tipo > 3){
					cout<<"Opcion incorrecta! Ingrese de nuevo"<<endl;
					cout<<"Que es el soldado?"<<endl<<"1. Arquero"<<endl<<"2. Coraza Dura"<<endl<<"3. Asesino Oculto"<<endl;
					cin>>tipo;
				}
				vector<Soldado*> temporal;
				temporal = escuadrones[escuadron]->getSoldiers();
				
				if(tipo==1){
					cout<<"Ingrese el numero de flechas: "<<endl;
					int flechas;
					cin>>flechas;
					cout<<"Ingrese la precision: "<<endl;
					int preci;
					cin>>preci;
					Soldado* tempo = new Arquero(nombreS,ciudads,edads,flechas,preci);
					temporal.push_back(tempo);
					delete tempo;
				}else if(tipo==2){
					cout<<"Ingrese la dureza de la armadura: "<<endl;
					int dureza;
					cin>>dureza;
					while(dureza<0 || dureza>10){
						cout<<"Debe ser entre 0 y 10"<<endl;
						cin>>dureza;
					}
					cout<<"Ingrese la cantidad de lanzas: "<<endl;
					int lanzas;
					cin>>lanzas;
					Soldado* tempo = new CorazasDuras(nombreS,ciudads,edads,dureza,lanzas);
					temporal.push_back(tempo);
					delete tempo;
				}else if(tipo==3){
					cout<<"Ingrese la cantidad de asesinatos: "<<endl;
					int cantidad;
					cin>>cantidad;
					cout<<"Ingrese el sigilo: "<<endl;
					int sigilo;
					cin>>sigilo;
					while(sigilo<0 || sigilo >10){
						cout<<"Debe ser entre 0 y 10"<<endl;
						cin>>sigilo;
					}
					Soldado* tempo = new Asesino(nombreS,ciudads,edads,cantidad,sigilo);
					temporal.push_back(tempo);
					delete tempo;
				}

				escuadrones[escuadron]->setSoldiers(temporal);

				cout<<"Desea agregar otro?[1/2]"<<endl;
				int op;
				cin>>op;
				if(op==2){
					seguir = false;
				}

			} while (seguir);
			
		}else if(opcion == 3){
			for(int i = 0; i < escuadrones.size(); i++) {
				cout<<i<<". "<<escuadrones[i]->getEnombre()<<endl;
			}

			int vanguardia1, retaguardia1;
			int vanguardia2, retaguardia2;

			cout<<"Ingrese el Escuadron frontal del primer equipo: "<<endl;
			cin>>vanguardia1;
			while(vanguardia1<0 || vanguardia1 >= escuadrones.size()){
				cout<<"Valor incorrecto, ingrese de nuevo"<<endl;
				cin>>vanguardia1;
			}
			cout<<"Ingrese la retaguardia del primer equipo: "<<endl;
			cin>>vanguardia2;
			while(vanguardia2<0 || vanguardia2>=escuadrones.size()){
				cout<<"Valor incorrecto, ingrese de nuevo"<<endl;
			}
		}else if(opcion == 4){
			salir = false;
		}else{
		
		}
	} while (salir);

	return 0;
}





int menu(){
	cout<<"1. Ingresar Escuadrones"<<endl;
	cout<<"2. Ingresar Soldados a los escuadrones"<<endl;
	cout<<"3. Simular batalla"<<endl;
	cout<<"4. Salir"<<endl;
	int opcion;
	cin>>opcion;
	return opcion;
}
