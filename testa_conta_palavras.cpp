#define CATCH_CONFIG_MAIN  // Isso diz ao Catch2 para fornecer uma função main()
#include "catch.hpp"
#include "conta_palavras.hpp"
#include <fstream>

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
