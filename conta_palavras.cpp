// Copyright 2025 Eduardo de Brito Ruas

#include "conta_palavras.hpp"  // NOLINT(build/include_subdir)
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Função para transformar uma string em letras minúsculas
std::string para_minusculas(const std::string& palavra) {
    std::string resultado = palavra;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return resultado;
}

// Função que conta as palavras em um texto
std::map<std::string, int> conta_palavras(const std::string& texto) {
    std::map<std::string, int> contagem;
    std::istringstream stream(texto);
    std::string palavra;

    while (stream >> palavra) {
        // Remove pontuações no início e fim da palavra
        palavra.erase(0, palavra.find_first_not_of(" \t\n\r\f\v.,!?\"'"));
        palavra.erase(palavra.find_last_not_of(" \t\n\r\f\v.,!?\"'") + 1);

        // Converte para minúsculas e incrementa a contagem
        palavra = para_minusculas(palavra);
        if (!palavra.empty()) {
            contagem[palavra]++;
        }
    }

    return contagem;
}

// Função que conta palavras a partir de um arquivo
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

// Função que imprime a contagem em ordem alfabética
void imprime_contagem(const std::map<std::string, int>& contagem) {
    for (const auto& [palavra, frequencia] : contagem) {
        std::cout << palavra << ": " << frequencia << std::endl;
    }
}

