#ifndef LINHAINIMIGOS_H
#define LINHAINIMIGOS_H

#include "VariaveisGlobais.h"
#include "ObjetoJogo.h"
#include "Inimigo.h"
#include <list>
#include <random>
#include <iterator>
#include <iostream>
#include <algorithm>

class LinhaInimigos : public ObjetoJogo {
private:

	std::list<Inimigo*> _linha;
	
	int _nivel;

	int _tempo_recarga;

public:		

	LinhaInimigos(sf::Vector2f posicao_inicial, int nivel);

	int getNivel();

	void mover(sf::Vector2f incremento);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	std::list<Inimigo*> getLinha();

	bool linhaVazia();

	void removerInimigo(Inimigo* inimigo);

	void atualizaDimensoes();

	Tiro* atirar();
};



#endif 
