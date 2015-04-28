#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>

namespace Ui {
    class Dialog;
}
class Dialog : public QDialog {
    Q_OBJECT
public:
    Dialog(QWidget *parent = 0, int obl=0);
    void NextQuestion();
    void CheckAnswer(bool ShowAnswer);
    bool CheckIfAnythingSelected();
    ~Dialog();
public slots:

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Check_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
