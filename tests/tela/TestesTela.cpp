#include "doctest.h"
#include "Tela.h"

TEST_CASE("Janela Aberta - Jogo funcionando") {
  Tela tela;
  CHECK(tela.janelaAberta());
}

TEST_CASE("Exibicoes") {
  Tela tela;
  tela.exibirVitoria();
  tela.exibirInstrucao();
  tela.exibirGameOver();
  tela.exibirMenuInicial();
  tela.exibirVidas();
  tela.exibirPause();
  tela.exibirScore();
  tela.exibirScoreFinal();
}

TEST_CASE("Carregamento de texturas") {
  carregaTexturas();
  CHECK_NOTHROW();
}

TEST_CASE("Carregamento de fonte") {
  carregaFonte();
  CHECK_NOTHROW();
}
