#ifndef GLOBAIS_H
#define GLOBAIS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <map>

// Janela
extern unsigned int _janela_largura;
extern unsigned int _janela_altura;


//Limite Jogo
extern float _limite_esquerdo;
extern float _limite_direito;


//Player
extern sf::Vector2f _player_dimensoes;
extern sf::Vector2f _player_posicao_inicial;
extern sf::Vector2f _player_velocidade;


//Inimigo
extern sf::Vector2f _inimigo_dimensoes;
extern sf::Vector2f _inimigo_posicao_inicial;
extern sf::Vector2f _inimigo_velocidade;
extern std::vector<sf::Vector2f> _inimigo_velocidades; 
extern sf::Vector2f inimigoVelocidade(int nivel);


//Tiro
extern sf::Vector2f _tiro_dimensoes;
extern sf::Vector2f _tiro_velocidade;


//Linha
extern int num_inimigos_linha;
extern sf::Vector2f _linha_inimigo_dimensoes;
extern sf::Vector2f _linha_inimigo_posicao_inicial;
extern sf::Vector2f _linha_inimigo_velocidade;
extern sf::Vector2f _linha_distancia_inimigos;


//Bloco
extern float bloco_num_linhas;
extern sf::Vector2f _bloco_distancia_linhas;
extern sf::Vector2f _bloco_inimigo_dimensoes;
extern sf::Vector2f _bloco_inimigo_posicao_inicial;
extern sf::Vector2f _bloco_inimigo_velocidade;


//Tempos
extern int _recarga_inimigo;
extern int _recarga_player;
extern std::vector<int> _recargas_inimigo;


//Texturas
extern sf::Texture _textura_player;

extern sf::Texture _textura_tiro;

extern sf::Texture _textura_inimigo_0;
extern sf::Texture _textura_inimigo_1;
extern sf::Texture _textura_inimigo_2;

extern sf::Texture _textura_menu;

extern sf::Texture _textura_vitoria;

extern sf::Texture _textura_game_over;

extern sf::Texture _textura_1_vida;
extern sf::Texture _textura_2_vidas;
extern sf::Texture _textura_3_vidas;

extern void carregaTexturas();

extern std::vector< sf::Texture*> _textura_inimigos;
extern std::map<int, sf::Texture*> _textura_vidas;


//Fonte 
extern sf::Font _fonte_padrao;
extern void carregaFonte();


#endif