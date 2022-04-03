#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QList>
#include <QWidget>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QPushButton>
#include "play.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Game *ui;
    play *playwindow;


};
#endif // GAME_H
