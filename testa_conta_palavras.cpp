// Copyright 2025 Eduardo de Brito Ruas

// Cabeçalhos C++
#include <fstream>
#include <string>
#define CATCH_CONFIG_MAIN

// Outros cabeçalhos
#include "catch.hpp"  // NOLINT(build/include_subdir)
#include "conta_palavras.hpp"  // NOLINT(build/include_subdir)

TEST_CASE("Testa contagem de palavras", "[conta_palavras]") {
    std::string texto = "palavra1 palavra2 palavra1";
    auto contagem = conta_palavras(texto);

    REQUIRE(contagem["palavra1"] == 2);
    REQUIRE(contagem["palavra2"] == 1);
}

