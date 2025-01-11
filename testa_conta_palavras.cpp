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

TEST_CASE("Contagem de palavras em um arquivo inexistente", "[ContadorPalavras]") {
    ContadorPalavras contador;
    std::map<std::string, int> resultado = contador.contarPalavras("arquivo_inexistente.txt");
    REQUIRE(resultado.empty());
}

TEST_CASE("Contagem de palavras em um arquivo com uma linha", "[ContadorPalavras]") {
    // Cria um arquivo temporário com uma linha
    std::ofstream arquivo("arquivo_uma_linha.txt");
    arquivo << "Este é um teste";
    arquivo.close();

    ContadorPalavras contador;
    std::map<std::string, int> resultado = contador.contarPalavras("arquivo_uma_linha.txt");

    REQUIRE(resultado.size() == 4);
    REQUIRE(resultado["este"] == 1);
    REQUIRE(resultado["é"] == 1);
    REQUIRE(resultado["um"] == 1);
    REQUIRE(resultado["teste"] == 1);

    // Remove o arquivo temporário
    std::remove("arquivo_uma_linha.txt");
}

TEST_CASE("Contagem de palavras em um arquivo com múltiplas linhas", "[ContadorPalavras]") {
    // Cria um arquivo temporário com múltiplas linhas
    std::ofstream arquivo("arquivo_multiplas_linhas.txt");
    arquivo << "Este é um teste\n";
    arquivo << "Este é outro teste\n";
    arquivo.close();

    ContadorPalavras contador;
    std::map<std::string, int> resultado = contador.contarPalavras("arquivo_multiplas_linhas.txt");

    REQUIRE(resultado.size() == 5);
    REQUIRE(resultado["este"] == 2);
    REQUIRE(resultado["é"] == 2);
    REQUIRE(resultado["um"] == 1);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["outro"] == 1);

    // Remove o arquivo temporário
    std::remove("arquivo_multiplas_linhas.txt");
}

TEST_CASE("Contagem de palavras com pontuação e maiúsculas/minúsculas", "[ContadorPalavras]") {
    // Cria um arquivo temporário com pontuação e maiúsculas/minúsculas
    std::ofstream arquivo("arquivo_pontuacao.txt");
    arquivo << "Este é um Teste, com pontuação!\n";
    arquivo << "Este é outro TESTE.\n";
    arquivo.close();

    ContadorPalavras contador;
    std::map<std::string, int> resultado = contador.contarPalavras("arquivo_pontuacao.txt");

    REQUIRE(resultado.size() == 7);
    REQUIRE(resultado["este"] == 2);
    REQUIRE(resultado["é"] == 2);
    REQUIRE(resultado["um"] == 1);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["com"] == 1);
    REQUIRE(resultado["pontuação"] == 1);
    REQUIRE(resultado["outro"] == 1);

    // Remove o arquivo temporário
    std::remove("arquivo_pontuacao.txt");
}

TEST_CASE("Contagem do exemplo", "[ContadorPalavras]") {
    // Cria um arquivo temporário com o texto do exemplo
    std::ofstream arquivo("arquivo_exemplo.txt");
    arquivo << "Este texto é o texto que será utilizado\n";
    arquivo.close();

    ContadorPalavras contador;
    std::map<std::string, int> resultado = contador.contarPalavras("arquivo_exemplo.txt");

    REQUIRE(resultado.size() == 7);
    REQUIRE(resultado["este"] == 1);
    REQUIRE(resultado["texto"] == 2);
    REQUIRE(resultado["é"] == 1);
    REQUIRE(resultado["o"] == 1);
    REQUIRE(resultado["que"] == 1);
    REQUIRE(resultado["será"] == 1);
    REQUIRE(resultado["utilizado"] == 1);

    // Remove o arquivo temporário
    std::remove("arquivo_exemplo.txt");
}

TEST_CASE("Verificar ordenação alfabética da saída", "[ContadorPalavras]") {
    // Cria um arquivo temporário com palavras fora de ordem
    std::ofstream arquivo("arquivo_desordenado.txt");
    arquivo << "zebra abacate dado casa bola\n";
    arquivo << "elefante abacate\n";
    arquivo.close();

    ContadorPalavras contador;
    std::map<std::string, int> resultado = contador.contarPalavras("arquivo_desordenado.txt");

    // Verifica se o mapa está vazio (não deveria estar)
    REQUIRE_FALSE(resultado.empty());

    // Verifica se a saída está em ordem alfabética
    std::string palavraAnterior = "";
    for (const auto& par : resultado) {
        REQUIRE(palavraAnterior <= par.first);
        palavraAnterior = par.first;
    }

    // Remove o arquivo temporário
    std::remove("arquivo_desordenado.txt");
}