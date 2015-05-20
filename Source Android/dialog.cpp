#include "dialog.h"
#include "ui_dialog.h"
#include <QTextStream>
#include <QFile>
#include "QMessageBox"
#include <QTextCodec>

int QuestionNum, // порядковый номер задаваемого вопроса
RightAnswer, // номер верного ответа на текущий вопрос
Score, // количество очков (правильных ответов)
Obl, // номер области знаний
CurrentQuestion, // номер вопроса из файла (массива), который сейчас выводится
QuestionsQuantity; // общее количество загруженных из файла вопросов.

bool isAnswerChecked;

#define NUMBEROFQUESTIONS 20 // максимальное количество вопросов
QString questions[NUMBEROFQUESTIONS][9]; // массив вопросов и ответов, загружаемых из файла
// первый индекс - номер вопроса.
// второй индекс:
// 0: текст вопроса
// 1-5: текст - варианты ответов
// 6: номер верного ответа.
// 7: текст верного ответа.
// 8: если этот вопрос уже задавался в текущей игре, то "1", иначе пустая строка.

Dialog::Dialog(QWidget *parent, int obl):QDialog(parent),ui(new Ui::Dialog){

    ui->setupUi(this);
    Obl = obl;

    QString str;

    switch (obl) { // от 0 до 5
    case 0:
        str = tr("Physics");
        break;
    case 1:
        str = tr("Literature");
        break;
    case 2:
        str = tr("Geography");
        break;
    case 3:
        str = tr("Biology");
        break;
    case 4:
        str = tr("History");
        break;
    case 5:
        str = tr("Chemistry");
        break;
    default:
        break;
    }

    ui->label_Obl->setText(tr("Area: ") + str);

    QuestionNum = 0;
    Score = 0;

    // загружаем из файла в массив вопросов и ответов.
/*
#ifdef Q_OS_LINUX
    QString slash = "/";
#endif
#ifdef Q_OS_WIN32
    QString slash = "\\";
#endif
*/
    //QFile file(QApplication::applicationDirPath() + slash + QString::number(Obl) + QString(".txt"));
    QFile file(":/" + QString::number(Obl) + QString(".txt"));
    //QFile file(QString("F:\\Programming\\QT\\Anastasiya\\WheelOfKnowledge\\" + QString::number(Obl) + ".txt"));
    //QFile file(QString("C:\\Users\\key\\Desktop\\Wheel\\" + QString::number(Obl) + ".txt"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextCodec *pCodec = QTextCodec::codecForName( "UTF-8");
    QTextCodec::setCodecForLocale(pCodec);

    QTextStream stream(&file);
    stream.setCodec(pCodec);

    QString line;
    int i=0;
    do {
        for(int j=0; j<=7; j++)
        {
            line = stream.readLine();
            questions[i][j]=line;
        }
        questions[i][8]="";

        if(i>=NUMBEROFQUESTIONS-1)
            break;
        i++;
    } while (!line.isNull());

    QuestionsQuantity = i-1; // количество итераций цикла без последней, т.к. на последней цикл закончился.

    // переход к следующему вопросу
    NextQuestion();

}

void Dialog::NextQuestion()
{
    QuestionNum++;

    ui->label_QuestionNum->setText(tr("Question ") + QString::number(QuestionNum) + tr(" of 5:"));

    //CurrentQuestion = QuestionNum;
    do
    {
        CurrentQuestion = rand() % QuestionsQuantity; // генерируем случайный номер вопроса
    }
    while(questions[CurrentQuestion][8]=="1"); // Проверяем, что этот вопрос ещё не задавался в текущей игре.

    questions[CurrentQuestion][8]="1"; // устанавливаем для вопроса признак того, что он уже задавался в текущей игре.

    // вопрос
    ui->label_Question->setText(questions[CurrentQuestion][0]);

    // варианты ответов
    ui->radioButton_1->setText(questions[CurrentQuestion][1]);
    ui->radioButton_2->setText(questions[CurrentQuestion][2]);
    ui->radioButton_3->setText(questions[CurrentQuestion][3]);
    ui->radioButton_4->setText(questions[CurrentQuestion][4]);
    ui->radioButton_5->setText(questions[CurrentQuestion][5]);

    // номер правильного ответа
    RightAnswer = questions[CurrentQuestion][6].toInt();//QuestionNum; //test

    // скрываем надпись с правильным ответом.
    ui->label_CheckAnswer->setVisible(false);

    // сбрасываем признак проверки ответа
    isAnswerChecked = false;
}

void Dialog::CheckAnswer(bool ShowAnswer)
{

    // проверка правильности ответа.
    if(!isAnswerChecked) // только если ещё не было проверки (не была нажата кнопка "Проверить").
    {
        if((ui->radioButton_1->isChecked() && RightAnswer == 1)
                || (ui->radioButton_2->isChecked() && RightAnswer == 2)
                || (ui->radioButton_3->isChecked() && RightAnswer == 3)
                || (ui->radioButton_4->isChecked() && RightAnswer == 4)
                || (ui->radioButton_5->isChecked() && RightAnswer == 5))
        {
            if(ShowAnswer)
                ui->label_CheckAnswer->setText(tr("Correct!"));
            Score++; // увеличиваем количество очков.
        }
        else
        {
            if(ShowAnswer)
                ui->label_CheckAnswer->setText(tr("Wrong! ") + questions[CurrentQuestion][7]);
        }
    }
    isAnswerChecked = true;

    // показываем надпись ответа.
    if(ShowAnswer)
        ui->label_CheckAnswer->setVisible(true);
}

Dialog::~Dialog(){
    delete ui;
}

// проверка, что хотя бы один вариант выбран.
bool Dialog::CheckIfAnythingSelected()
{
    if(!(ui->radioButton_1->isChecked()
         ||ui->radioButton_2->isChecked()
         ||ui->radioButton_3->isChecked()
         ||ui->radioButton_4->isChecked()
         ||ui->radioButton_5->isChecked()))
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Please select the answer."));
        msgBox.exec();
        return false;
    }
    return true;
}

// кнопка "Далее"
void Dialog::on_pushButton_clicked()
{
    if(!CheckIfAnythingSelected())
        return;

    CheckAnswer(false);

    if(QuestionNum < 5)
        NextQuestion();
    else
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Correct answers: ") + QString::number(Score));
        msgBox.exec();

        // закрываем текущее окно, возвращаемся к первому окну с рулеткой.
        this->close();
    }
}

// кнопка "Проверить"
void Dialog::on_pushButton_Check_clicked()
{
    if(!CheckIfAnythingSelected())
        return;

    CheckAnswer(true);
}
