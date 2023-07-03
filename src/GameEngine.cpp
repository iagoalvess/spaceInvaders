#include "GameEngine.h"


GameEngine::GameEngine() {
	//Player
	this->_player = new Player();
	this->_renderizaveis.push_back(this->_player);

	//Bloco de Inimigos
	BlocoInimigos* bloco = new BlocoInimigos();
	this->_bloco_inimigos = bloco;
	this->_renderizaveis.push_back(bloco);
	
	this->_estado.setEstado(jogando);

	this->_score = 0;
}



void GameEngine::atualizaJogo() {

	this->colisoesTiro(); //Checa se o tiro acertou algum objeto, destroi o tiro e da dano no objeto
	this->removeTirosPerdidos(); //Remove os tiros que não acertaram nenhum objeto
	this->moverObjetos(); //Move os objetos
	this->ganhar(); //Checa se todos os inimigos morreram
	this->gameOver(); // Checa se o player perdeu todas as suas vidas
	this->recargas(); //Controla a frequencia de tiros do player e do bloco de inimigos

}



std::list<ObjetoJogo*> GameEngine::renderizaveis() {
	return this->_renderizaveis;
}



void GameEngine::moverPlayer(float direcao) {
	this->_player->mover(direcao);
}



void GameEngine::moverObjetos() {
	for (ObjetoJogo* obj : this->_renderizaveis) {
		obj->mover();
	}
}



void GameEngine::colisoesTiro() {

	std::set<ObjetoJogo*> destruir; //Conjunto de objetos a serem destruidos

	for (Tiro* tiro : this->_tiros){
		if(tiro->getOrigem()->getSubtipo() == 'P'){
			for (LinhaInimigos* linha : this->_bloco_inimigos->getBloco()) {
				for (Inimigo* inimigo : linha->getLinha()) {
					bool colisao_tiro_inimigo = tiro->getBounds().intersects(inimigo->getBounds());
					if (colisao_tiro_inimigo) {
						destruir.insert(tiro);
						destruir.insert(inimigo);
					}
				}
			}
		}


		if (tiro->getOrigem()->getSubtipo() == 'I') {
			bool colisao_tiro_player = tiro->getBounds().intersects(this->_player->getBounds());
			if (colisao_tiro_player) {
				destruir.insert(tiro);
				this->_player->perdeUmaVida();
			}
		}

		
	}


	for (ObjetoJogo* obj : destruir) {
		if (obj->getSubtipo() == 'I') {
			
			LinhaInimigos* linha = dynamic_cast<LinhaInimigos*>((dynamic_cast<Inimigo*>(obj))->getLinhaPertencente());
			
			this->_score += 10*((dynamic_cast<Inimigo*>(obj))->getNivel()+1);
			
			linha->removerInimigo(dynamic_cast<Inimigo*>(obj));
			if (linha->linhaVazia()) {
				this->_bloco_inimigos->removerLinha(linha);
			}
		}

		else if (obj->getSubtipo() == 'T') {
			this->_tiros.remove(dynamic_cast<Tiro*>(obj));
		}
		this->_renderizaveis.remove(obj);
		delete obj;
	}


		this->_bloco_inimigos->atualizaDimensoes();
		this->_bloco_inimigos->atualizaVelocidade();

}



void GameEngine::removeTirosPerdidos() {

	std::list<ObjetoJogo*> destruir;

	for (Tiro* tiro : this->_tiros) {
			if (tiro->getPosicao().y < 0 or tiro->getPosicao().y > _janela_altura) {
				destruir.push_back(tiro);
		}
	}

	for (ObjetoJogo* obj : destruir) {
		this->_tiros.remove(dynamic_cast<Tiro*>(obj));
		this->_renderizaveis.remove(obj);
		delete obj;
	
	}

}



void GameEngine::inimigoAtirar() {
	Tiro* tiro = this->_bloco_inimigos->atirar();
	this->_tiros.push_back(tiro);
	this->_renderizaveis.push_back(tiro);
}



void GameEngine::playerAtirar() {
	if (this->_player->getTempoRecarga() < 0) {
		Tiro* tiro = this->_player->atirar();
		this->_tiros.push_back(tiro);
		this->_renderizaveis.push_back(tiro);
		this->_player->resetTempoRecarga();
	}
}



void GameEngine::ganhar() {
	if (this->_bloco_inimigos->blocoVazio()) {
		this->_estado.setEstado(vitoria);
	};
}



void GameEngine::gameOver() {
	bool _numero_vidas = (this->_player->getVidas() == 0);

	float _borda_inferior_bloco = this->_bloco_inimigos->getPosicao().y + this->_bloco_inimigos->getBounds().height;
	bool _bloco_atinge_player = (_borda_inferior_bloco >= this->_player->getPosicao().y);
	
	if (_numero_vidas || _bloco_atinge_player) { 
	this->_estado.setEstado(game_over);
	}
}



void GameEngine::recargas() {
	this->_player->atualizaTempoRecarga();
	if (this->_bloco_inimigos->getTempoRecarga() == 0) {
		this->inimigoAtirar();
	}
	this->_bloco_inimigos->atualizaTempoRecarga();
}



int GameEngine::getVidas() {
	return this->_player->getVidas();
}



int GameEngine::getScore(){
	return this->_score;
}

BlocoInimigos* GameEngine::getBlocoInimigos() {
	return this->_bloco_inimigos;
}

Player* GameEngine::getPlayer() {
	return this->_player;
}

GerenciadorEstados GameEngine::getEstado() {
	return this->_estado;
}

std::list<Tiro*> GameEngine::getTiros() {
	return this->_tiros;
}