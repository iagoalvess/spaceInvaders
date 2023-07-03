#include "doctest.h"
#include "Inimigo.h"
#include "LinhaInimigos.h"
#include "BlocoInimigos.h"

TEST_CASE("Movimento inimigo") {
  Inimigo inimigo;
  sf::Vector2f pos_inicial = inimigo.getPosicao();
  sf::Vector2f pos_final(18.5f, 19.5f);
  inimigo.mover(pos_final);
  CHECK(inimigo.getPosicao() != pos_inicial);
}

TEST_CASE("Movendo bloco de inimigos") {
  BlocoInimigos bloco;
  sf::Vector2f pos_inicial = bloco.getPosicao();
  bloco.mover();
  CHECK(bloco.getPosicao() != pos_inicial);
}

