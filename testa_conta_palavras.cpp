// Copyright 2025 Eduardo de Brito Ruas

// Cabeçalhos C++
#include <fstream>
#include <map>
#include <string>

// Outros cabeçalhos
#include "catch.hpp"           // NOLINT(build/include_subdir)
#include "conta_palavras.hpp"  // NOLINT(build/include_subdir)
#define CATCH_CONFIG_MAIN

// Função auxiliar para criar arquivos de teste
void criaArquivo(const std::string& nomeArquivo,
                const std::string& conteudo) {
  std::ofstream arquivo(nomeArquivo);
  arquivo << conteudo;
  arquivo.close();
}

/**
 * @brief Configuração inicial para todos os testes.
 *        Cria os arquivos necessários para os testes.
 */
TEST_CASE("Configuração inicial", "[ContadorPalavras]") {
  criaArquivo("arquivo_vazio.txt", "");
  criaArquivo("arquivo_uma_linha.txt", "Este é um teste");
  criaArquivo("arquivo_multiplas_linhas.txt",
              "Este é um teste\nEste é outro teste\n");
  criaArquivo("arquivo_pontuacao.txt",
              "Este é um Teste, com pontuação!\nEste é outro TESTE.\n");
  criaArquivo("arquivo_exemplo.txt",
              "Este texto é o texto que será utilizado\n");
  criaArquivo("arquivo_desordenado.txt",
              "zebra abacate dado casa bola\nelefante abacate\n");
}

/**
 * @brief Testa a contagem de palavras em um arquivo vazio.
 */
TEST_CASE("Contagem de palavras em um arquivo vazio", "[ContadorPalavras]") {
  ContadorPalavras contador;
  std::map<std::string, int> resultado =
      contador.contarPalavras("arquivo_vazio.txt");
  REQUIRE(resultado.empty());
}

/**
 * @brief Testa a contagem de palavras em um arquivo inexistente.
 */
TEST_CASE("Contagem de palavras em um arquivo inexistente",
          "[ContadorPalavras]") {
  ContadorPalavras contador;
  std::map<std::string, int> resultado =
      contador.contarPalavras("arquivo_inexistente.txt");
  REQUIRE(resultado.empty());
}

/**
 * @brief Testa a contagem de palavras em um arquivo com uma linha.
 */
TEST_CASE("Contagem de palavras em um arquivo com uma linha",
          "[ContadorPalavras]") {
  ContadorPalavras contador;
  std::map<std::string, int> resultado =
      contador.contarPalavras("arquivo_uma_linha.txt");

  REQUIRE(resultado.size() == 4);
  REQUIRE(resultado["este"] == 1);
  REQUIRE(resultado["é"] == 1);
  REQUIRE(resultado["um"] == 1);
  REQUIRE(resultado["teste"] == 1);
}

/**
 * @brief Testa a contagem de palavras em um arquivo com múltiplas linhas.
 */
TEST_CASE("Contagem de palavras em um arquivo com múltiplas linhas",
          "[ContadorPalavras]") {
  ContadorPalavras contador;
  std::map<std::string, int> resultado =
      contador.contarPalavras("arquivo_multiplas_linhas.txt");

  REQUIRE(resultado.size() == 5);
  REQUIRE(resultado["este"] == 2);
  REQUIRE(resultado["é"] == 2);
  REQUIRE(resultado["um"] == 1);
  REQUIRE(resultado["teste"] == 2);
  REQUIRE(resultado["outro"] == 1);
}

/**
 * @brief Testa a contagem de palavras com pontuação e
 *        maiúsculas/minúsculas.
 */
TEST_CASE(
    "Contagem de palavras com pontuação e maiúsculas/minúsculas",
    "[ContadorPalavras]") {
  ContadorPalavras contador;
  std::map<std::string, int> resultado =
      contador.contarPalavras("arquivo_pontuacao.txt");

  REQUIRE(resultado.size() == 7);
  REQUIRE(resultado["este"] == 2);
  REQUIRE(resultado["é"] == 2);
  REQUIRE(resultado["um"] == 1);
  REQUIRE(resultado["teste"] == 2);
  REQUIRE(resultado["com"] == 1);
  REQUIRE(resultado["pontuacao"] == 1);
  REQUIRE(resultado["outro"] == 1);
}

/**
 * @brief Testa a contagem de palavras em um exemplo específico.
 */
TEST_CASE("Contagem do exemplo", "[ContadorPalavras]") {
  ContadorPalavras contador;
  std::map<std::string, int> resultado =
      contador.contarPalavras("arquivo_exemplo.txt");

  REQUIRE(resultado.size() == 7);
  REQUIRE(resultado["este"] == 1);
  REQUIRE(resultado["texto"] == 2);
  REQUIRE(resultado["é"] == 1);
  REQUIRE(resultado["o"] == 1);
  REQUIRE(resultado["que"] == 1);
  REQUIRE(resultado["será"] == 1);
  REQUIRE(resultado["utilizado"] == 1);
}

/**
 * @brief Testa se a saída está em ordem alfabética.
 */
TEST_CASE("Verificar ordenação alfabética da saída", "[ContadorPalavras]") {
  ContadorPalavras contador;
  std::map<std::string, int> resultado =
      contador.contarPalavras("arquivo_desordenado.txt");

  REQUIRE_FALSE(resultado.empty());

  std::string palavraAnterior = "";
  for (const auto& par : resultado) {
    REQUIRE(palavraAnterior <= par.first);
    palavraAnterior = par.first;
  }
}