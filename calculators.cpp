#include "calculators.h"
#include "ui_calculators.h"
#include<QFile>
#include<QApplication>
#include "support.h"
#include<math.h>
using namespace std;
double calcVal =0;


calculators::calculators(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::calculators)

{
    ui->setupUi(this);

    connect(ui->Button0, SIGNAL(released()), this,
            SLOT(Button0()));
    connect(ui->Button1, SIGNAL(released()), this,
            SLOT(Button1()));
    connect(ui->Button2, SIGNAL(released()), this,
            SLOT(Button2()));
    connect(ui->Button3, SIGNAL(released()), this,
            SLOT(Button3()));
    connect(ui->Button4, SIGNAL(released()), this,
            SLOT(Button4()));
    connect(ui->Button5, SIGNAL(released()), this,
            SLOT(Button5()));
    connect(ui->Button6, SIGNAL(released()), this,
            SLOT(Button6()));
    connect(ui->Button7, SIGNAL(released()), this,
            SLOT(Button7()));
    connect(ui->Button8, SIGNAL(released()), this,
            SLOT(Button8()));
    connect(ui->Button9, SIGNAL(released()), this,
            SLOT(Button9()));

    connect(ui->Add, SIGNAL(released()), this,
            SLOT(Add()));
    connect(ui->Subtract, SIGNAL(released()), this,
            SLOT(Subtract()));
    connect(ui->Multiply, SIGNAL(released()), this,
            SLOT(Multiply()));
    connect(ui->Divide, SIGNAL(released()), this,
            SLOT(Divide()));
    connect(ui->Exponent, SIGNAL(released()), this,
            SLOT(Exponent()));
    connect(ui->Equal, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));



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
      connect(ui->point, SIGNAL(released()), this,
                                       SLOT(point()));

  }

calculators::~calculators()
{
    delete ui;
}

void calculators:: numClicked(QString num)

    {
        if (m_mainDisplay == "0")
        {
            m_mainDisplay = num;
            ui->m_mainDisplay->setText(m_mainDisplay);
        }
        else
        {
            m_mainDisplay += num;
            ui->m_mainDisplay->setText(m_mainDisplay);
        }
    }


    void calculators::Add()
    {
        if (operatorPressed == add)
            return;
        //
        m_firstNum = m_mainDisplay.toDouble();
        operatorPressed = add;
        m_mainDisplay = "";
        ui->m_mainDisplay->setText(m_mainDisplay);

        m_subDisplay = QString::number(m_firstNum) + " + " ;
        ui->m_subDisplay->setText(m_subDisplay);
    }

    void calculators::Subtract()
    {
        if (operatorPressed == subtract)
            return;

        m_firstNum = m_mainDisplay.toDouble();
        operatorPressed = subtract;
        m_mainDisplay = "";
        ui->m_mainDisplay->setText(m_mainDisplay);

        m_subDisplay = QString::number(m_firstNum) + " - ";
        ui->m_subDisplay->setText(m_subDisplay);
    }

    void calculators::Multiply()
    {
        if (operatorPressed == multiply)
            return;
        //
        m_firstNum = m_mainDisplay.toDouble();
        operatorPressed = multiply;
        m_mainDisplay = "";
        ui->m_mainDisplay->setText(m_mainDisplay);

        m_subDisplay = QString::number(m_firstNum) + " * ";
        ui->m_subDisplay->setText(m_subDisplay);
    }

    void calculators::Divide()
    {
        if (operatorPressed == divide)
            return;
        //
        m_firstNum = m_mainDisplay.toDouble();
        operatorPressed = divide;
        m_mainDisplay = "";
        ui->m_mainDisplay->setText(m_mainDisplay);

        m_subDisplay = QString::number(m_firstNum) + " / " ;
        ui->m_subDisplay->setText(m_subDisplay);
    }
    void calculators::Exponent()
    {
        if (operatorPressed == exponent)
            return;
        //
        m_firstNum = m_mainDisplay.toDouble();
        operatorPressed = exponent;
        m_mainDisplay = "";
        ui->m_mainDisplay->setText(m_mainDisplay);

        m_subDisplay = QString::number(m_firstNum) + " ^ " ;
        ui->m_subDisplay->setText(m_subDisplay);
    }



void calculators::EqualButtonPressed()
{
    {
        if (operatorPressed == equals)
            return;

      m_secondNum = m_mainDisplay.toDouble();
       m_subDisplay = m_subDisplay+ QString::number( m_secondNum) + "  =  ";
       ui->m_subDisplay->setText(m_subDisplay);


        switch (operatorPressed)
        {
            case add:
                m_result = m_firstNum + m_secondNum;
                m_mainDisplay = QString::number(m_result);
                ui->m_mainDisplay->setText(m_mainDisplay);
                break;
            case subtract:
                m_result = m_firstNum - m_secondNum;
                m_mainDisplay = QString::number(m_result);
                ui->m_mainDisplay->setText(m_mainDisplay);
                break;
            case multiply:
                m_result = m_firstNum * m_secondNum;
                m_mainDisplay = QString::number(m_result);
                ui->m_mainDisplay->setText(m_mainDisplay);
                break;
            case divide:
                m_result = m_firstNum / m_secondNum;
                m_mainDisplay = QString::number(m_result);
                ui->m_mainDisplay->setText(m_mainDisplay);
                break;
          case exponent:
            m_result =   pow (m_firstNum , m_secondNum);
            m_mainDisplay = QString::number(m_result);
            ui->m_mainDisplay->setText(m_mainDisplay);
            break;
        }
        operatorPressed = equals;
    }


}

void calculators::C()
{
    {
        m_mainDisplay = "";
        ui->m_mainDisplay->setText(m_mainDisplay);
        m_subDisplay = "";
        ui->m_subDisplay->setText(m_subDisplay);
        m_firstNum = 0;
        m_secondNum = 0;
        m_result = 0;
    }
}

void calculators ::CE()
{
    m_mainDisplay = "0";
    ui->m_mainDisplay->setText(m_mainDisplay);
    m_subDisplay = "";
    ui->m_subDisplay->setText(m_subDisplay);
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
    ui->m_mainDisplay->setText(ui->m_mainDisplay->text()+' '+button->text());
}


void calculators::point()

{
    if (!m_mainDisplay.contains('.'))
    {
        m_mainDisplay += '.';
        ui->m_mainDisplay->setText(m_mainDisplay);
    }
}
void calculators::Button0()
{
    numClicked("0");
}
void calculators::Button1()
{
    numClicked("1");
}

void calculators::Button2()
{
    numClicked("2");
}

void calculators::Button3()
{
    numClicked("3");
}

void calculators::Button4()
{
    numClicked("4");
}

void calculators::Button5()
{
    numClicked("5");
}

void calculators::Button6()
{
    numClicked("6");
}

void calculators::Button7()
{
    numClicked("7");
}

void calculators::Button8()
{
   numClicked("8");
}

void calculators::Button9()
{
    numClicked("9");
}


