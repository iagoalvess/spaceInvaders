#include "BlocoInimigos.h"
#include <iostream>


BlocoInimigos::BlocoInimigos() {

	this->_subtipo = 'I';
	this->_velocidade = _inimigo_velocidades[0]; 
	this-> _tempo_recarga_inimigo = _recarga_inimigo;

	this->_objeto.setSize(_bloco_inimigo_dimensoes);
	this->_objeto.setPosition(_bloco_inimigo_posicao_inicial);

	this->initFase1();

	this->_movendo_direita = true;
}



void BlocoInimigos::initFase1() {
	float coordenada_y = _bloco_inimigo_posicao_inicial.y;
	int nivel_inimigo = bloco_num_linhas - 1;
	for (int i = 0; i < bloco_num_linhas; i++) {
		LinhaInimigos* linha = new LinhaInimigos(sf::Vector2f(_bloco_inimigo_posicao_inicial.x, coordenada_y), nivel_inimigo);
		this->_bloco.push_back(linha);
		coordenada_y += _bloco_distancia_linhas.y + _inimigo_dimensoes.y;
		nivel_inimigo--;
	}
}



void BlocoInimigos::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//target.draw(_objeto, states);
	for (LinhaInimigos* linha : this->_bloco) {
		target.draw(*linha, states);
	}
	
}



void BlocoInimigos::mover() {

	sf::Vector2f incremento = this->_velocidade;

	if (!this->_movendo_direita) {
		incremento.x = -incremento.x;
	}

	// Checa se toca o lado esquerdo tela, desce e muda de dire��o
	if (this->getBounds().left < _limite_esquerdo && !this->_movendo_direita) {
		incremento = sf::Vector2f(incremento.y, -30.0 * incremento.x);
		this->_movendo_direita = true;
	}

	// Checa se toca o lado direito tela, desce e muda de dire��o
	else if (this->getBounds().left + this->getBounds().width >= _limite_direito && this->_movendo_direita) {
		incremento = sf::Vector2f(incremento.y, 30.0* incremento.x);
		this->_movendo_direita = false;
	}

	for (LinhaInimigos* linha : this->_bloco) {
		linha->mover(incremento);
	}

	this->_objeto.move(incremento);

}



std::list<LinhaInimigos*> BlocoInimigos::getBloco() {
	return this->_bloco;
}



void BlocoInimigos::removerLinha(LinhaInimigos* linha) {
	this->_bloco.remove(linha);
	//delete linha;
}



bool BlocoInimigos::blocoVazio() {
	return this->_bloco.empty();
}



void BlocoInimigos::atualizaDimensoes() {

	if (this->blocoVazio()) {
		return;
	}

	float limite_esq = _janela_largura;
	float limite_dir = 0;
	float limite_inferior;

	sf::Vector2f posicao_atualizada = this->getPosicao();

	for (LinhaInimigos* linha : this->_bloco) {

		linha->atualizaDimensoes();


		if (linha->getPosicao().x < limite_esq) {  
			limite_esq = linha->getPosicao().x;
			posicao_atualizada.x = limite_esq;
		}
		if (linha->getPosicao().x + linha->getBounds().width > limite_dir) {
			limite_dir = linha->getPosicao().x + linha->getBounds().width;
		}
	}

	limite_inferior = this->_bloco.back()->getPosicao().y - this->getPosicao().y + _linha_inimigo_dimensoes.y;

	sf::Vector2f dimensao_final(limite_dir - limite_esq, limite_inferior);
	
	this->setDimensoes(dimensao_final);

	this->setPosicao(posicao_atualizada);

}



void BlocoInimigos::atualizaVelocidade() {
	
	if (this->blocoVazio()) {
		return;
	}

	this->_velocidade = _inimigo_velocidades[this->_bloco.back()->getNivel()];
}



Tiro* BlocoInimigos::atirar() {
	return this->_bloco.back()->atirar();
}



void BlocoInimigos::atualizaTempoRecarga() {
	this->_tempo_recarga_inimigo -= 1;
	if (this->_tempo_recarga_inimigo < 0) {
		this->_tempo_recarga_inimigo = _recargas_inimigo[this->_bloco.back()->getNivel()];
	}
}



int BlocoInimigos::getTempoRecarga() {
	return this->_tempo_recarga_inimigo;
}