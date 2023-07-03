#ifndef TELA_H
#define TELA_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "VariaveisGlobais.h"
#include "GameEngine.h"
#include "Player.h"
#include "Inimigo.h"
#include "Tiro.h"

#include <list>
#include <memory>

#include "GerenciadorEstados.h"

class Tela {
private:
	sf::RenderWindow* _janela;
	sf::VideoMode _dimensoes_janela;
	sf::Event _evento;

	void initVariaveis();
	void initJanela();

	GameEngine _game_engine;


public:
	GerenciadorEstados _estado;

	Tela();

	virtual ~Tela();

	bool janelaAberta(); 

	void monitoraEventos();

	void atualizar(); 

	void renderizar(); 

	void exibirVitoria();

	void exibirGameOver();

	void exibirScore();

	void exibirVidas();

	void exibirMenuInicial();

	void exibirScoreFinal();

	void exibirPause();

	void exibirInstrucao();
};

#endif