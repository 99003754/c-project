#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <QString>
#include <QLabel>
#include "display.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this,SLOT(UpdateTime()));
    timer_1s->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTime()
{
    //ui->lbl_time->setText("hello");
    display obj;
            int16_t value;

            int16_t mask=3;
            int16_t mask1=2040;
            int16_t mask2=8192;
            int16_t data_value=0;
            int16_t int1,int2;
            int data=0;

                cout<<endl;
               value = obj.receieve();

                if((value&mask)==1)
            {
               cout<<"Controller data"<<endl;
               data_value=mask1&value;
               int1 = data_value/8;
               QString res = QString::number(int1);

               ui->label_3->setText(res);
                ui->label_4->setText("Ack  not req");
               if((value&mask2)==8192)
               {
                   ui->label_4->setText("Ack sent");
                   send("0111111111111111");
               }

            }

                if((value&mask)==2)
            {
               cout<<"Sensor data"<<endl;
               data_value=mask1&value;
               cout<<data_value/8;
               int2 = data_value/8;

                 QString res1 = QString::number(int2);
               ui->label->setText(res1);
                if(int2>0 && int2 <100)
                    ui->label_5->setText("A");
                else if(int2>=100 && int2 <200)
                    ui->label_5->setText("B");
                else {
                    ui->label_5->setText("C");
                }

            }
    //ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}
