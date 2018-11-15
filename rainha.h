#ifndef RAINHA_H
#define RAINHA_H

#include <iostream>
#include <string>
#include "peca.h"

class Tabuleiro;

class Rainha:public Peca
{

public:
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
	virtual QGraphicsItem *createItem(QGraphicsScene *scene) override {
		 if(getCor()=='B')
			  return scene->addPixmap(QPixmap(":/Imagens/w_queen_png_shadow_256px.png").scaled(80, 80));
		 else
			  return scene->addPixmap(QPixmap(":/Imagens/b_queen_png_shadow_256px.png").scaled(80, 80));
	}
private:

	int peca_no_caminho_torre(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
  	int peca_no_caminho_bispo(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);

  	std::string retornaString() override {

		if(getCor() == 'P') return "\u265A";
		else return "\u2654";
	}
};

#endif
