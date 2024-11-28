Tüm: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/genDugum.o -c ./src/genDugum.cpp
	g++ -I ./include/ -o ./lib/genListe.o -c ./src/genListe.cpp
	g++ -I ./include/ -o ./lib/kromozomDugum.o -c ./src/kromozomDugum.cpp
	g++ -I ./include/ -o ./lib/kromozomListe.o -c ./src/kromozomListe.cpp
	g++ -I ./include/ -o ./bin/main ./lib/genDugum.o ./lib/genListe.o ./lib/kromozomDugum.o ./lib/kromozomListe.o ./src/main.cpp

calistirma:
	./bin/main