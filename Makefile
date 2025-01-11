# Makefile para compilar, testar e depurar o programa de contagem de palavras.

# Documentação com Doxygen
doc:
	doxygen Doxyfile

# Regra principal: compila e executa o programa
all: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	# Compila o programa principal
	g++ -std=c++17 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	# Executa o programa
	./testa_conta_palavras || true
	# Use comentários para descrever qualquer comportamento necessário

# Compila o programa sem executar
compile: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	g++ -std=c++17 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras

# Compila apenas o objeto conta_palavras.o
conta_palavras.o: conta_palavras.cpp conta_palavras.hpp
	g++ -std=c++17 -Wall -c conta_palavras.cpp

# Compila o programa principal
testa_conta_palavras: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	g++ -std=c++17 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras

# Executa o programa principal para testar
test: testa_conta_palavras	
	./testa_conta_palavras || true

# Verifica o estilo do código com cpplint
cpplint: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp
	cpplint --exclude=catch.hpp *.*

# Gera cobertura de código com gcov
gcov: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp 
	g++ -std=c++17 -Wall -fprofile-arcs -ftest-coverage -c conta_palavras.cpp
	g++ -std=c++17 -Wall -fprofile-arcs -ftest-coverage conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras || true
	gcov *.cpp	

# Compila o programa em modo de depuração e executa com gdb
debug: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp 
	g++ -std=c++17 -Wall -g -c conta_palavras.cpp
	g++ -std=c++17 -Wall -g conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	gdb testa_conta_palavras

# Analisa o código em busca de possíveis problemas com cppcheck
cppcheck: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp
	cppcheck --enable=warning . --suppress=syntaxError:catch.hpp

# Testa o programa com Valgrind para verificar problemas de memória
valgrind: testa_conta_palavras
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_conta_palavras || true

# Remove arquivos gerados durante a compilação
clean:
	rm -rf *.o *.exe *.gc* testa_conta_palavras
