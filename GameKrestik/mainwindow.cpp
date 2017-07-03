#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionNew_Game, SIGNAL(triggered()), this, SLOT(newGame()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButton00click()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onButton01click()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onButton02click()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(onButton10click()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(onButton11click()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(onButton12click()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(onButton20click()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(onButton21click()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(onButton22click()));

    cross = new QPixmap(":/new/image/image/cross.png");
    zero = new QPixmap(":/new/image/image/zero.png");
    sound = new QSound(":/sound/click.mp3");
    player = new QMediaPlayer();
    player->setMedia(QUrl("qrc:/sound/click.mp3"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame() {
   player_turns = 0;
   bool ok;
   player1_name = QInputDialog::getText(0, "Input name", "Input player 1 name:",
                                        QLineEdit::Normal, "", &ok);
   if (!ok || player1_name.isEmpty()) {
       player1_name = "player 1";
   }

   player2_name = QInputDialog::getText(0, "Input name", "Input player 2 name:",
                                        QLineEdit::Normal, "", &ok);
   if (!ok || player2_name.isEmpty()) {
       player2_name = "player 2";
   }

   ui->pushButton->setDisabled(false);
   ui->pushButton_2->setDisabled(false);
   ui->pushButton_3->setDisabled(false);
   ui->pushButton_4->setDisabled(false);
   ui->pushButton_5->setDisabled(false);
   ui->pushButton_6->setDisabled(false);
   ui->pushButton_7->setDisabled(false);
   ui->pushButton_8->setDisabled(false);
   ui->pushButton_9->setDisabled(false);

   ui->pushButton->setIcon(QIcon());
   ui->pushButton_2->setIcon(QIcon());
   ui->pushButton_3->setIcon(QIcon());
   ui->pushButton_4->setIcon(QIcon());
   ui->pushButton_5->setIcon(QIcon());
   ui->pushButton_6->setIcon(QIcon());
   ui->pushButton_7->setIcon(QIcon());
   ui->pushButton_8->setIcon(QIcon());
   ui->pushButton_9->setIcon(QIcon());

   QString st("Сейчас ходит игрок " + player1_name);
   ui->label->setText(st);
}

void MainWindow::checkVictory() {
    QString pl = (player_turns % 2 == 0) ? player2_name : player1_name;
    mg.setText("Победа игрока " + pl);
    if (bt == bt2 && bt2 == bt3 && bt > -1) {
        mg.show();
    } else if (bt == bt5 && bt == bt9 && bt > -1) {
        mg.show();
    } else if (bt == bt4 && bt == bt7 && bt > -1) {
        mg.show();
    } else if (bt5 == bt2 && bt5 == bt8 && bt5 > -1) {
        mg.show();
    } else if (bt5 == bt3 && bt5 == bt7 && bt5 > -1) {
        mg.show();
    } else if (bt9 == bt6 && bt9 == bt3 && bt9 > -1) {
        mg.show();
    } else if (bt9 == bt8 && bt9 == bt7 && bt9 > -1) {
        mg.show();
    }
}

void MainWindow::writeResults() { //доделать
    QFile file("results.txt");
    if(file.exists()) {
        if (!file.open(QIODevice::ReadWrite)) {

        }
    } else {
        if (!file.open(QIODevice::WriteOnly)) {

        }
    }
}

void MainWindow::onButtonClick() {
    player->play();
    if (player_turns % 2 == 1) {
        QString st("Сейчас ходит игрок " + player1_name);
        ui->label->setText(st);
        icon = new QIcon(*cross);
    } else {
        QString st("Сейчас ходит игрок " + player2_name);
        ui->label->setText(st);
        icon = new QIcon(*zero);
    }
    player_turns++;
}

void MainWindow::onButton00click() {
    ui->pushButton->setDisabled(true);
    bt = player_turns % 2;
    onButtonClick();
    ui->pushButton->setIcon(*icon);
    checkVictory();
}

void MainWindow::onButton01click() {
    ui->pushButton_2->setDisabled(true);
    bt2 = player_turns % 2;
    onButtonClick();
    ui->pushButton_2->setIcon(*icon);
    checkVictory();
}

void MainWindow::onButton02click() {
    ui->pushButton_3->setDisabled(true);
    bt3 = player_turns % 2;
    onButtonClick();
    ui->pushButton_3->setIcon(*icon);
    checkVictory();
}

void MainWindow::onButton10click() {
    ui->pushButton_4->setDisabled(true);
    bt4 = player_turns % 2;
    onButtonClick();
    ui->pushButton_4->setIcon(*icon);
    checkVictory();
}

void MainWindow::onButton11click() {
    ui->pushButton_5->setDisabled(true);
    bt5 = player_turns % 2;
    onButtonClick();
    ui->pushButton_5->setIcon(*icon);
    checkVictory();
}

void MainWindow::onButton12click() {
    ui->pushButton_6->setDisabled(true);
    bt6 = player_turns % 2;
    onButtonClick();
    ui->pushButton_6->setIcon(*icon);
    checkVictory();
}

void MainWindow::onButton20click() {
    ui->pushButton_7->setDisabled(true);
    bt7 = player_turns % 2;
    onButtonClick();
    ui->pushButton_7->setIcon(*icon);
    checkVictory();
}

void MainWindow::onButton21click() {
    ui->pushButton_8->setDisabled(true);
    bt8 = player_turns % 2;
    onButtonClick();
    ui->pushButton_8->setIcon(*icon);
    checkVictory();
}

void MainWindow::onButton22click() {
    ui->pushButton_9->setDisabled(true);
    bt9 = player_turns % 2;
    onButtonClick();
    ui->pushButton_9->setIcon(*icon);
    checkVictory();
}
