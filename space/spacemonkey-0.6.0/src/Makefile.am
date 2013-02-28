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
libitem_la_SOURCES = jogador.cpp SDL_Tela.cpp tela.cpp SDL_Mapa.cpp fase.cpp menus.cpp jogo.cpp

# Libraries needed to build our library
libitem_la_LIBADD = 

# Program description
spacemonkey_SOURCES =	spacemonkey.cpp

# Libraries needed to build program
spacemonkey_LDADD =	libitem.la -lSDL

# Include flags
INCLUDES = -I../include -Wall -Wno-long-long -W -pedantic -ansi

