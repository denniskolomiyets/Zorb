#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include "item.h"
#include "derived.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Flags { //Bit-Field
    unsigned char hasCode : 1;
    unsigned char hasKey : 1;
    unsigned char hasLookedAtKey : 1;
    unsigned char wordleGameWon : 1;
    unsigned char gameWon : 1;
    unsigned char hasLookedAtButton : 1;

    Flags& operator! () { //Operator Overloading
        this->hasCode = false;
        this->hasKey = false;
        this->hasLookedAtKey = false;
        this->wordleGameWon = false;
        this->gameWon = false;
        this->hasLookedAtButton = false;
        return *this;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateText(QString str);
    friend class ZorkUL; // friend



private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void updateGraphics();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_dilemaButton1_clicked();

    void on_dilemaButton2_clicked();

    void on_reset_clicked();

private:

    Flags flags;
    int attempts = 0;


protected:
    Ui::MainWindow *ui;
    ZorkUL zorkUL;
};



#endif // MAINWINDOW_H
