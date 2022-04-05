#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include "item.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateText(QString str);




private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void updateGraphics();

    void on_lineEdit_textChanged(const QString &arg1);

private:


    bool hasCode = false; //allows you to pick up key
    bool hasKey = false; //allows you to open the door
    bool hasLookedAtKey = false; //if enabled will allow you to play the puzzle
    bool wordleGameWon = false;
    bool gameWon = false;
    int attempts = 0;

protected:
    Ui::MainWindow *ui;
    ZorkUL zorkUL;
};


#endif // MAINWINDOW_H
