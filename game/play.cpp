#include "play.h"
#include "ui_play.h"
#include "tank.h"
#include <iostream>
#include <QTimer>



play::play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::play)
{
    ui->setupUi(this);
    QString text="Health: "+ QString::number(health);
    ui->label2->setText(text);

    ui->comboBox->hide();
    ui->pushButton_4->hide();
    for(int i=0;i<6;i++){
        QString DestroyedName="DestroyedRocket"+QString::number(i);
        DestroyedNames[i]=play::findChild<QLabel*>(DestroyedName);
        DestroyedNames[i]->hide();
    }
    connect(ui->Rocket0,SIGNAL(clicked()),this,SLOT(Rocket_clicked()));
    connect(ui->Rocket1,SIGNAL(clicked()),this,SLOT(Rocket_clicked()));
    for(int i=0;i<6;i++){
        QString DestroyedNameT="DestroyedTank"+QString::number(i);
        DestroyedNamesT[i]=play::findChild<QLabel*>(DestroyedNameT);
        DestroyedNamesT[i]->hide();
    }
    connect(ui->Tank0,SIGNAL(clicked()),this,SLOT(Tank_clicked()));
    connect(ui->Tank1,SIGNAL(clicked()),this,SLOT(Tank_clicked()));
    connect(ui->Tank2,SIGNAL(clicked()),this,SLOT(Tank_clicked()));
    connect(ui->Tank3,SIGNAL(clicked()),this,SLOT(Tank_clicked()));

    QPushButton *tanks[4];
    for(int i=0;i<4;i++){
        QString butName="Tank"+QString::number(i);
        tanks[i]=play::findChild<QPushButton*>(butName);
        tanks[i]->hide();
    }
    QPushButton *rockets[2];
    for(int i=0;i<2;i++){
        QString butName="Rocket"+QString::number(i);
        rockets[i]=play::findChild<QPushButton*>(butName);
        rockets[i]->hide();
    }

}

play::~play()
{
    delete ui;
}



//    LEVEL 1



void play::Move(QPushButton* Enemy)
{
    QPushButton *btn=Enemy;
    if(Enemy->x()<850 && Destroyed<6){
        Enemy->setStyleSheet("image: url(:/new/prefix1/C:/Users/1/Desktop/pics/pngwing.com (1).png);");
    }
    QPropertyAnimation *animation = new QPropertyAnimation(btn,"geometry");
    if(Destroyed<6){
    animation->setDuration(5000);
    }
    else{
        animation->setDuration(10000);
    }
    animation->setEndValue(QRect(900,Y+50,211,131));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();

}




void play::Rocket_clicked()
{
    QPushButton *Enemy = dynamic_cast<QPushButton *>(sender());
    if(Destroyed==6){
        ui->Rocket1->destroyed();
        ui->Rocket1->hide();
        ui->Rocket0->destroyed();
        ui->Rocket0->hide();
        ++level;
    }
    else{
        if(health<=0){
            QMessageBox::warning(this,"Error","You lose :(");
            ui->Rocket1->destroyed();
            ui->Rocket1->hide();
            ui->Rocket0->destroyed();
            ui->Rocket0->hide();
            ui->Tank0->destroyed();
            ui->Tank0->hide();
            ui->Tank1->destroyed();
            ui->Tank1->hide();
            ui->Tank2->destroyed();
            ui->Tank2->hide();
            ui->Tank3->destroyed();
            ui->Tank3->hide();
        }
    if(Enemy->x()>=850){
        Enemy->setStyleSheet("image: url(:/new/prefix1/C:/Users/1/Desktop/pics/rocketshoot.png);");
        health=health-5;
        QString text="Health: "+ QString::number(health);
        ui->label2->setText(text);
    }
    if(Enemy->x()<850){
        Enemy->setStyleSheet("image: url(:/new/prefix1/C:/Users/1/Desktop/pics/pngwing.com (1).png);");
    }
    if (sender()==ui->Rocket1){
        rocket1health--;
    }
    if (sender()==ui->Rocket0){
        rocket0health--;
    }
    if (rocket1health==0){
        coins=coins+10;
        ++Destroyed;
        QString text="Coins: "+ QString::number(coins);
        ui->label->setText(text);
        Rocket_Reborn();


    }
    if (rocket0health==0){
        coins=coins+10;
        ++Destroyed;
        QString text="Coins: "+ QString::number(coins);
        ui->label->setText(text);
        Rocket_Reborn();

    }
    }
    }

void play::Rocket_Reborn(){

    if (rocket1health==0){
        if(Destroyed>5){
            QString DestroyedName="DestroyedRocket"+QString::number(Destroyed-1);
            DestroyedNames[Destroyed-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNames[Destroyed-1]->show();
            DestroyedNames[Destroyed-1]->move(ui->Rocket1->pos());
            ui->Rocket1->destroyed();
            ui->Rocket1->hide();

        }
        else{
            QString DestroyedName="DestroyedRocket"+QString::number(Destroyed-1);
            DestroyedNames[Destroyed-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNames[Destroyed-1]->show();
            DestroyedNames[Destroyed-1]->move(ui->Rocket1->pos());
            rocket1health=5;
            Y=rand()%500;
            ui->Rocket1->move(100,rand()%1000);
            Move(ui->Rocket1);

        }


    }
    else if (rocket0health==0){
        if (rocket0health==0){
            if(Destroyed>5){
                QString DestroyedName="DestroyedRocket"+QString::number(Destroyed-1);
                DestroyedNames[Destroyed-1]=play::findChild<QLabel*>(DestroyedName);
                DestroyedNames[Destroyed-1]->show();
                DestroyedNames[Destroyed-1]->move(ui->Rocket1->pos());
                ui->Rocket0->destroyed();
                ui->Rocket0->hide();

            }
            else{
                QString DestroyedName="DestroyedRocket"+QString::number(Destroyed-1);
                DestroyedNames[Destroyed-1]=play::findChild<QLabel*>(DestroyedName);
                DestroyedNames[Destroyed-1]->show();
                DestroyedNames[Destroyed-1]->move(ui->Rocket0->pos());
                rocket0health=5;
                Y=rand()%500;
                ui->Rocket0->move(50,Y);
                Move(ui->Rocket0);

            }
    }
    }

}


// LEVEL 2




void play::Tank_clicked()
{
    if(DestroyedTanks==6){
        ui->Tank0->destroyed();
        ui->Tank0->hide();
        ui->Tank1->destroyed();
        ui->Tank1->hide();
        ui->Tank2->destroyed();
        ui->Tank2->hide();
        ui->Tank3->destroyed();
        ui->Tank3->hide();
        QMessageBox::warning(this,"Error","You win :)");
    }
    else{
    QPushButton *Enemy = dynamic_cast<QPushButton *>(sender());
    if(Enemy->x()>=850){
        health=health-5;
        QString text="Health: "+ QString::number(health);
        ui->label2->setText(text);
        if(health<=0){
            QMessageBox::warning(this,"Error","You lose :(");
            ui->Rocket1->destroyed();
            ui->Rocket1->hide();
            ui->Rocket0->destroyed();
            ui->Rocket0->hide();
            ui->Tank0->destroyed();
            ui->Tank0->hide();
            ui->Tank1->destroyed();
            ui->Tank1->hide();
            ui->Tank2->destroyed();
            ui->Tank2->hide();
            ui->Tank3->destroyed();
            ui->Tank3->hide();
        }
    }
    if (sender()==ui->Tank0){
        if (Javelin>0){
            tank0health=tank0health-10;
            Javelin--;
        }
        else if (NLAW>1){
            tank0health=tank0health-5;
            NLAW--;
        }
        else{
            tank0health--;
        }
    }
    if (sender()==ui->Tank1){
        if (Javelin>0){
            tank1health=tank1health-10;
            Javelin--;
        }
        else if (NLAW>0){
            tank1health=tank1health-5;
            NLAW--;
        }
        else{
            tank1health--;
        }
    }
    if (sender()==ui->Tank2){
        if (Javelin>0){
            tank2health=tank2health-10;
            Javelin--;
        }
        else if (NLAW>0){
            tank2health=tank2health-5;
            NLAW--;
        }
        else{
            tank2health--;
        }
    }
    if (sender()==ui->Tank3){
        if (Javelin>0){
            tank3health=tank3health-10;
            Javelin--;
        }
        else if (NLAW>0){
            tank3health=tank3health-5;
            NLAW--;
        }
        else{
            tank3health--;
        }
    }
    if (tank0health<=0 || tank1health<=0 || tank2health<=0 || tank3health<=0){
        coins=coins+30;
        ++DestroyedTanks;
        QString text="Coins: "+ QString::number(coins);
        ui->label->setText(text);
        Tank_Reborn();


    }
    }
}

void play::Tank_Reborn(){
    if (tank0health==0){
        if(DestroyedTanks>5){
            QString DestroyedName="DestroyedTank"+QString::number(DestroyedTanks-1);
            DestroyedNamesT[DestroyedTanks-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNamesT[DestroyedTanks-1]->show();
            DestroyedNamesT[DestroyedTanks-1]->move(ui->Tank0->pos());
            ui->Tank0->destroyed();
            ui->Tank0->hide();

        }
        else{
            QString DestroyedName="DestroyedTank"+QString::number(DestroyedTanks-1);
            DestroyedNamesT[DestroyedTanks-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNamesT[DestroyedTanks-1]->show();
            DestroyedNamesT[DestroyedTanks-1]->move(ui->Tank0->pos());
            tank0health=10;
            Y=rand()%500;
            ui->Tank0->move(100,rand()%1000);
            Move(ui->Tank0);

        }


    }
    else if (tank1health==0){
        if(DestroyedTanks>5){
            QString DestroyedName="DestroyedTank"+QString::number(DestroyedTanks-1);
            DestroyedNamesT[DestroyedTanks-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNamesT[DestroyedTanks-1]->show();
            DestroyedNamesT[DestroyedTanks-1]->move(ui->Tank1->pos());
            ui->Tank1->destroyed();
            ui->Tank1->hide();

        }
        else{
            QString DestroyedName="DestroyedTank"+QString::number(DestroyedTanks-1);
            DestroyedNamesT[DestroyedTanks-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNamesT[DestroyedTanks-1]->show();
            DestroyedNamesT[DestroyedTanks-1]->move(ui->Tank1->pos());
            tank1health=10;
            Y=rand()%500;
            ui->Tank1->move(100,rand()%1000);
            Move(ui->Tank1);

        }
    }
    else if (tank2health==0){
        if(DestroyedTanks>5){
            QString DestroyedName="DestroyedTank"+QString::number(DestroyedTanks-1);
            DestroyedNamesT[DestroyedTanks-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNamesT[DestroyedTanks-1]->show();
            DestroyedNamesT[DestroyedTanks-1]->move(ui->Tank2->pos());
            ui->Tank2->destroyed();
            ui->Tank2->hide();

        }
        else{
            QString DestroyedName="DestroyedTank"+QString::number(DestroyedTanks-1);
            DestroyedNamesT[DestroyedTanks-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNamesT[DestroyedTanks-1]->show();
            DestroyedNamesT[DestroyedTanks-1]->move(ui->Tank2->pos());
            tank2health=10;
            Y=rand()%500;
            ui->Tank2->move(100,rand()%1000);
            Move(ui->Tank2);

        }
    }
    else if (tank3health==0){
        if(DestroyedTanks>5){
            QString DestroyedName="DestroyedTank"+QString::number(DestroyedTanks-1);
            DestroyedNamesT[DestroyedTanks-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNamesT[DestroyedTanks-1]->show();
            DestroyedNamesT[DestroyedTanks-1]->move(ui->Tank3->pos());
            ui->Tank3->destroyed();
            ui->Tank3->hide();

        }
        else{
            QString DestroyedName="DestroyedTank"+QString::number(DestroyedTanks-1);
            DestroyedNamesT[DestroyedTanks-1]=play::findChild<QLabel*>(DestroyedName);
            DestroyedNamesT[DestroyedTanks-1]->show();
            DestroyedNamesT[DestroyedTanks-1]->move(ui->Tank3->pos());
            tank3health=10;
            Y=rand()%500;
            ui->Tank3->move(100,rand()%1000);
            Move(ui->Tank3);

        }
    }
    }




void play::on_pushButton_2_clicked()
{
    QPushButton *rockets[2];
    for(int i=0;i<2;i++){
        QString butName="Rocket"+QString::number(i);
        rockets[i]=play::findChild<QPushButton*>(butName);
        rockets[i]->setFlat(true);
        rockets[i]->show();

        Move(rockets[i]);
    }
}


void play::on_pushButton_clicked()
{
    QPushButton *tanks[4];
    for(int i=0;i<4;i++){
        QString butName="Tank"+QString::number(i);
        tanks[i]=play::findChild<QPushButton*>(butName);
        tanks[i]->setFlat(true);
        tanks[i]->show();

        if(level==2){
        Move(tanks[i]);
        }
    }
}


void play::on_pushButton_3_clicked()
{
    ui->pushButton_4->show();
    if (shop==0){
        ui->comboBox->show();
        ui->pushButton_4->show();
        ui->pushButton_3->setText("Close Shop");
        shop=1;
    }
    else if (shop==1){
        ui->comboBox->hide();
        ui->pushButton_4->hide();
        ui->pushButton_3->setText("Shop");
        shop=0;
    }
}


void play::on_pushButton_4_clicked()
{
    if(ui->comboBox->currentText()=="Javelin (80)" && coins>=80){
        Javelin++;
        coins=coins-80;
        QString text="Coins: "+ QString::number(coins);
        ui->label->setText(text);
    }

    else if(ui->comboBox->currentText()=="NLAW(60)" && coins>=60){
        NLAW++;
        coins=coins-60;
        QString text="Coins: "+ QString::number(coins);
        ui->label->setText(text);
    }
    else if((ui->comboBox->currentText()=="Javelin (80)" && coins<80) ||(ui->comboBox->currentText()=="NLAW(60)" && coins<60)){
        QMessageBox::warning(this,"Error","Not enough coins");
    }
}

