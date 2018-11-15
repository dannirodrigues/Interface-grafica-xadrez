#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tabuleiro.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void resizeEvent(QResizeEvent* event);

    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_button_clicked();

private:

    void _update_view_size();

    int cont=-1;

    Ui::MainWindow *ui;
    Tabuleiro *_tabuleiro;
};

#endif // MAINWINDOW_H
