#include "game.h"
#include "ui_game.h"
#include <QTimer>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{

    ui->setupUi(this);
    ui->label->setVisible(false);
    progress[0] = 0;
    progress[1] = 0;
    i = -1;
}

Game::~Game()
{
    delete ui;
}

void Game::updateLabel()
{
    if(i < 3)
        ui->label->setText(strings[i++]);
    if(i == 3)
    {
        go = true;
        ui->button1->setEnabled(true);
        ui->button2->setEnabled(true);
        ui->button3->setEnabled(true);
        ui->button4->setEnabled(true);
    }
}

void Game::on_start_clicked()
{
    ui->label->setVisible(true);
    ui->start->setEnabled(false);
    ui->start->setVisible(false);
    i = 0;
    countdown();
}

void Game::countdown()
{
    auto t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(updateLabel()));
    t->start(1000);
    if(i == 2)
    {
        t->stop();
        delete t;
        t = NULL;
    }
}

void Game::keyPressEvent(QKeyEvent *e)
{
    if(!go) return;
    char c = e->text().at(0).toLower().toLatin1();
    switch(c)
    {
        case 'a':
            on_button1_clicked();
            break;
        case 'd':
            on_button2_clicked();
            break;
        case 'i':
            on_button3_clicked();
            break;
        case 'p':
            on_button4_clicked();
            break;
        default:
            break;
    }
}

void Game::on_button_clicked(int x)
{
    if(x == 0)
        ui->progressBar->setValue(++progress[0]);
    else
        ui->progressBar_2->setValue(++progress[1]);

    if(progress[x] == 20)
        winner(x);
}

void Game::on_button1_clicked()
{
    ui->label->setText(herecomedatboi[0]);
    on_button_clicked(0);
}

void Game::on_button2_clicked()
{
    ui->label->setText(herecomedatboi[1]);
    on_button_clicked(0);
}

void Game::on_button3_clicked()
{
    ui->label->setText(herecomedatboi[2]);
    on_button_clicked(1);
}

void Game::on_button4_clicked()
{
    ui->label->setText(herecomedatboi[3]);
    on_button_clicked(1);
}

void Game::winner(int x)
{
    ui->button1->setText(herecomedatboi[0]);
    ui->button2->setText(herecomedatboi[1]);
    ui->button3->setText(herecomedatboi[2]);
    ui->button4->setText(herecomedatboi[3]);
    ui->button1->setEnabled(false);
    ui->button2->setEnabled(false);
    ui->button3->setEnabled(false);
    ui->button4->setEnabled(false);
    if(x == 0)
        ui->label->setText("p1 wins, p2 loses");
    else
        ui->label->setText("p2 wins, p1 loses");

}
