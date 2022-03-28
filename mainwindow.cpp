#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked() //North
{
    ui->outputLabel->setText(QString::fromStdString(zorkUL.goRoom("north")));
}



void MainWindow::on_pushButton_clicked()//west
{
    ui->outputLabel->setText(QString::fromStdString(zorkUL.goRoom("west")));
}


void MainWindow::on_pushButton_4_clicked() //east
{
    ui->outputLabel->setText(QString::fromStdString(zorkUL.goRoom("east")));
}


void MainWindow::on_pushButton_2_clicked() //south
{
    ui->outputLabel->setText(QString::fromStdString(zorkUL.goRoom("south")));
}

