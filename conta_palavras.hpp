#ifndef CONTA_PALAVRAS_HPP
#define CONTA_PALAVRAS_HPP

#include <string>
#include <map>

// Função para contar palavras em uma string
std::map<std::string, int> conta_palavras(const std::string& texto);

// Função para contar palavras a partir de um arquivo
std::map<std::string, int> conta_palavras_arquivo(const std::string& arquivo);

// Função para imprimir a contagem
void imprime_contagem(const std::map<std::string, int>& contagem);

#endif
