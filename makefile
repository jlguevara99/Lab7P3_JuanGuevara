main:	main.o Soldado.o Arquero.o CorazasDuras.o Asesino.o Escuadron.o
	g++ main.o Soldado.o Arquero.o CorazasDuras.o Asesino.o Escuadron.o -o mn

main.o:	main.cpp Soldado.h Arquero.h CorazasDuras.h Asesino.h Escuadron.h
	g++ -c main.cpp

Soldado.o: Soldado.h Soldado.cpp
	g++ -c Soldado.cpp

Arquero.o:	Arquero.h Arquero.cpp
	g++ -c Arquero.cpp

CorazasDuras.o:	CorazasDuras.h CorazasDuras.cpp
	g++ -c CorazasDuras.cpp

Asesino.o:	Asesino.h Asesino.cpp
	g++ -c Asesino.cpp

Escuadron.o:	Escuadron.h Escuadron.cpp
	g++ -c Escuadron.cpp
