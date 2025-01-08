// Copyright 2025 Eduardo de Brito Ruas

#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <string>
#include <map>

// Função que conta as palavras em uma string
std::map<std::string, int> conta_palavras(const std::string& texto);

// Função que conta as palavras em um arquivo
std::map<std::string, int> conta_palavras_arquivo(const std::string& arquivo);

// Função que imprime a contagem das palavras
void imprime_contagem(const std::map<std::string, int>& contagem);

#endif  // CONTA_PALAVRAS_HPP_
