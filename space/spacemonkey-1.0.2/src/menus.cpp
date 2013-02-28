
#include "menus.h"
#include "tela.h"
#include "menuEventos.h"
#include "animacao.h"
#include "nomesArquivos.h"
#include "constantes.h"
#include "initException.h"
#include "exitException.h"
#include "fileNotFoundException.h"
#include "animaException.h"


//inicia as variáveis locais
void Menus::init() throw (InitException)
{
	this->telaJogo = Tela::obterTela();
}

//destrutor da classe
Menus::~Menus()
{
	Tela::liberarTela();
}

//mostra a animação inicial do jogo
void Menus::apresentacaoInicial() throw(InitException, FileNotFoundException, ExitException, AnimaException)
{
	Animacao *apresentacao = NULL;
	try{
	//cria uma animação
		apresentacao = new Animacao();
		//estipula o tempo (em segundos) de duração da animação
	}catch(bad_alloc ba){
		throw InitException("Falha ao alocar memoria para mostrar a apresentacao inicial");
	}
	
	apresentacao->setTime(5);
	//carrega as imagens que a animação mostrará, suas posições e o momento em que cada uma aparecerá
	apresentacao->carregarImagem(IMAGEM_APRESENTACAO_INICIAL,CENTRALIZAR,0,0);
	apresentacao->carregarImagem(IMAGEM_PRESENTS,CENTRALIZAR,510,3);
	
	apresentacao->rodar();	
	
	delete apresentacao;
}

//mostra o menu inicial pro jogador. retorna o inteiro correspondente ao botão pressionado
Botoes Menus::menuInicial() throw(FileNotFoundException, ExitException)
{
	MenuEventos *menuEventos = new MenuEventos();
	menuEventos->init();
	Botoes bt = menuEventos->getBotaoPressionado();
	
	delete menuEventos;
	
	return bt;
}

