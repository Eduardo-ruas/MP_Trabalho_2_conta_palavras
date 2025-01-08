all: testa_conta_palavras.cpp   main.cpp conta_palavras.hpp main.o
	g++ -std=c++11 -Wall main.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras
	#use comentario se necessario

compile: testa_conta_palavras.cpp   main.cpp conta_palavras.hpp main.o
	g++ -std=c++11 -Wall main.o testa_conta_palavras.cpp -o testa_conta_palavras

main.o : main.cpp conta_palavras.hpp
	g++ -std=c++11 -Wall -c main.cpp
	
testa_conta_palavras: 	testa_conta_palavras.cpp   main.cpp conta_palavras.hpp main.o
	g++ -std=c++11 -Wall main.o testa_conta_palavras.cpp -o testa_conta_palavras
	
test: testa_conta_palavras	
	./testa_conta_palavras
	
cpplint: testa_conta_palavras.cpp   main.cpp conta_palavras.hpp
	cpplint   --exclude=catch.hpp  *.*
	
gcov: testa_conta_palavras.cpp   main.cpp conta_palavras.hpp 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c conta_palavras.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras
	gcov *.cpp	
	 
debug: testa_conta_palavras.cpp   main.cpp conta_palavras.hpp 
	g++ -std=c++11 -Wall -g -c main.cpp
	g++ -std=c++11 -Wall  -g main.o testa_conta_palavras.cpp -o testa_conta_palavras
	gdb testa_conta_palavras
	
	
cppcheck: testa_conta_palavras.cpp   main.cpp conta_palavras.hpp
	cppcheck  --enable=warning .

valgrind: testa_conta_palavras
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_conta_palavras


clean:
	rm -rf *.o *.exe *.gc* testa_conta_palavras
	
	
