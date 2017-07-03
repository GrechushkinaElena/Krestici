#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QSound>
#include <QMediaPlayer>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void newGame();
    void onButton00click();
    void onButton01click();
    void onButton02click();
    void onButton10click();
    void onButton11click();
    void onButton12click();
    void onButton20click();
    void onButton21click();
    void onButton22click();

private:
    Ui::MainWindow *ui;
    QString player1_name;
    QString player2_name;
    int playing_field[3][3];
    int player_turns;
    QPixmap *cross;
    QPixmap *zero;
    QIcon *icon;
    QSound *sound;
    QMediaPlayer *player;
    QMessageBox mg;

    int bt = -1;
    int bt2 = -1;
    int bt3 = -1;
    int bt4 = -1;
    int bt5 = -1;
    int bt6 = -1;
    int bt7 = -1;
    int bt8 = -1;
    int bt9= -1;

    void onButtonClick();
    void checkVictory();
    void writeResults();
};

#endif // MAINWINDOW_H
