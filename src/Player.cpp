#include "Player.h"
#include <iostream>

Player::Player() {
	this->_subtipo = 'P';
	this->_velocidade = _player_velocidade;
	
	this->_objeto.setSize(_player_dimensoes); //Tamanho da nave na tela
	this->_objeto.setPosition(_player_posicao_inicial); // Posi��o inicial na tela

	this->_objeto.setTexture(&_textura_player);

	this->_vidas = 3;
	this->_tempo_recarga_tiro = _recarga_player;
}

Player::~Player() {

}



void Player::setPosition(const sf::Vector2f pos) {
	this->_objeto.setPosition(pos);
}



void Player::setPosition(const float x, const float y) {
	this->_objeto.setPosition(x, y);
}



int Player::getVidas(){
	return this->_vidas;
}



void Player::perdeUmaVida() {
	this->_vidas--;
}



int Player::getTempoRecarga() {
	return this->_tempo_recarga_tiro;
}



void Player::setTempoRecarga(int x) {
	this->_tempo_recarga_tiro = x;
}



void Player::resetTempoRecarga() {
	this->_tempo_recarga_tiro = _recarga_player;
}



void Player::atualizaTempoRecarga() {
	this->_tempo_recarga_tiro--;
}



void Player::mover(float direcao) {
	sf::Vector2f nova_posicao = this->_objeto.getPosition() + this->_velocidade * direcao;
	this->_objeto.setPosition(nova_posicao);
	if (this->getBounds().left < _limite_esquerdo) {
		this->setPosition(_limite_esquerdo, this->getBounds().top);
	}
	else if (this->getBounds().left + this->getBounds().width >= _limite_direito) {
		this->setPosition(_limite_direito - this->getBounds().width, this->getBounds().top);
	}
}



Tiro* Player::atirar() {
	Tiro* tiro = new Tiro(this);
	return tiro;
}

