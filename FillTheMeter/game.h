#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include <QKeyEvent>
#include <QString>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

    public:
        explicit Game(QWidget *parent = 0);
        const char *strings[3] = {"Ready", "Set", "Go!"};
        const char *herecomedatboi[4] = {"Bush", "did", "9", "11"};
        ~Game();
        void countdown();
        void keyPressEvent(QKeyEvent *);

    private slots:
        void updateLabel();



        void on_button1_clicked();

        void on_button2_clicked();

        void on_button3_clicked();

        void on_button4_clicked();

        void on_start_clicked();

private:
        Ui::Game *ui;
        int i;
        bool go = false;
        int progress[2];
        void winner(int);
        void on_button_clicked(int);
};

#endif // GAME_H
