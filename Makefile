all: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	g++ -std=c++17 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras || true
	#use comentario se necessario

compile: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	g++ -std=c++17 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras

conta_palavras.o : conta_palavras.cpp conta_palavras.hpp
	g++ -std=c++17 -Wall -c conta_palavras.cpp
	
testa_conta_palavras: 	testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	g++ -std=c++17 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	
test: testa_conta_palavras	
	./testa_conta_palavras || true
	
cpplint: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp
	cpplint   --exclude=catch.hpp  *.*
	
gcov: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp 
	g++ -std=c++17 -Wall -fprofile-arcs -ftest-coverage -c conta_palavras.cpp
	g++ -std=c++17 -Wall -fprofile-arcs -ftest-coverage conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras || true
	gcov *.cpp	
	 
debug: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp 
	g++ -std=c++17 -Wall -g -c conta_palavras.cpp
	g++ -std=c++17 -Wall  -g conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	gdb testa_conta_palavras
	
	
cppcheck: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp
	cppcheck  --enable=warning . --suppress=syntaxError:catch.hpp

valgrind: testa_conta_palavras
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_conta_palavras 


clean:
	rm -rf *.o *.exe *.gc* testa_conta_palavras
	
	
