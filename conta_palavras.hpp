// Copyright 2025 Eduardo de Brito Ruas

#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <map>
#include <string>

class ContadorPalavras {
 public:
  /**
   * @brief Lê um arquivo texto, conta as palavras diferentes e lista
   * suas ocorrências em ordem alfabética.
   *
   * @param nomeArquivo O nome do arquivo a ser lido.
   * @return Um mapa onde a chave é a palavra e o valor é a quantidade de
   * ocorrências. Retorna um mapa vazio se o arquivo não puder ser aberto.
   */
  std::map<std::string, int> contarPalavras(const std::string& nomeArquivo);
};

#endif  // CONTA_PALAVRAS_HPP_