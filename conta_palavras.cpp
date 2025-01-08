// Copyright 2025 Seu Nome
#include "conta_palavras.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
#include <string>

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

    if (!entrada) {
        throw std::runtime_error("Erro ao abrir o arquivo: " + arquivo);
    }

    // Lê todo o conteúdo do arquivo para uma string
    std::string texto((std::istreambuf_iterator<char>(entrada)),
                      std::istreambuf_iterator<char>());

    return conta_palavras(texto);
}

void imprime_contagem(const std::map<std::string, int>& contagem) {
    for (const auto& [palavra, frequencia] : contagem) {
        std::cout << palavra << ": " << frequencia << std::endl;
    }
}
