#ifndef INIMIGO_H
#define INIMIGO_H

#include "ObjetoJogo.h"
#include "Tiro.h"
#include "VariaveisGlobais.h"

class Inimigo : public ObjetoJogo {
private:

	ObjetoJogo* _linha_pertencente;
	int _nivel_inimigo;

public:	

	Inimigo();

	Inimigo(sf::Vector2f posicao_inicial, ObjetoJogo* linha, int nivel);

	virtual ~Inimigo();

	ObjetoJogo* getLinhaPertencente();

	int getNivel();

	void mover(sf::Vector2f incremento);

	Tiro* atirar();
};



#endif
