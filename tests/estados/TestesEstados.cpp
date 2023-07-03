#include "doctest.h"
#include "GerenciadorEstados.h"

TEST_CASE("Estado inicial") {
  GerenciadorEstados estado;
  CHECK_EQ(estado.getEstadoAtual(), menu_inicial);
}

TEST_CASE("Iniciando jogo") {
  GerenciadorEstados estado;
  estado.iniciaJogo();
  CHECK_EQ(estado.getEstadoAtual(), jogando);
}

TEST_CASE("Pausar") {
  GerenciadorEstados estado;
  estado.setEstado(jogando);
  estado.pausar();
  CHECK_EQ(estado.getEstadoAtual(), pausado);
}

TEST_CASE("Despausar") {
  GerenciadorEstados estado;
  estado.setEstado(pausado);
  estado.pausar();
  CHECK_EQ(estado.getEstadoAtual(), jogando);
}

TEST_CASE("Abrir instrucao") {
  GerenciadorEstados estado;
  estado.exibirInstrucao();
  CHECK_EQ(estado.getEstadoAtual(), instrucao);
}

TEST_CASE("Fechar instrucao") {
  GerenciadorEstados estado;
  estado.setEstado(instrucao);
  estado.exibirInstrucao();
  CHECK_EQ(estado.getEstadoAtual(), menu_inicial);
}

