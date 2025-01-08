#ifndef CONTA_PALAVRAS_HPP
#define CONTA_PALAVRAS_HPP

#include <string>
#include <map>

class ContaPalavras {
 public:
  ContaPalavras(const std::string& nomeArquivo);
  void lerArquivo();
  int obterContagemTotal() const;
  std::map<std::string, int> obterContagemPalavras() const;

 private:
  std::string nomeArquivo;
  std::map<std::string, int> contagemPalavras;
};

#endif