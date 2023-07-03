#include "ObjetoJogo.h"

ObjetoJogo::ObjetoJogo() {
	_objeto.setSize(sf::Vector2f(30.0f, 15.0f)); //Tamanho da nave na tela
	_objeto.setFillColor(sf::Color::Green); //Cor 
	_objeto.setPosition(400, 570); // Posicao inicial na tela
	
}

ObjetoJogo::ObjetoJogo(sf::Vector2f tamanho, sf::Vector2f posicao) {
	_objeto.setSize(tamanho); //Tamanho da nave na tela
	_objeto.setFillColor(sf::Color::Green); //Cor 
	_objeto.setPosition(posicao.x, posicao.y); // Posicao inicial na tela

}

ObjetoJogo::~ObjetoJogo() {

}


sf::Vector2f ObjetoJogo::getPosicao() {
	return this->_objeto.getPosition();
}


// Retorna um struct com as coordendas da ponta superior esquerda do retangulo,
// bem como a largura e a altura
const sf::FloatRect ObjetoJogo::getBounds() {
	return this->_objeto.getGlobalBounds();
}



void ObjetoJogo::setDimensoes(sf::Vector2f dimensoes){
	this->_objeto.setSize(dimensoes);
}




void ObjetoJogo::setPosicao(sf::Vector2f posicao) {
	this->_objeto.setPosition(posicao);
}



char ObjetoJogo::getSubtipo() {
	return this->_subtipo;
}

void ObjetoJogo::mover() {

}

void ObjetoJogo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_objeto, states);
}

