#ifndef PLAYER_H
#define PLAYER_H

#include "ObjetoJogo.h"
#include "Tiro.h"
#include "VariaveisGlobais.h"

class Player : public ObjetoJogo{
private:
	int _tempo_recarga_tiro;
	int _vidas; 

public:

	Player();
	virtual ~Player();

	void setPosition(const sf::Vector2f pos);

	void setPosition(const float x, const float y);

	int getVidas();

	int getTempoRecarga();

	void setTempoRecarga(int x);

	void resetTempoRecarga();

	void atualizaTempoRecarga();

	void perdeUmaVida();

	void mover(float direcao);

	Tiro* atirar();

};

#endif