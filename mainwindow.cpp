#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player=new QMediaPlayer(this);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SliderProgress_sliderMoved(int position)
{
player->setPosition(position);
}

void MainWindow::on_SliderVolume_sliderMoved(int position)
{
player->setVolume(position);
}

void MainWindow::on_pushButton_clicked()
{
//Load the file
    player->setMedia(QUrl::fromLocalFile(QFileInfo("C:/Users/Valued Customer/Documents/MyPlayer/moonlight.mp3").absoluteFilePath()));
    player->play();
    qDebug()<<player->errorString();
}

void MainWindow::on_pushButton_2_clicked()
{
player->stop();
}

void MainWindow::on_positionChanged(qint64 position)
{
ui->SliderProgress->setValue(position);
}

void MainWindow::on_durationChanged(qint64 position)
{
ui->SliderProgress->setMaximum(position);
}
