#include "Tela.h"
#include <iostream>
#include <string>


// Inicializar as futuras vari�veis aqui
void Tela::initVariaveis() {
	this->_janela = nullptr;
}



//Podemos colocar novas configura��es da Janela aqui
void Tela::initJanela() {
	this->_dimensoes_janela.width = _janela_largura;
	this->_dimensoes_janela.height = _janela_altura;
	this->_janela = new sf::RenderWindow(_dimensoes_janela, "SPACE INVADERS");
	this->_janela->setFramerateLimit(300);   //Quadros por segundo

}



// Construtor
Tela::Tela() {
	this->initVariaveis();
	this->initJanela();
}



//Destrutor
Tela::~Tela() {
	delete this->_janela;
}




// Retorna um booleano informando se o jogo est� rodando
bool Tela::janelaAberta() {
	return this->_janela->isOpen();
}



//Monitora os eventos na Janela e responde a esses eventos 
void Tela::monitoraEventos() {
	
	while (this->_janela->pollEvent(this->_evento)) //captura eventos na janela
	{

		if (this->_evento.type == sf::Event::Closed) { //Evento fechar janela clicando em X
			this->_janela->close();
		}

		else if (this->_evento.type == sf::Event::KeyPressed) // V� se o evento foi uma tecla apertada
		{
			switch (this->_evento.key.code)
			{
			case sf::Keyboard::Key::Escape:    //Evento fechar janela apertanto ESC
				this->_janela->close();
				break;

			case sf::Keyboard::Key::Space:    //Evento começar jogo
				this->_estado.iniciaJogo();
				break;

			case sf::Keyboard::Key::P:    //Evento pausar
				this->_estado.pausar();
				break;

			case sf::Keyboard::Key::I:    //Evento mostrar as instrucoes
				this->_estado.exibirInstrucao();
				break;
			
			case sf::Keyboard::Key::Right:    //Evento mover para direita
				this->_game_engine.moverPlayer(1.0);
				break;

			case sf::Keyboard::Key::Left:     //Evento mover para esquerda
				this->_game_engine.moverPlayer(-1.0);
				break;

			case sf::Keyboard::Key::Up:     //Evento atirar
				this->_game_engine.playerAtirar();
				break;

			default:
				break;
			}
		}

	}


}




//Atualiza o jogo
void Tela::atualizar() {

	this->monitoraEventos(); //Monitora os eventos da tela

	this->_game_engine.atualizaJogo();

}



//Renderiza o jogo: limpa o frame anterior, renderiza os objetos e exibe na janela
void Tela::renderizar() {

	this->_janela->clear();

	for (ObjetoJogo* obj : _game_engine.renderizaveis())
	{
		this->_janela->draw(*obj);
	}


	this->exibirScore();
	this->exibirVidas();

	this->_janela->display();

}




void Tela::exibirVitoria() {

		this->_janela->clear();

		sf::Text vitoria;

		vitoria.setFont(_fonte_padrao);
		vitoria.setString("YOU    WIN    ");

		vitoria.setPosition(_janela_largura/2.0f - vitoria.getLocalBounds().width, 0.25 * _janela_altura);
     	vitoria.setCharacterSize(70);
		vitoria.setFillColor(sf::Color::Yellow);


		sf::Sprite sprite_vitoria;

		sprite_vitoria.setTexture(_textura_vitoria);
		sprite_vitoria.scale(0.4, 0.4);
		sprite_vitoria.setPosition(_janela_largura / 2.f - sprite_vitoria.getGlobalBounds().width / 2.f, 0.4* _janela_altura);
		
		this->exibirScoreFinal();

		this->_janela->draw(vitoria);
		this->_janela->draw(sprite_vitoria);
		this->_janela->display();

}



void Tela::exibirScoreFinal() {
	
	std::string valor_score = "Score   " + std::to_string(this->_game_engine.getScore()) + "    ";
	
	sf::Text score;

	score.setFont(_fonte_padrao);
	score.setString(valor_score);

	score.setPosition(_janela_largura / 2.0f - score.getLocalBounds().width / 2, 0.5 * _janela_altura);
	score.setCharacterSize(30);
	score.setFillColor(sf::Color::White);

	this->_janela->draw(score);
}



void Tela::exibirGameOver() {

	this->_janela->clear();

	sf::Text gameover;

	gameover.setFont(_fonte_padrao);
	gameover.setString("Game    Over    ");
	gameover.setPosition(_janela_largura / 2.0f - gameover.getLocalBounds().width, 0.25 * _janela_altura);
	gameover.setCharacterSize(70);
	gameover.setFillColor(sf::Color::Red);


	sf::Sprite sprite_game_over;

	sprite_game_over.setTexture(_textura_game_over);
	sprite_game_over.scale(0.4, 0.4);
	sprite_game_over.setPosition(_janela_largura / 2.f - sprite_game_over.getGlobalBounds().width / 2.f, 0.4 * _janela_altura);


	this->exibirScoreFinal();

	this->_janela->draw(gameover);
	this->_janela->draw(sprite_game_over);
	this->_janela->display();
}



void Tela::exibirMenuInicial() {
	
	this->_janela->clear();
	
	sf::Text space_invaders;
	space_invaders.setFont(_fonte_padrao);
	space_invaders.setString("      Space\nInvaders      ");
	space_invaders.setPosition(_janela_largura/2.0f - space_invaders.getGlobalBounds().width, 0.2 * _janela_altura);
	space_invaders.setCharacterSize(70);
	space_invaders.setFillColor(sf::Color::Green);

	
	sf::Text menu;


	menu.setFont(_fonte_padrao);
	menu.setString("                               Press  SPACEBAR  to  start");
	menu.setPosition(_janela_largura/2.f - menu.getGlobalBounds().width, 0.6 * _janela_altura);
	menu.setCharacterSize(50);
	menu.setFillColor(sf::Color::White);
	

	sf::Text instrucao;

	instrucao.setFont(_fonte_padrao);
	instrucao.setString("\n                               Press    I    to instructions");
	instrucao.setPosition(_janela_largura/1.6f - instrucao.getGlobalBounds().width, 0.75 * _janela_altura);
	instrucao.setCharacterSize(30);
	instrucao.setFillColor(sf::Color::White);

	sf::Sprite sprite_menu;
	sprite_menu.setTexture(_textura_menu);
	sprite_menu.scale(0.4, 0.4);
	sprite_menu.setPosition(_janela_largura / 2.f - sprite_menu.getGlobalBounds().width / 2.f, 0.48 * _janela_altura);


	this->_janela->draw(space_invaders);
	this->_janela->draw(menu);
	this->_janela->draw(instrucao);
	this->_janela->draw(sprite_menu);
	this->_janela->display();

}



void Tela::exibirScore() {

	std::string valor_score = "Score   " + std::to_string(this->_game_engine.getScore());

	sf::Text score;

	score.setFont(_fonte_padrao);
	score.setString(valor_score);
	score.setPosition(0.86* _janela_largura, 0.15* _janela_altura);
	score.setCharacterSize(20);
	score.setFillColor(sf::Color::White);


	this->_janela->draw(score);
}



void Tela::exibirVidas(){

	int num_vidas = this->_game_engine.getVidas();

	if (num_vidas > 0) {
		sf::Sprite sprite_vidas;
		sprite_vidas.setTexture(*_textura_vidas[num_vidas]);

		sprite_vidas.setPosition(0.86*_janela_largura, 0.1 *_janela_altura);
		sprite_vidas.scale(0.5, 0.5);


		this->_janela->draw(sprite_vidas);
	}
}



void Tela::exibirPause() {

	sf::Text pause;

	pause.setFont(_fonte_padrao);
	pause.setString("Paused");
	pause.setPosition(_janela_largura / 2.0f - pause.getLocalBounds().width, 0.4 * _janela_altura);
	pause.setCharacterSize(50);
	pause.setFillColor(sf::Color(100,100,100));

	this->_janela->draw(pause);
	this->_janela->display();
}

void Tela::exibirInstrucao() {

	this->_janela->clear();

	sf::Text instrucao;

	instrucao.setFont(_fonte_padrao);
	instrucao.setString("Instructions");
	instrucao.setPosition(_janela_largura / 2.0f - instrucao.getLocalBounds().width, 0.2 * _janela_altura);
	instrucao.setCharacterSize(50);
	instrucao.setFillColor(sf::Color(100,100,100));

	sf::Text teclas;

	teclas.setFont(_fonte_padrao);
	teclas.setString("\nI\t\t\t\t\t\t\t\t\t\t\topen and close instructions\nSPACEBAR\t\t\tstart the game\nESC   \t\t\t\t\t\t\t\tclose the game\nP\t\t\t\t\t\t\t\t\t\t\tpause the game\n");
	teclas.setPosition(_janela_largura/1.4f - teclas.getGlobalBounds().width, 0.45 * _janela_altura);
	teclas.setCharacterSize(30);
	teclas.setFillColor(sf::Color::White);

	this->_janela->draw(instrucao);
	this->_janela->draw(teclas);
	this->_janela->display();

}