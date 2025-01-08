#include "conta_palavras.hpp"
#include <sstream>
#include <map>
#include <algorithm>

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
