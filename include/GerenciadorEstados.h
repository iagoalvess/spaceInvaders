#ifndef GERENCIADORESTADOS_H
#define GERENCIADORESTADOS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Estados.h"

class GerenciadorEstados{
private:
	
	static Estado _estado;

public:

	GerenciadorEstados();
	~GerenciadorEstados();

	Estado getEstadoAtual();

	void setEstado(Estado estado_novo);

	void pausar();

	void exibirInstrucao();

	void iniciaJogo();

};

#endif // GERENCIADORESTADOS_H