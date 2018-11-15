#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include<string>
#include <QGraphicsPixmapItem>
#include "tabuleiro.h"
using namespace std;

std::string switch_char_string(char letra);
int switch_para_numero(char numero);
int switch_para_letra(char letra);
bool decodifica_main(Tabuleiro *t, string jogadas_times, int posicao);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(new QGraphicsScene(0, 0, 1000, 1000, this));
    ui->graphicsView->scene()->addPixmap(QPixmap(":/Imagens/board_brown.png").scaled(1000, 1000));

    _tabuleiro = new Tabuleiro(ui->graphicsView->scene());

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->adjustSize();
    //ui->graphicsView->adjustSize();
    //ui->centralWidget->update();
    //_update_view_size();

    /*if(_tabuleiro->jogada("P5B", 5, 4, "") == false)
    {
        std::cout << "Jogada Invalida!" << std::endl;
    }*/

    ui->graphicsView->scale(400/ui->graphicsView->scene()->width(),
                            350/ui->graphicsView->scene()->height());

    on_button_clicked();
}

MainWindow::~MainWindow()
{
    delete _tabuleiro;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event) {

    QMainWindow::resizeEvent(event);
    //_update_view_size();
}

void MainWindow::_update_view_size() {

    ui->graphicsView->resetMatrix();
    ui->graphicsView->scale(ui->graphicsView->width()/ui->graphicsView->scene()->width(),
                            ui->graphicsView->height()/ui->graphicsView->scene()->height());
}

void MainWindow::on_button_clicked() {

    //ui->label->setText(QString("%0").arg(cont));
    decodifica_main(this->_tabuleiro, ui->set->text().toStdString(), cont);
    cont++;
    //ui->label->setText(QString("%0").arg(cont));
}

bool decodifica_main(Tabuleiro *t, string jogadas_times, int posicao)
{
    char cor_time;
    if(posicao%2 == 0) cor_time = 'B';
    else cor_time = 'P';

    string jogada_atual = jogadas_times;

    //caso letras sejam miusculas significa que sera apenas peao
    if(islower(jogada_atual[0]) != 0)
    {
        if(jogada_atual.size() == 2) //apenas movimentacao
        {
            string peca = std::string("P") + char('1' + switch_para_letra(jogada_atual[0])) + cor_time;
            int linha = switch_para_numero(jogada_atual[1]);
            int coluna = switch_para_letra(jogada_atual[0]);
            cout << peca << " " << linha << " " << coluna << endl;

            if(!t->jogada(peca, linha, coluna, jogada_atual))
            {
                std::cout << "Jogada Invalida" << std::endl;
                return false;
            }
            return true;
        }

        else if(jogada_atual.size() == 4) //movimentacao seguida de comida de peca
        {
            string peca = std::string("P") + char('1' + switch_para_letra(jogada_atual[0])) + cor_time;
            int linha = switch_para_numero(jogada_atual[3]);
            int coluna = switch_para_letra(jogada_atual[2]);
            cout << peca << " " << linha << " " << coluna << endl;

            if(!t->jogada(peca, linha, coluna, jogada_atual))
            {
                std::cout << "Jogada Invalida" << std::endl;
                return false;
            }
            return true;
        }
    }

    //caso seja minuscula sera as pecas restantes
    else if(isupper(jogada_atual[0]) != 0)
    {
        if(jogada_atual.size() == 3) //apenas movimentacao para cavalos
        {
            string peca = switch_char_string(jogada_atual[0]) + std::string("1") + cor_time;
            if(jogada_atual[0] == 'R' || jogada_atual[0] == 'D' ) peca = switch_char_string(jogada_atual[0]) + cor_time;
            int linha = switch_para_numero(jogada_atual[2]);
            int coluna = switch_para_letra(jogada_atual[1]);

            if(!t->jogada(peca, linha, coluna, jogada_atual))
            {
                peca = switch_char_string(jogada_atual[0]) + std::string("2") + cor_time;
                if(jogada_atual[0] == 'R' || jogada_atual[0] == 'D' ) peca = switch_char_string(jogada_atual[0]) + cor_time;
                if(!t->jogada(peca, linha, coluna, jogada_atual))
                {
                    std::cout << "Jogada Invalida" << std::endl;
                    return false;
                }
                cout << peca << " " << linha << " " << coluna << endl;
                return true;
            }
            cout << peca << " " << linha << " " << coluna << endl;
        }

        if(jogada_atual.size() == 4) //apenas movimentacao para cavalos
        {
            string peca = switch_char_string(jogada_atual[0]) + std::string("1") + cor_time;
            if(jogada_atual[0] == 'R' || jogada_atual[0] == 'D' ) peca = switch_char_string(jogada_atual[0]) + cor_time;
            int linha = switch_para_numero(jogada_atual[3]);
            int coluna = switch_para_letra(jogada_atual[2]);

            if(!t->jogada(peca, linha, coluna, jogada_atual))
            {
                peca = switch_char_string(jogada_atual[0]) + std::string("2") + cor_time;
                if(jogada_atual[0] == 'R' || jogada_atual[0] == 'D' ) peca = switch_char_string(jogada_atual[0]) + cor_time;
                if(!t->jogada(peca, linha, coluna, jogada_atual))
                {
                    std::cout << "Jogada Invalida" << std::endl;
                    return false;
                }
                cout << peca << " " << linha << " " << coluna << endl;
                return true;
            }
            cout << peca << " " << linha << " " << coluna << endl;
        }
    }

    else return false;
}



int switch_para_letra(char letra)
{
    switch(letra)
    {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
    }

    return -1;
}

int switch_para_numero(char numero)
{
    switch(numero)
    {
        case '1':
            return 7;
        case '2':
            return 6;
        case '3':
            return 5;
        case '4':
            return 4;
        case '5':
            return 3;
        case '6':
            return 2;
        case '7':
            return 1;
        case '8':
            return 0;
    }

    return -1;
}

std::string switch_char_string(char letra)
{
    switch(letra)
    {
        case 'C':
            return std::string("C");
        case 'T':
            return std::string("T");
        case 'B':
            return std::string("B");
        case 'D':
            return std::string("D");
        case 'R':
            return std::string("R");
    }

    return std::string("erro");;
}

void MainWindow::keyPressEvent(QKeyEvent *event){

    if(Qt::Key_Return) on_button_clicked();
}
