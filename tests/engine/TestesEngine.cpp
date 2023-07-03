#include "doctest.h"
#include "GameEngine.h"

TEST_CASE("Movimento do player") {
  GameEngine engine;
  sf::Vector2f pos_inicial;
  pos_inicial = engine.getPlayer()->getPosicao();
  engine.moverPlayer(5);
  CHECK(pos_inicial != engine.getPlayer()->getPosicao());
}

TEST_CASE("GameOver - Vidas zeradas") {
  GameEngine engine;
  engine.getPlayer()->perdeUmaVida();
  engine.getPlayer()->perdeUmaVida();
  engine.getPlayer()->perdeUmaVida();
  engine.gameOver();
  CHECK_EQ(engine.getEstado().getEstadoAtual(), game_over);
}

TEST_CASE("Inimigos atirando") {
  GameEngine engine;
  engine.inimigoAtirar();
  CHECK(engine.getTiros().size() != 0);
}

TEST_CASE("Player atirando") {
  GameEngine engine;
  engine.getPlayer()->setTempoRecarga(-1);
  engine.playerAtirar();
  CHECK(engine.getTiros().size() != 0);
}
