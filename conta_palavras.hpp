// Copyright 2025 Eduardo de Brito Ruas

#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <map>
#include <string>

/**
 * @brief Classe responsável por contar a frequência de palavras em um arquivo de texto.
 *
 * Esta classe fornece um método para ler um arquivo, contar a frequência de palavras
 * diferentes e retornar um mapa com as palavras em ordem alfabética e suas respectivas
 * ocorrências.
 */
class ContadorPalavras {
 public:
  /**
   * @brief Conta a frequência de palavras em um arquivo texto.
   *
   * Este método lê o arquivo linha por linha, remove pontuações, converte
   * as palavras para letras minúsculas e calcula a frequência de cada
   * palavra. As palavras são organizadas em ordem alfabética no mapa de
   * retorno.
   *
   * @param nomeArquivo O caminho ou nome do arquivo a ser lido.
   * @return Um mapa onde a chave é a palavra e o valor é a quantidade de
   *         ocorrências. Retorna um mapa vazio se o arquivo não puder ser aberto.
   */
  std::map<std::string, int> contarPalavras(const std::string& nomeArquivo);
};

#endif  // CONTA_PALAVRAS_HPP_
