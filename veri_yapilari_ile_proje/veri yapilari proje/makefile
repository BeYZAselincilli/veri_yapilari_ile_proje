all:derle bagla calistir
derle:

	g++ -c -I "./include" ./src/main2.cpp -o ./lib/main2.o
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/Radixsortf.cpp -o ./lib/Radixsortf.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o		
	g++ -c -I "./include" ./src/Dugumikili.cpp -o ./lib/Dugumikili.o		
	g++ -c -I "./include" ./src/ikiliagac.cpp -o ./lib/ikiliagac.o	
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o	
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o		
bagla:
	g++  ./lib/main2.o  ./lib/Hucre.o ./lib/Doku.o ./lib/Organ.o ./lib/Sistem.o ./lib/Kuyruk.o ./lib/Organizma.o ./lib/ikiliagac.o ./lib/Dugumikili.o ./lib/Radixsortf.o -o ./bin/program

calistir:
	./bin/program