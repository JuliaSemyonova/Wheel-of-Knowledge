#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

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
    void on_pushButton_Turn_clicked();
    void refreshRoulette();

private:
    Ui::MainWindow *ui;

protected:
    void resizeEvent ( QResizeEvent * event );
};

#endif // MAINWINDOW_H
