#include "calculators.h"
#include "ui_calculators.h"
#include<QFile>
#include<QApplication>
#include "support.h"
using namespace std;
double calcVal =0;

calculators::calculators(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::calculators)

{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
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

    connect(ui->C, SIGNAL(released()), this,
            SLOT(C()));
      connect(ui->CE, SIGNAL(released()), this,
             SLOT(CE()));
      connect(ui->T1, SIGNAL(released()), this,
             SLOT(T1()));

      connect(ui->T2, SIGNAL(released()), this,
             SLOT(T2()));
      connect(ui->T3, SIGNAL(released()), this,
             SLOT(T3()));
      connect(ui->Open, SIGNAL(released()), this,
             SLOT(addbrackets()));
      connect(ui->Close, SIGNAL(released()), this,
                                       SLOT(addbrackets()));
  }

calculators::~calculators()
{
    delete ui;
}

void calculators::NumPressed()
{

    QPushButton *button=(QPushButton*)sender();
    if(ui->Display->text()=="0"){
        ui->Display->setText(button->text());
    }else{
        string exp=ui->Display->text().toStdString();
        size_t length=exp.length();
        if(exp[length-1]=='+'||exp[length-1]=='*'||exp[length-1]=='-'||exp[length-1]=='/' ||exp[length-1]=='^'|| exp[length-1]=='(')
            ui->Display->setText(ui->Display->text()+' '+button->text());
        else
            ui->Display->setText(ui->Display->text()+button->text());
    }

}
void calculators::MathButtonPressed()
{
    QPushButton*button =(QPushButton*)sender();
    ui->Display->setText(ui->Display->text()+' '+button->text());
};
void calculators::EqualButtonPressed()
{
    ui->subDisplay->setText(ui->Display->text());
    string expression=ui->Display->text().toStdString();
    long long result = evaluate  (expression);
    ui->Display->setText(QString::number(result,'g',15));
}

void calculators::C()
{
    QString displayVal  = "0";
    ui->Display ->setText(displayVal);
    displayVal = "";
    ui-> Display->setText( displayVal  );
    m_firstNum = 0;
    m_secondNum = 0;
    m_result = 0;
    QString m_subDisplay = "";
     ui->subDisplay->setText(m_subDisplay);
}

void calculators ::CE()
{
    QString displayVal = "0";
    ui->Display->setText( displayVal);
    QString m_subDisplay = "0";
     ui->subDisplay->setText(m_subDisplay);
}
void calculators::T1()
{
    QFile file ("C:/Users/Sonali Gaonkar/Documents/calculators/Adaptic.qss");
    file.open(QFile::ReadOnly);
    QString stylesheets = QLatin1String(file.readAll());
   setStyleSheet(stylesheets);
   }
void calculators ::T2()
{
 QFile fib("C:/Users/Sonali Gaonkar/Documents/calculators/fibers.qss");
   fib.open(QFile::ReadOnly);
   QString stylesheet = QLatin1String(fib.readAll());
   setStyleSheet(stylesheet);
}
void calculators ::T3()
{
 QFile fib("C:/Users/Sonali Gaonkar/Documents/calculators/Irrorater.qss");
   fib.open(QFile::ReadOnly);
   QString stylesheet = QLatin1String(fib.readAll());
   setStyleSheet(stylesheet);

}
void calculators::addbrackets(){
    QPushButton*button =(QPushButton*)sender();
    ui->Display->setText(ui->Display->text()+' '+button->text());
}

