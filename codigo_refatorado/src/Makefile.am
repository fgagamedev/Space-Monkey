# Author: Edson Alves - edsonalves@unb.br
# Date: 21/12/2012

# Library description
lib_LTLIBRARIES = libitem.la

# Programs excluded from instalation
#noinst_PROGRAMS = atendimento
bin_PROGRAMS = spacemonkey

# Library flags
libitem_la_LDFLAGS = -static

# Library sources
libitem_la_SOURCES = inicializador.cpp definicoesMapaLogico.cpp inimigo.cpp torre.cpp jogador.cpp util.cpp audio.cpp SDL_Tela.cpp tela.cpp SDL_Mapa.cpp mapa.cpp fase.cpp animacao.cpp eventos.cpp marcador.cpp menuEventos.cpp menus.cpp jogo.cpp horda.cpp SDL_Sprite.cpp chipanze1.cpp chipanze2.cpp orangotango.cpp gorila1.cpp gorila2.cpp atiradorSimples.cpp atiradorDuplo.cpp atiradorRetardante.cpp atiradorAngulado.cpp atiradorMoreFire.cpp agentesProtetores.cpp bombardeiro.cpp fortification.cpp ironMan.cpp muro.cpp muroReforcado.cpp tanque.cpp

# Libraries needed to build our library
libitem_la_LIBADD = 

# Program description
spacemonkey_SOURCES =	spacemonkey.cpp

# Libraries needed to build program
spacemonkey_LDADD =	libitem.la -lSDL -lSDL_image -lSDL_ttf

# Include flags
INCLUDES = -I../include -Wall -Wno-long-long -W -pedantic -ansi

