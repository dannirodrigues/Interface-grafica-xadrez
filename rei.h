#ifndef REI_H
#define REI_H

#include <iostream>
#include <string>
#include "peca.h"

class Tabuleiro;

class Rei:public Peca
{
public:
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);

	std::string retornaString() override {

		if(getCor() == 'P') return "\u265B";
		else return "\u2655";
	}
	virtual QGraphicsItem *createItem(QGraphicsScene *scene) override {
		 if(getCor()=='B')
			  return scene->addPixmap(QPixmap(":/Imagens/w_king_png_shadow_256px.png").scaled(80, 80));
		 else
			  return scene->addPixmap(QPixmap(":/Imagens/b_king_png_shadow_256px.png").scaled(80, 80));
	}
};

#endif
