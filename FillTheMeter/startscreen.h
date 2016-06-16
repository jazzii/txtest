#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>

namespace Ui {
class StartScreen;
}

class StartScreen : public QWidget
{
    Q_OBJECT

    public:
        explicit StartScreen(QWidget *parent = 0);
        ~StartScreen();

    public slots:
        void playGame();

    private slots:
        void on_play_clicked();

    private:
        Ui::StartScreen *ui;
};

#endif // STARTSCREEN_H
