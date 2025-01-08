#define CATCH_CONFIG_MAIN  // Isso diz ao Catch2 para fornecer uma função main()
#include "catch.hpp"

TEST_CASE("Conta palavras de um arquivo") {
    auto resultado = conta_palavras_arquivo("texto.txt");

    REQUIRE(resultado["é"] == 1);
    REQUIRE(resultado["este"] == 1);
    REQUIRE(resultado["o"] == 1);
    REQUIRE(resultado["que"] == 1);
    REQUIRE(resultado["será"] == 1);
    REQUIRE(resultado["texto"] == 2);
    REQUIRE(resultado["utilizado"] == 1);
}