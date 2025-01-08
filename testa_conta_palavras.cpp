// Copyright 2025 Eduardo de Brito Ruas

// Cabeçalhos C++
#include <fstream>
#include <string>
#define CATCH_CONFIG_MAIN

// Outros cabeçalhos
#include "catch.hpp"  // NOLINT(build/include_subdir)
#include "conta_palavras.hpp"  // NOLINT(build/include_subdir)

TEST_CASE("Testa a contagem de palavras no texto", "[conta_palavras]") {
    std::string texto = "Este texto é o texto que será utilizado";

    auto contagem = conta_palavras(texto);

    REQUIRE(contagem["este"] == 1);
    REQUIRE(contagem["texto"] == 2);
    REQUIRE(contagem["é"] == 1);
    REQUIRE(contagem["o"] == 1);
    REQUIRE(contagem["que"] == 1);
    REQUIRE(contagem["será"] == 1);
    REQUIRE(contagem["utilizado"] == 1);
}

TEST_CASE("Testa contagem sem diferenciar maiúsculas e minúsculas", "[conta_palavras]") {
    std::string texto = "Este eStE estE";
    auto contagem = conta_palavras(texto);
    REQUIRE(contagem["este"] == 3); 
}

TEST_CASE("Testa falha em contagem incorreta", "[conta_palavras]") {
    std::string texto = "Este texto é o texto que será utilizado";

    auto contagem = conta_palavras(texto);

    REQUIRE(contagem["este"] == 1);
    REQUIRE(contagem["texto"] == 2);
    REQUIRE(contagem["é"] == 1);
    REQUIRE(contagem["o"] == 1);
    REQUIRE(contagem["que"] == 0);
    REQUIRE(contagem["será"] == 1);
    REQUIRE(contagem["utilizado"] == 1);
}

TEST_CASE("Testa frase com números", "[conta_palavras]") {
    std::string texto = "Ele fez 4 gols";

    auto contagem = conta_palavras(texto);

    REQUIRE(contagem["ele"] == 1);
    REQUIRE(contagem["fez"] == 1);
    REQUIRE(contagem["4"] == 1);
    REQUIRE(contagem["gols"] == 1);
}

TEST_CASE("Testa se a saída está em ordem alfabética", "[conta_palavras]") {
  std::string texto = "Este texto é o texto que será utilizado zzz aaa";
  auto contagem = conta_palavras(texto);

  auto it = contagem.begin();
  auto end = contagem.end();
  --end;  // Para evitar acessar um iterador inválido no loop

  for (; it != end; ++it) {
    auto next = std::next(it);
    REQUIRE(it->first <= next->first); 
  }
}
