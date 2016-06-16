#include "startscreen.h"
#include "ui_startscreen.h"
#include "game.h"

StartScreen::StartScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);

}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::playGame()
{
    auto game = new Game;
    game->setAttribute(Qt::WA_DeleteOnClose);
    game->show();
    deleteLater();
}

void StartScreen::on_play_clicked()
{
    playGame();
}
