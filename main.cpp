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
			if(escuadrones.size()>= 4){

			

			
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
			cin>>retaguardia1;
			while(retaguardia1<0 || retaguardia1>=escuadrones.size()){
				cout<<"Valor incorrecto, ingrese de nuevo"<<endl;
				cin>>retaguardia1;
			}
			cout<<"Ingrese la vanguardia del segundo equipo: "<<endl;
			cin>>vanguardia2;
			while(vanguardia2<0 || vanguardia2>=escuadrones.size()){
				cout<<"Valor incorrecto, ingrese de nuevo"<<endl;
				cin>>vanguardia2;
			}
			cout<<"Ingrese la retaguardia del segundo equipo: "<<endl;
			cin>>retaguardia2;
			while(retaguardia2<0 || retaguardia2>escuadrones.size()){
				cout<<"Valor incorrecto, ingrese de nuevo"<<endl;
				cin>>retaguardia2;
			}
			//simulacion
			int ganador=0;
			//vector<Soldado*> sol = escuadrones[vanguardia1]->getSoldiers();
			for(int i = 0; i < 2; i++) {
				double attack=0;
				double defense=0;
				if(i == 0){				
					for(int i = 0; i < escuadrones[vanguardia1]->getSoldiers().size(); i++) {
						cout<<"1."<<endl;
						attack += escuadrones[vanguardia1]->getSoldiers()[i]->ataque();
					}
					for(int i = 0; i < escuadrones[retaguardia2]->getSoldiers().size(); i++) {
						cout<<"2."<<endl;
						defense += escuadrones[retaguardia2]->getSoldiers()[i]->defensa();
					}
					if(attack> (defense*10)){
						ganador = 1;
						break;
					}
				}else{
					for(int i = 0; i < escuadrones[vanguardia2]->getSoldiers().size(); i++) {
						attack += escuadrones[vanguardia2]->getSoldiers()[i]->ataque();
					}
					for(int i = 0; i < escuadrones[retaguardia1]->getSoldiers().size(); i++) {
						defense += escuadrones[retaguardia1]->getSoldiers()[i]->defensa();
					}
					if(attack>(defense*10)){
						ganador = 2;
					}
				}
			
			}
			if(ganador == 0){
				cout<<"HA SIDO UN EMPATE!!"<<endl;
			}else if(ganador == 1){
				cout<<"EL EQUIPO 1 HA GANADO"<<endl;
				cout<<escuadrones[vanguardia1]->getEnombre()<<" y "<<escuadrones[retaguardia1]->getEnombre()<<endl;
			}else{
				cout<<"EL EQUIPO 2 HA GANADO"<<endl;
				cout<<escuadrones[vanguardia2]->getEnombre()<<" y "<<escuadrones[retaguardia2]->getEnombre()<<endl;
			}


		}else{
			cout<<"No tiene sufucientes escuadrones"<<endl;
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
