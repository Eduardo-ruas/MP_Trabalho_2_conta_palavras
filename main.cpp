#include "conta_palavras.hpp"
#include <iostream>

int main() {
    try {
        // Caminho do arquivo
        std::string arquivo = "texto.txt";

        // Conta palavras no arquivo
        auto contagem = conta_palavras_arquivo(arquivo);

        // Imprime o resultado
        imprime_contagem(contagem);
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}