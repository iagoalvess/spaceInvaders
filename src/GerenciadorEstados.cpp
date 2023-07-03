#include "GerenciadorEstados.h"
#include <iostream>

Estado GerenciadorEstados::_estado = menu_inicial;


GerenciadorEstados::GerenciadorEstados() {
	_estado = menu_inicial;
}


GerenciadorEstados::~GerenciadorEstados() {

}



void GerenciadorEstados::setEstado(Estado estado_novo) {
	this->_estado = estado_novo;
}



Estado GerenciadorEstados::getEstadoAtual() {
	return this->_estado;
}



void GerenciadorEstados::pausar() {
	if (this->_estado == pausado) {
		this->_estado = jogando;
	}
	else if (this->_estado == jogando) {
		this->_estado = pausado;
	}
}

void GerenciadorEstados::exibirInstrucao() {
	if (this->_estado == instrucao) {
		this->_estado = menu_inicial;
	}
	else if (this->_estado == menu_inicial) {
		this->_estado = instrucao;
	}
}

void GerenciadorEstados::iniciaJogo() {
	if (this->_estado == menu_inicial) {
		this->_estado = jogando;
	}
}