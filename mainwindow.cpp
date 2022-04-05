#include "mainwindow.h"
#include "ZorkUL.h"
#include "item.h"
#include "ui_mainwindow.h"
#include <QPixmap>
//global
string word = "COLOR";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->image_label->setScaledContents(true);
    QPixmap pic1(":/resources/images/centre.png");
    ui->lineEdit->setVisible(false);
    ui->image_label->setPixmap(pic1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Buttons
void MainWindow::on_pushButton_3_clicked() //North
{
    if(!gameWon){
        zorkUL.goRoom("north");
        updateGraphics();
    }

}



void MainWindow::on_pushButton_clicked()//west
{
    if(!gameWon){
        zorkUL.goRoom("west");
        updateGraphics();
    }
}


void MainWindow::on_pushButton_4_clicked() //east
{
    if(!gameWon){
        zorkUL.goRoom("east");
        updateGraphics();
    }
}


void MainWindow::on_pushButton_2_clicked() //south
{
    if(!gameWon){
        zorkUL.goRoom("south");
        updateGraphics();
    }
}

void MainWindow::updateGraphics(){
    if(zorkUL.getRoom() == "Centre"){
        QPixmap pic(":/resources/images/centre.png");
        ui->outputLabel->setText(QString::fromStdString("You're in a dimly lit industrial room.\nAcetylene lights flicker above as they reveal\nmachinery in the room. The whirring of fans\ndraw the attention of your ear.\n\nTheres an exit in every direction"));
        ui->image_label->setPixmap(pic);
    }
    else if(zorkUL.getRoom() == "West"){
        QPixmap pic(":/resources/images/west.png");
        ui->outputLabel->setText(QString::fromStdString("Dusk glows through the tall windows as the sun\nsets. A red carpet leads you to a very \nimportant looking table. \nAs you walk up to it, you notice a few pens and \na half empty mug with NUMBER TWO CHIEF\nwritten on it\n\nThe only door in this room\nis the one you came through"));
        ui->image_label->setPixmap(pic);
    }
    else if(zorkUL.getRoom() == "East"){
        QPixmap pic(":/resources/images/east.png");
        ui->outputLabel->setText(QString::fromStdString("This door reveals a deep dark tunnel leading you.. \nSomewhere\nThere a bit of natural light seeping through \nthe cracks\nEven I'm too scared to go there.. \n\nTurn around"));
        ui->image_label->setPixmap(pic);
    }
    else if(zorkUL.getRoom() == "North"){
        QPixmap pic(":/resources/images/north.png");
        ui->outputLabel->setText(QString::fromStdString("The north door reveals a nice study.\nThe yellow light shows a broken clock on the wall.\nThere's an old radio in the corner\n\nThe doors lead east, west and from \nwence you came."));
        ui->image_label->setPixmap(pic);
    }
    else if(zorkUL.getRoom() == "South"){
        QPixmap pic(":/resources/images/south.png");
        ui->outputLabel->setText(QString::fromStdString("Industrial whirring continues \nas you enter the south door.\nThe same artificial flickering lights fill the room.\nThe noises seem to be coming from the \nwashing machine.\n\nThe doors lead back, east and west."));
        ui->image_label->setPixmap(pic);
    }
    else if(zorkUL.getRoom() == "North-West"){
        QPixmap pic(":/resources/images/hintroom.png");
        ui->outputLabel->setText(QString::fromStdString("A warm skylight reveals the old bar.\nYou can still smell the booze.\nThough the bar seemed abandoned...\nfor a while now\nThere's a note at the bar.\n\nOnly one way out."));
        ui->image_label->setPixmap(pic);
    }
    else if(zorkUL.getRoom() == "North-East"){
        QPixmap pic(":/resources/images/keypad.png");
        ui->outputLabel->setText(QString::fromStdString("There's a console in this room?\n\nHow strange?"));
        ui->image_label->setPixmap(pic);
    }
    else if(zorkUL.getRoom() == "key"){
        QPixmap pic(":/resources/images/safe.png");
        ui->outputLabel->setText(QString::fromStdString("This old room is so..\nbroken.. \nEven by the standards of this building.\nThere's a box in the corner\n\nLook at it?\n\nEast is only exit. "));
        ui->image_label->setPixmap(pic);
    }
    else if(zorkUL.getRoom() == "Door"){
        QPixmap pic(":/resources/images/door.png");
        ui->outputLabel->setText(QString::fromStdString("There's a large mechanical door in this dim room\n\nCould it lead to escape"));
        ui->image_label->setPixmap(pic);
    }
}



void MainWindow::on_pushButton_5_clicked() //interact button
{
    if(zorkUL.getRoom() == "North-East" && !hasCode && hasLookedAtKey) {
        ui->lineEdit->setVisible(true);
        if(attempts > 5){
            attempts = 0;
        }
        ui->outputLabel->setText(QString::fromStdString("Please enter a 5 letter word\nYou have 6 attempts."));
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
    else if(zorkUL.getRoom() == "Door" && hasKey && !gameWon) {
        ui->outputLabel->setText(QString::fromStdString("The Door swings open and you're free \n\nYou Win!"));
        QPixmap pic(":/resources/images/out.png");
        ui->image_label->setPixmap(pic);
        ui->pushButton_5->setText("End?");
        gameWon = true;
    }
    else if(zorkUL.getRoom() == "North-West") {
        ui->outputLabel->setText(QString::fromStdString("There's a wrong way to spell colour?\n\n\nThe rest of the paper is incoherent scribbles."));
    }
    else if(gameWon){
        exit(0);
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

    if(attempts > 5){
        ui->outputLabel->setText(QString::fromStdString("The keypad beeped unhappily.\n\nYou should try again."));
        word = "CHIEF";
        ui->lineEdit->setVisible(false);
        return;
    }
    if(arg1.length() == 5) {
        string output = "Your guess: " + arg1.toUpper().toStdString() + "\n\n";
        string input = arg1.toUpper().toStdString();
        wordleGameWon = true;
        for (int i = 0; i < 5; i++){
            if(input.at(i) == word.at(i)){ //checks if letter match letter in relative position
                output += "Letter at Position " + std::to_string(i+1) + " is correct\n";
            } else if (word.find(input.at(i)) != std::string::npos) {//checks if letter is contained in word
                output += "Letter at Position " + std::to_string(i+1) +  " is in incorrect position\n";
                wordleGameWon = false;
            } else {
                output += "Letter at Position " + std::to_string(i+1) + " not found\n";
                wordleGameWon = false;
            }

        }

        if(wordleGameWon){
            if(word == "COLOR"){
            output += "\nYou heard a click in the room with the safe.\n\n\nWhy does this room not have colour?";
            } else {
                output += "\nYou heard a click in the room with the safe.\n\n\nWhat a terrible password.";
            }
            ui->lineEdit->setVisible(false);
            hasCode = true;
        } else {
            attempts++;
            ui->lineEdit->setText(QString::fromStdString(""));
        }
        ui->outputLabel->setText(QString::fromStdString(output));
    }
}

