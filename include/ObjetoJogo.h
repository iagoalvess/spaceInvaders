#ifndef OBJETOJOGO_H
#define OBJETOJOGO_H

// Inimigo e Player serão classes filhas de Nave

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class ObjetoJogo : public sf::Drawable{
protected:
	sf::RectangleShape _objeto;
	char _subtipo; 
	sf::Vector2f _velocidade;

public:
	ObjetoJogo();
	ObjetoJogo(sf::Vector2f tamanho, sf::Vector2f posicao);
	
	virtual ~ObjetoJogo();

	const sf::FloatRect getBounds();

	void setDimensoes(sf::Vector2f dimensao);

	void setPosicao(sf::Vector2f posicao);

	sf::Vector2f getPosicao();

	char getSubtipo();

	virtual void mover();
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif