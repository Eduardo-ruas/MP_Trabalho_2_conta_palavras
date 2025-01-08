#include "conta_palavras.hpp"
#include <sstream>
#include <map>
#include <algorithm>
#include <fstream>

std::map<std::string, int> conta_palavras(const std::string& texto) {
    std::map<std::string, int> contagem;
    std::istringstream stream(texto);
    std::string palavra;

    while (stream >> palavra) {
        // Incrementa o contador da palavra
        contagem[palavra]++;
    }

    return contagem;
}

std::map<std::string, int> conta_palavras_arquivo(const std::string& arquivo) {
    std::ifstream entrada(arquivo);
    std::string texto((std::istreambuf_iterator<char>(entrada)),
                       std::istreambuf_iterator<char>());
    return conta_palavras(texto);
}
