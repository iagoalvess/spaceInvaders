#include "LinhaInimigos.h"
#include <iostream>


LinhaInimigos::LinhaInimigos(sf::Vector2f posicao_inicial, int nivel) {
	this->_subtipo = 'I';
	
	this->_velocidade = _inimigo_velocidades[nivel];

	this->_nivel = nivel;
	this->_tempo_recarga = _recargas_inimigo[nivel];

	this->_objeto.setSize(_linha_inimigo_dimensoes);
	this->_objeto.setPosition(posicao_inicial);
	
	float coordenada_x = posicao_inicial.x;
	for (int i = 0; i < num_inimigos_linha; i++)
	{
		Inimigo* inimigo = new Inimigo(sf::Vector2f(coordenada_x, posicao_inicial.y), dynamic_cast<ObjetoJogo*>(this), nivel);
		_linha.push_back(inimigo);
		coordenada_x += _linha_distancia_inimigos.x + _inimigo_dimensoes.x;
	}
}



int LinhaInimigos::getNivel() {
	return this->_nivel;
}



void LinhaInimigos::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for(Inimigo* ini : this->_linha) {
		target.draw(*ini, states);
	}
	//target.draw(_objeto, states);
}



void LinhaInimigos::mover(sf::Vector2f incremento) {
	
	for (Inimigo* ini : this->_linha) {
		ini->mover(incremento);
	}

	this->_objeto.move(incremento);
}



std::list<Inimigo*> LinhaInimigos::getLinha() {
	return this->_linha;
}



void LinhaInimigos::removerInimigo(Inimigo* inimigo) {
	this->_linha.remove(inimigo);
	//delete inimigo;
}



bool LinhaInimigos::linhaVazia() {
	return this->_linha.empty();
}



void LinhaInimigos::atualizaDimensoes() {

	float lim_esq, lim_dir;
	lim_esq = this->_linha.front()->getPosicao().x;
	lim_dir = this->_linha.back()->getPosicao().x + _inimigo_dimensoes.x;
	
	sf::Vector2f posicao_atualizada = this->_linha.front()->getPosicao();

	sf::Vector2f atualizada(lim_dir - lim_esq, this->getBounds().height);
	this->setDimensoes(atualizada);
	this->_objeto.setPosition(posicao_atualizada);
}



Tiro* LinhaInimigos::atirar() {
	
	// Um jeito burro de selecionar aleatoriamente um inimigo da lista (a melhorar)
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, this->_linha.size()-1);
	int indice = distribution(generator);

	std::list<Inimigo*>::iterator it = this->_linha.begin();
	std::advance(it, indice);
	Inimigo* inimigo = *it;

	return inimigo->atirar();
}