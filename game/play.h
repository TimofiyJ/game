#ifndef PLAY_H
#define PLAY_H


#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QAbstractButton>
#include <QPainter>
#include <QList>
#include <QWidget>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QRect>
#include <QString>
#include <QMessageBox>

namespace Ui {
class play;
}

class play : public QDialog
{
    Q_OBJECT

public:
    explicit play(QWidget *parent = nullptr);
    ~play();

private slots:


    //void on_Tank0_clicked();
    void Rocket_clicked();

    //void on_Tank1_clicked();

    void Tank_clicked();
    void Rocket_Reborn();
    void Move(QPushButton*);
    void Tank_Reborn();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::play *ui;

    QList<QPushButton*> buttonList;
    int buttonSize;
    QLabel *DestroyedNames[10];
    int coins=0;
    int health=100;
    int shop=0;
    int Javelin=0;
    int NLAW=0;
    int Destroyed=0;
    int DestroyedTanks=0;
    int rocket0health=5;
    int rocket1health=5;
    int level=1;
    int Y=rand()%1000;
    int tank0health=10;
    int tank1health=10;
    int tank2health=10;
    int tank3health=10;
     QLabel *DestroyedNamesT[10];
     QList<QPushButton*> tankList;


};


#endif // PLAY_H
