#include "mainwindow.h"
#include "ZorkUL.h"
#include "item.h"
#include "ui_mainwindow.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic1("/Users/dennis.kolomiyets/RealZorB/homeImage.jpg");
    ui->lineEdit->setVisible(false);
    ui->image_label->setPixmap(pic1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked() //North
{
    ui->outputLabel->setText(QString::fromStdString(zorkUL.goRoom("north")));
    void updateGrapics();


}



void MainWindow::on_pushButton_clicked()//west
{
    ui->outputLabel->setText(QString::fromStdString(zorkUL.goRoom("west")));
    void updateGrapics();

}


void MainWindow::on_pushButton_4_clicked() //east
{
    ui->outputLabel->setText(QString::fromStdString(zorkUL.goRoom("east")));
    void updateGrapics();

}


void MainWindow::on_pushButton_2_clicked() //south
{
    ui->outputLabel->setText(QString::fromStdString(zorkUL.goRoom("south")));
    void updateGrapics();

}



class UpText: MainWindow {
    void updateText(string str){
        ui->outputLabel->setText(QString::fromStdString(str));
    }

    void updateGraphics(){
        if(zorkUL.getRoom() == "Centre"){
            QPixmap pic("/Users/dennis.kolomiyets/RealZorB/homeImage.jpg");
            ui->image_label->setPixmap(pic);
        }
    }
};



void MainWindow::on_pushButton_5_clicked() //interact button
{
    if(zorkUL.getRoom() == "North-East" && !hasCode && hasLookedAtKey) {
        ui->lineEdit->setVisible(true);
        ui->outputLabel->setText(QString::fromStdString("Please enter a 6 letter word\nYou have 6 attempts."));
    }
    else if(zorkUL.getRoom() == "North-East" && !hasCode && !hasLookedAtKey){
        ui->outputLabel->setText(QString::fromStdString("Its a Keypad with Letters and a screen."));
    }
    else if(zorkUL.getRoom() == "key" && !hasCode ) {
        ui->outputLabel->setText(QString::fromStdString("There is a key in a glass safe. It is locked"));
        hasLookedAtKey = true;
    }
    else if(zorkUL.getRoom() == "key" && hasCode ) {
        ui->outputLabel->setText(QString::fromStdString("The Door clicked open,\nYou picked up the key"));
        hasKey = true;
    }
    else if(zorkUL.getRoom() == "Door" && !hasKey) {
        ui->outputLabel->setText(QString::fromStdString("Its a large locked door\nTheres a slot for a key."));

    }
    else if(zorkUL.getRoom() == "Door" && hasKey) {
        ui->outputLabel->setText(QString::fromStdString("The Door swings open and you're free \n\nYou Win!"));

    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    string word = "POWERS";
    if(attempts > 5){
        ui->outputLabel->setText(QString::fromStdString("YOU LOSE!"));
        ui->lineEdit->setVisible(false);
        return;
    }
    if(arg1.length() == 6) {
        string output = "Your guess: " + arg1.toUpper().toStdString() + "\n\n";
        string input = arg1.toUpper().toStdString();
        wordleGameWon = true;
        for (int i = 0; i < 6; i++){
            if(input.at(i) == word.at(i)){
                output += "Letter at Position " + std::to_string(i+1) + " is correct\n";
            } else if (word.find(input.at(i)) != std::string::npos) {
                output += "Word contains letter but is in incorrect position\n";
                wordleGameWon = false;
            } else {
                output += "Letter not found\n";
                wordleGameWon = false;
            }

        }

        if(wordleGameWon){
            output += "\nYou Win\n";
            ui->lineEdit->setVisible(false);
            hasCode = true;
        } else {
            attempts++;
            ui->lineEdit->setText(QString::fromStdString(""));
        }
        ui->outputLabel->setText(QString::fromStdString(output));
    }
}

