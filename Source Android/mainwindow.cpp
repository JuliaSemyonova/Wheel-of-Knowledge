#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "time.h"
#include <QTimer>
#include <QGraphicsTextItem>

QGraphicsScene *scene; // "сцена" для отображения
int Rez, // номер выбранной области (от 0 до 5)
currentVal, // текущее значение рулетки
maxVal; // значение рулетки, до которого нужно дойти
QTimer *timer;

// функция обновления изображения рулетки
void MainWindow::refreshRoulette()
{
    // увеличиваем текущее значение рулетки
    currentVal++;
    if(currentVal < maxVal) // если не дошли до нужного сектора
        ui->dial->setValue(currentVal); // устанавливаем новое значение рулетки
    else // если дошли до нужного сектора
    {
        // создаём диалоговое окно (с вопросами)
        Dialog MyDialog(this, Rez);
        // открываем его.
        if(!MyDialog.isVisible())
            MyDialog.exec();
        timer->stop();
        ui->pushButton_Turn->setEnabled(true);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(0));

    // запускаем таймер
    ui->dial->setValue(0);
    timer = new QTimer(this);
    // сигнал от таймера подключается к слоту
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshRoulette()));

    // рисуется рулетка
    scene = new QGraphicsScene;
/*    QString apppath = QApplication::applicationDirPath();

#ifdef Q_OS_LINUX
    QString slash = "/";
#endif
#ifdef Q_OS_WIN32
    QString slash = "\\";
#endif
*/
    //scene->addPixmap(QPixmap(apppath + slash + "roulette.png"));
    scene->addPixmap(QPixmap(":/roulette.png"));

    // устанавливаем нарисованную сцену для виджета graphicsView_Wheel
    ui->graphicsView_Wheel->setScene(scene);
}

void MainWindow::resizeEvent ( QResizeEvent * event )
{
  //std::cout << "ResizeEvent" << std::endl;
  //ui->graphicsView_Wheel->fitInView(0,0,this->width(),this->height());
    ui->graphicsView_Wheel->setGeometry(0,0, this->width(), this->height() - ui->statusBar->height() - ui->pushButton_Turn->height() - 10);
    ui->dial->setGeometry(ui->graphicsView_Wheel->width()/2 - ui->dial->width()/2, ui->graphicsView_Wheel->height()/2 - ui->dial->height()/2, ui->dial->height(), ui->dial->width()); // посередине виджета GraphicsWheel.
    ui->pushButton_Turn->setGeometry(this->width()/2 - ui->pushButton_Turn->width()/2, this->height() - ui->pushButton_Turn->height() - ui->statusBar->height() - 2, ui->pushButton_Turn->width(), ui->pushButton_Turn->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Turn_clicked()
{
    // случайным образом выбирается номер области (от 0 до 5).
    Rez = int(6.0*rand()/(RAND_MAX+1.0));
    //Rez = 0;

    switch(Rez)
    {
    case 0:
        maxVal = 3;
        break;
    case 1:
        maxVal = 20;
        break;
    case 2:
        maxVal = 30;
        break;
    case 3:
        maxVal = 50;
        break;
    case 4:
        maxVal = 70;
        break;
    case 5:
        maxVal = 90;
        break;
    }

    // инициализируются значения рулетки
    currentVal=0;
    ui->dial->setValue(0);
    // запускается таймер
    timer->start(70);
    // кнопка делается недоступной на время вращения рулетки
    ui->pushButton_Turn->setEnabled(false);
}
