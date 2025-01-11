// Copyright 2025 Eduardo de Brito Ruas

// Cabeçalhos C++
#include <fstream>
#include <string>
#define CATCH_CONFIG_MAIN

// Outros cabeçalhos
#include "catch.hpp"  // NOLINT(build/include_subdir)
#include "conta_palavras.hpp"  // NOLINT(build/include_subdir)

TEST_CASE("Contagem de palavras em um arquivo vazio", "[ContadorPalavras]") {
    ContadorPalavras contador;
    std::map<std::string, int> resultado = contador.contarPalavras("arquivo_vazio.txt");
    REQUIRE(resultado.empty());
}
