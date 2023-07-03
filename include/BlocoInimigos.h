#ifndef BLOCOINIMIGOS_H
#define BLOCOINIMIGOS_H

#include "ObjetoJogo.h"
#include "LinhaInimigos.h"
#include "Inimigo.h"
#include <list>
#include <map>

class BlocoInimigos : public ObjetoJogo {
private: 
	std::list<LinhaInimigos*> _bloco;

	bool _movendo_direita;

	int _tempo_recarga_inimigo;

public:
	BlocoInimigos();

	void initFase1();

	void mover() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	std::list<LinhaInimigos*> getBloco();

	void removerLinha(LinhaInimigos* linha);

	bool blocoVazio();

	void atualizaDimensoes();

	void atualizaVelocidade();

	void atualizaTempoRecarga();

	Tiro* atirar();

	int getTempoRecarga();
};

#endif 
