// Copyright 2025 Eduardo de Brito Ruas

// Cabeçalhos C++
#include <fstream>  // NOLINT(build/include_subdir)
#include <string>  // NOLINT(build/include_subdir)

// Outros cabeçalhos
#include "catch.hpp"  // NOLINT(build/include_subdir)
#include "conta_palavras.hpp"  // NOLINT(build/include_subdir)

TEST_CASE("Conta palavras em uma string simples") {
    std::string texto = "Este texto é o texto que será utilizado";
    auto resultado = conta_palavras(texto);

    REQUIRE(resultado["Este"] == 1);
    REQUIRE(resultado["texto"] == 2);
    REQUIRE(resultado["é"] == 1);
    REQUIRE(resultado["o"] == 1);
    REQUIRE(resultado["que"] == 1);
    REQUIRE(resultado["será"] == 1);
    REQUIRE(resultado["utilizado"] == 1);
}
