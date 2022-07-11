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
                SLOT(NumPressed()));
    }
    connect(ui->Add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Equal, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));

    connect(ui->Exponent, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui->Clear, SIGNAL(released()), this,
            SLOT(C()));

      connect(ui->decimal, SIGNAL(released()), this,
             SLOT(decimal()));
       connect(ui->change_sign, SIGNAL(released()), this,
             SLOT(change_sign()));;
      connect(ui->T1, SIGNAL(released()), this,
             SLOT(T1()));
      connect(ui->T2, SIGNAL(released()), this,
             SLOT(T2()));
      connect(ui->T3, SIGNAL(released()), this,
             SLOT(T3()));
      connect(ui->openbracket, SIGNAL(released()), this,
             SLOT(addbrackets()));
      connect(ui->closebracket, SIGNAL(released()), this,
                                       SLOT(addbrackets()));
  }

calculators::~calculators()
{
    delete ui;
}

void calculators::NumPressed()
{

    QPushButton *button=(QPushButton*)sender();
    if(ui->mainDisplay->text()=="0"){
        ui->mainDisplay->setText(button->text());
    }else{
        string exp=ui->mainDisplay->text().toStdString();
        size_t length=exp.length();
        if(exp[length-1]=='+'||exp[length-1]=='*'||exp[length-1]=='-'||exp[length-1]=='/' ||exp[length-1]=='^' || exp[length-1]=='(')
            ui->mainDisplay->setText(ui->mainDisplay->text()+' '+button->text());
        else
            ui->mainDisplay->setText(ui->mainDisplay->text()+button->text());
    }

}
void calculators::MathButtonPressed()
{
    QPushButton *button =(QPushButton*)sender();
    ui->mainDisplay->setText(ui->mainDisplay->text()+' '+button->text());
};
void calculators::EqualButtonPressed()
{
    ui->subDisplay->setText(ui->mainDisplay->text());
    string expression=ui->mainDisplay->text().toStdString();
    long long result = evaluate  (expression);
    ui->mainDisplay->setText(QString::number(result,'g',15));
}

void calculators::C()
{
    QString mainDisplayVal  = "0";
    ui->mainDisplay ->setText(mainDisplayVal);
    mainDisplayVal = "";
    ui-> mainDisplay->setText( mainDisplayVal  );
    m_firstNum = 0;
    m_secondNum = 0;
    m_result = 0;
    QString subDisplay = "";
     ui->subDisplay->setText(subDisplay);
}
void calculators ::change_sign()
{

  //   QPushButton *button = (QPushButton*)sender();
    /* if( button->text()=="+/-")
     {
         m_result = ui->mainDisplay->text().toDouble();
         m_result =m_result * -1;*/
         string expression=ui->mainDisplay->text().toStdString();
         long long result = evaluate(expression);
         ui->mainDisplay->setText(QString::number(result,'g',15));



     /*double labelNumber;
     QString newLabel;



         labelNumber = ui->mainDisplay->text().toDouble();
         labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->mainDisplay->setText(newLabel);*/
}



void calculators ::decimal()
{
     ui->mainDisplay->setText(ui->mainDisplay->text() + ".");
}

void calculators::addbrackets(){
    QPushButton*button =(QPushButton*)sender();
    ui->mainDisplay->setText(ui->mainDisplay->text()+' '+button->text());
}

void calculators::T1()
{
    QFile file ("C:/Users/Sonali Goenkar/Desktop/New folder/calculator/Adaptic.qss");
    file.open(QFile::ReadOnly);
    QString stylesheets = QLatin1String(file.readAll());
   setStyleSheet(stylesheets);
   }

void calculators ::T2()
{
 QFile fib("C:/Users/Sonali Goenkar/Desktop/New folder/calculator/fibers.qss");
   fib.open(QFile::ReadOnly);
   QString stylesheet = QLatin1String(fib.readAll());
   setStyleSheet(stylesheet);
}
void calculators ::T3()
{
 QFile fib("C:/Users/Sonali Goenkar/Desktop/New folder/calculator/Irrorater.qss");
   fib.open(QFile::ReadOnly);
   QString stylesheet = QLatin1String(fib.readAll());
   setStyleSheet(stylesheet);

}

