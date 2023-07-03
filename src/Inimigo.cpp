#include "Inimigo.h"

Inimigo::Inimigo() {
	this->_subtipo = 'I';
	this->_linha_pertencente = nullptr;
	this->_objeto.setSize(_inimigo_dimensoes); //Tamanho da nave na tela
	this->_objeto.setFillColor(sf::Color::Red); //Cor 
	this->_objeto.setPosition(_inimigo_posicao_inicial); // Posi��o inicial na tela
	this->_velocidade = _inimigo_velocidade;

	this->_objeto.setTexture(&_textura_inimigo_1);
}



Inimigo::Inimigo(sf::Vector2f posicao_inicial, ObjetoJogo* linha, int nivel) {
	this->_subtipo = 'I';
	this->_nivel_inimigo = nivel;

	this->_linha_pertencente = linha;

	this->_objeto.setSize(_inimigo_dimensoes); //Tamanho da nave na tela
	this->_objeto.setFillColor(sf::Color::White); //Cor 
	this->_objeto.setPosition(posicao_inicial); // Posi��o inicial na tela
	
	this->_velocidade = inimigoVelocidade(nivel);

	this->_objeto.setTexture(_textura_inimigos[nivel]);
}


Inimigo::~Inimigo() {
}



ObjetoJogo* Inimigo::getLinhaPertencente() {
	return this->_linha_pertencente;
}



int Inimigo::getNivel() {
	return this->_nivel_inimigo;
}



void Inimigo::mover(sf::Vector2f incremento) {
	this->_objeto.move(incremento);
}



Tiro* Inimigo::atirar() {
	Tiro* tiro = new Tiro(this);
	return tiro;
}