// Copyright 2025 Eduardo de Brito Ruas

#include "conta_palavras.hpp"  // NOLINT(build/include_subdir)
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

/**
 * @brief Conta a frequência de cada palavra em um arquivo de texto.
 *
 * Este método lê um arquivo linha por linha, remove pontuações, converte
 * as palavras para letras minúsculas e calcula a frequência de cada
 * palavra.
 *
 * @param nomeArquivo Caminho para o arquivo que será processado.
 * @return Um mapa onde as chaves são as palavras encontradas no arquivo e os
 *         valores são a frequência de cada palavra. Retorna um mapa vazio
 *         se o arquivo não puder ser aberto.
 */
std::map<std::string, int> ContadorPalavras::contarPalavras(
    const std::string& nomeArquivo) {
  std::map<std::string, int> contagemPalavras;
  std::ifstream arquivo(nomeArquivo);

  if (!arquivo.is_open()) {
    return contagemPalavras;  // Retorna mapa vazio se não abrir o arquivo
  }

  std::string linha;
  while (std::getline(arquivo, linha)) {
    std::istringstream iss(linha);
    std::string palavra;
    while (iss >> palavra) {
      // Remove pontuação e converte para minúsculas
      palavra.erase(
          std::remove_if(palavra.begin(), palavra.end(), ::ispunct),
          palavra.end());
      std::transform(palavra.begin(), palavra.end(), palavra.begin(),
                    ::tolower);

      if (!palavra.empty()) {
        contagemPalavras[palavra]++;
      }
    }
  }

  arquivo.close();
  return contagemPalavras;
}