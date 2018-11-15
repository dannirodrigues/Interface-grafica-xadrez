#ifndef CAVALO_H
#define CAVALO_H

#include <iostream>
#include <string>
#include <cmath>
#include "peca.h"

class Tabuleiro;

class Cavalo:public Peca
{
public:
	/*	VERIFICA_JOGADA
	 *		Recebe como parametros dois inteiros que representam uma posicao i e j (respectivamente) no tabuleiro e, um ponteiro pro tabuleiro.
	 *		Retorna um valor logico (true ou false) informando se a jogada solicitada eh valida.
	 */
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);

	std::string retornaString() override {

		if(getCor() == 'P') return "\u265E";
		else return "\u2658";
	}
	virtual QGraphicsItem *createItem(QGraphicsScene *scene) override {
		 if(getCor()=='B')
			  return scene->addPixmap(QPixmap(":/Imagens/w_knight_png_shadow_256px.png").scaled(80, 80));
		 else
			  return scene->addPixmap(QPixmap(":/Imagens/b_knight_png_shadow_256px.png").scaled(80, 80));
	}
};

#endif
