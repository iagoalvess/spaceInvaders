#include "VariaveisGlobais.h"

//Janela 
unsigned int _janela_largura = sf::VideoMode::getDesktopMode().width;
unsigned int _janela_altura = sf::VideoMode::getDesktopMode().height;



// Limite jogo
float _limite_esquerdo = _janela_largura * 0.15;
float _limite_direito = _janela_largura * 0.85;

 
// Player
sf::Vector2f _player_dimensoes(_janela_largura/30.f, _janela_altura/30.f);
sf::Vector2f _player_posicao_inicial(400, 570);
sf::Vector2f _player_velocidade(_janela_largura/50.0f, 0.0f);


// Inimigos
sf::Vector2f _inimigo_dimensoes(_janela_largura / 30.f, _janela_altura / 25.f);
sf::Vector2f _inimigo_posicao_inicial(400, 50);
std::vector<sf::Vector2f> _inimigo_velocidades = {sf::Vector2f(_janela_largura / 3000.0f, 0.0f), sf::Vector2f(_janela_largura / 2500.0f, 0.0f), sf::Vector2f(_janela_largura / 2000.0f, 0.0f)};
sf::Vector2f _inimigo_velocidade(_janela_largura / 3000.0f, 0.0f);
sf::Vector2f inimigoVelocidade(int nivel) {
	return  _inimigo_velocidades[nivel];
}


// Linha Inimigos
int num_inimigos_linha = 10;
sf::Vector2f _linha_distancia_inimigos(_janela_largura / 70.0f, 0.f);
sf::Vector2f _linha_inimigo_dimensoes(10*_inimigo_dimensoes.x + 9.f*_linha_distancia_inimigos.x, _inimigo_dimensoes.y);
sf::Vector2f _linha_inimigo_posicao_inicial(_janela_largura / 2 - _linha_inimigo_dimensoes.x / 2, 50);
sf::Vector2f _linha_inimigo_velocidade(_janela_largura / 5000.0f, 0.f);


// Bloco Inimigos
float bloco_num_linhas = 3;
sf::Vector2f _bloco_distancia_linhas(0.f, _janela_altura / 50.0f);
sf::Vector2f _bloco_inimigo_dimensoes(_linha_inimigo_dimensoes.x, bloco_num_linhas * _linha_inimigo_dimensoes.y + (bloco_num_linhas-1)*_bloco_distancia_linhas.y );
sf::Vector2f _bloco_inimigo_posicao_inicial(_janela_largura/2 - _bloco_inimigo_dimensoes.x/2, 50.f);
sf::Vector2f _bloco_inimigo_velocidade(_linha_inimigo_posicao_inicial);


// Tiro
sf::Vector2f _tiro_dimensoes(4.f, 0.85 * _bloco_distancia_linhas.y);
sf::Vector2f _tiro_velocidade(0.f, _janela_altura/400);



// Tempo de recargas 
int _recarga_inimigo = 900;
std::vector<int> _recargas_inimigo = {900, 500, 200};
int _recarga_player = 60;


// Texturas
sf::Texture _textura_player;
sf::Texture _textura_tiro;
sf::Texture _textura_inimigo_0;
sf::Texture _textura_inimigo_1;
sf::Texture _textura_inimigo_2;
sf::Texture _textura_menu;
sf::Texture _textura_vitoria;
sf::Texture _textura_game_over;
sf::Texture _textura_1_vida;
sf::Texture _textura_2_vidas;
sf::Texture _textura_3_vidas;



void carregaTexturas() {
	if (!_textura_inimigo_0.loadFromFile("imgfiles/inimigo0.png") || 
						!_textura_inimigo_1.loadFromFile("imgfiles/inimigo1.png") ||
						!_textura_inimigo_2.loadFromFile("imgfiles/inimigo2.png") ||
						!_textura_player.loadFromFile("imgfiles/player.png") ||
						!_textura_tiro.loadFromFile("imgfiles/tiro.png") ||
						!_textura_menu.loadFromFile("imgfiles/menu.png") ||
						!_textura_vitoria.loadFromFile("imgfiles/vitoria.png") ||
						!_textura_game_over.loadFromFile("imgfiles/gameover.png") ||
						!_textura_1_vida.loadFromFile("imgfiles/1vida.png") ||
						!_textura_2_vidas.loadFromFile("imgfiles/2vidas.png") ||
						!_textura_3_vidas.loadFromFile("imgfiles/3vidas.png")) {
		throw("Erro na leitura de texturas!");
	}
}

std::vector<sf::Texture*> _textura_inimigos = {&_textura_inimigo_0, &_textura_inimigo_1, &_textura_inimigo_2};

std::map<int, sf::Texture*> _textura_vidas = { {1, &_textura_1_vida} ,{2, &_textura_2_vidas}, {3, &_textura_3_vidas} };


//Fonte
sf::Font _fonte_padrao;
void carregaFonte() {
	if(!_fonte_padrao.loadFromFile("imgfiles/ARCADECLASSIC.TTF")) {
		throw("Erro na leitura da fonte!");
	}
}


