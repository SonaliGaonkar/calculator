#include "calculators.h"
#include "ui_calculators.h"
#include<QFile>
#include<math.h>
#include<QApplication>
#include "support.h"

using namespace std;
double calcVal =0;

calculators::calculators(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::calculators)

{
    ui->setupUi(this);

    ui->mainDisplay->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i = 0; i< 10; ++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = calculators::findChild<QPushButton *>(butName);

        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(numPressed()));
    }
    connect(ui->Add, SIGNAL(released()), this,
            SLOT(mathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this,
            SLOT(mathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this,
            SLOT(mathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this,
            SLOT(mathButtonPressed()));
    connect(ui->Equal, SIGNAL(released()), this,
            SLOT(equalButtonPressed()));

    connect(ui->Exponent, SIGNAL(released()), this,
            SLOT(mathButtonPressed()));

    connect(ui->Clear, SIGNAL(released()), this,
            SLOT(clear()));

      connect(ui->decimal, SIGNAL(released()), this,
             SLOT(decimal()));
       connect(ui->change_sign, SIGNAL(released()), this,
             SLOT(changeSign()));;
      connect(ui->T1, SIGNAL(released()), this,
             SLOT(theme1()));
      connect(ui->T2, SIGNAL(released()), this,
             SLOT(theme2()));
      connect(ui->T3, SIGNAL(released()), this,
             SLOT(theme3()));
      connect(ui->openbracket, SIGNAL(released()), this,
             SLOT(addBrackets()));
      connect(ui->closebracket, SIGNAL(released()), this,
                                       SLOT(addBrackets()));
  }

calculators::~calculators()
{
    delete ui;
}
void calculators::setText()
{
    QPushButton *button=(QPushButton*)sender();
 ui->mainDisplay->setText(ui->mainDisplay->text()+' '+button->text());
}

void calculators::numPressed()
   {
        string exp=ui->mainDisplay->text().toStdString();
        size_t length=exp.length();
        if(exp[length-1]=='+'||exp[length-1]=='*'||exp[length-1]=='-'||exp[length-1]=='/' ||exp[length-1]=='^' || exp[length-1]=='(')
           setText();
        else
          setText();
    }


void calculators::mathButtonPressed()
{
     setText();
}

void calculators::equalButtonPressed()
{
    ui->subDisplay->setText(ui->mainDisplay->text());
    string expression=ui->mainDisplay->text().toStdString();
    long long result = evaluate  (expression);
    ui->mainDisplay->setText(QString::number(result,'g',15));
}

void calculators::clear()
{
    QString mainDisplayVal = "";
    ui-> mainDisplay->setText( mainDisplayVal);
    QString subDisplay = "";
     ui->subDisplay->setText(subDisplay);
}

void calculators ::changeSign()
{
         QString text = ui->mainDisplay->text();
         double value = text.toDouble();

         if (value > 0.0){
             text.prepend(tr("-"));
         }else if (value <0.0){
             text.remove(0,1);
         }
       ui->mainDisplay->setText(text);
}

void calculators ::decimal()
{
     ui->mainDisplay->setText(ui->mainDisplay->text() + ".");
}

void calculators::addBrackets(){
    QPushButton*button =(QPushButton*)sender();
   setText();// ui->mainDisplay->setText(ui->mainDisplay->text()+' '+button->text());
}

void calculators::theme1()
{
    QFile file ("C:/Users/Sonali Goenkar/Desktop/New folder/calculator/Adaptic.qss");
    file.open(QFile::ReadOnly);
    QString stylesheets = QLatin1String(file.readAll());
   setStyleSheet(stylesheets);
}

void calculators ::theme2()
{
 QFile fib("C:/Users/Sonali Goenkar/Desktop/New folder/calculator/fibers.qss");
   fib.open(QFile::ReadOnly);
   QString stylesheet = QLatin1String(fib.readAll());
   setStyleSheet(stylesheet);
}

void calculators ::theme3()
{
 QFile fib("C:/Users/Sonali Goenkar/Desktop/New folder/calculator/Irrorater.qss");
   fib.open(QFile::ReadOnly);
   QString stylesheet = QLatin1String(fib.readAll());
   setStyleSheet(stylesheet);
}
