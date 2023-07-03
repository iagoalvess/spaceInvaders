#ifndef  CONTROLEOBJETOS_H
#define CONTROLEOBJETOS_H

#include "GerenciadorEstados.h"
#include "BlocoInimigos.h"
#include "LinhaInimigos.h"
#include "Inimigo.h"
#include "Player.h"
#include "Tiro.h"
#include <list>
#include <set>

class GameEngine {
private:

	Player* _player;

	BlocoInimigos* _bloco_inimigos;

	std::list<Tiro*> _tiros;

	std::list<ObjetoJogo*> _renderizaveis;

	GerenciadorEstados _estado;

	int _score;

public:

	GameEngine();

	void atualizaJogo();

	std::list<ObjetoJogo*> renderizaveis();

	void moverPlayer(float direcao);

	void playerAtirar();

	void moverObjetos();

	void colisoesTiro();

	void removeTirosPerdidos();

	void inimigoAtirar();

	void ganhar();

	void gameOver();

	void recargas();

	int getVidas();

	int getScore();

	BlocoInimigos* getBlocoInimigos();

	GerenciadorEstados getEstado();

	Player* getPlayer();

	std::list<Tiro*> getTiros();
};

#endif 
