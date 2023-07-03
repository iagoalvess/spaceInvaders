#include "Tiro.h"
#include <iostream>

Tiro::Tiro(ObjetoJogo* origem) : ObjetoJogo() {

	this->_origem = origem;
	this->_subtipo = 'T';
	
	this->initVelocidade();

	this->_objeto.setSize(_tiro_dimensoes); 
	this->_objeto.setFillColor(sf::Color::White); 

	this->_objeto.setTexture(&_textura_tiro);
}



void Tiro::initVelocidade() {

	if (this->_origem->getSubtipo() == 'I') {
		this->_velocidade = _tiro_velocidade;
		this->_objeto.setPosition(this->_origem->getPosicao().x + _inimigo_dimensoes.x / 2 - _tiro_dimensoes.x / 2, this->_origem->getPosicao().y);
	}
	else {
		this->_velocidade = - _tiro_velocidade;
		this->_objeto.setPosition(this->_origem->getPosicao().x + _player_dimensoes.x / 2 - _tiro_dimensoes.x / 2, this->_origem->getPosicao().y);
	}
}



ObjetoJogo* Tiro::getOrigem() {
	return this->_origem;
}



void Tiro::mover(){
	this->_objeto.move(this->_velocidade);
}

