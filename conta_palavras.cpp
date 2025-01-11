// Copyright 2025 Eduardo de Brito Ruas

#include "conta_palavras.hpp"  // NOLINT(build/include_subdir)
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::map<std::string, int> ContadorPalavras::contarPalavras(const std::string& nomeArquivo) {
    std::map<std::string, int> contagemPalavras;
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        return contagemPalavras; // Retorna mapa vazio se não conseguir abrir o arquivo
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string palavra;
        while (iss >> palavra) {
            // Remove pontuação e converte para minúsculas
            palavra.erase(std::remove_if(palavra.begin(), palavra.end(), ::ispunct), palavra.end());
            std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

            if (!palavra.empty()) {
                contagemPalavras[palavra]++;
            }
        }
    }

    arquivo.close();
    return contagemPalavras;
}

