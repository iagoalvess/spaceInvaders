#include "Tela.h"
#include "VariaveisGlobais.h"
#include "GerenciadorEstados.h"


int main()
{
    sf::Context context;
    carregaTexturas();
    carregaFonte();

    Tela tela;

    while (tela.janelaAberta())
    {
        switch (tela._estado.getEstadoAtual()) {

        case(menu_inicial):
            tela.exibirMenuInicial();
            tela.monitoraEventos();
            break;

        case(instrucao):
            tela.monitoraEventos();
            tela.exibirInstrucao();
            break;

        case(jogando):
            tela.atualizar();
            tela.renderizar();
            break;

        case(pausado):
            tela.monitoraEventos();
            tela.exibirPause();
            break;

        case(vitoria):
            tela.exibirVitoria();
            tela.monitoraEventos();
            break;

        case(game_over):
            tela.exibirGameOver();
            tela.monitoraEventos();
            break;
       
        default:
            break;
        }
    
    }
    return 0;
}