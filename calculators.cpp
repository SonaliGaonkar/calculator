#include "calculators.h"
#include "ui_calculators.h"

double calcVal = 0.0;
bool divTrigger = false;
bool multiTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

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

    connect(ui->Changesign, SIGNAL(released()), this,
            SLOT(ChangeNumberSign()));

    connect(ui->C, SIGNAL(released()), this,
            SLOT(C()));
      connect(ui->CE, SIGNAL(released()), this,
             SLOT(CE()));
      connect(ui->DOT, SIGNAL(released()), this,
              SLOT(DOT()));
  }

calculators::~calculators()
{
    delete ui;
}

void calculators::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble()==0)||(displayVal.toDouble()==0.0)){
        ui->Display->setText(butVal);
    }else {

        double dblNewVal = displayVal.toDouble()*10 + butVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g',16));
    }
}
void calculators::MathButtonPressed(){
    divTrigger=false;
    multiTrigger=false;
    addTrigger=false;
    subTrigger=false;
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal,"/",Qt::CaseInsensitive)==0){
        divTrigger = true;
    }    else if(QString::compare(butVal,"*",Qt::CaseInsensitive)==0){
        multiTrigger = true;
    }    else if(QString::compare(butVal,"+",Qt::CaseInsensitive)==0){
        addTrigger = true;
    }    else{
       subTrigger = true;
    }
    ui->Display->setText("");
    // Update textEdit_subdisplay
    m_subDisplay = QString::number(calcVal) + (   butVal  );
    ui->subDisplay->setText(m_subDisplay);
}
void calculators::EqualButtonPressed(){
    double solutions = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(addTrigger || subTrigger || multiTrigger|| divTrigger){
        if(addTrigger){
            solutions = calcVal + dblDisplayVal;
           } else if(subTrigger){
                solutions = calcVal - dblDisplayVal;
               } else if(multiTrigger){
                    solutions = calcVal * dblDisplayVal;
                    } else {
                        solutions = calcVal / dblDisplayVal;
        }
    }

              m_subDisplay = m_subDisplay + displayVal + " = ";
              ui->subDisplay->setText(m_subDisplay);
                ui->Display->setText(QString::number(solutions));
}

void calculators::ChangeNumberSign(){
    QString displayVal = ui->Display->text();
    QRegExp reg("[-]/[0-9.]*");
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplaySign = -1 * dblDisplayVal;
        ui->Display->setText(QString::number(dblDisplaySign));
    }
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
void calculators::DOT()
{
    QString displayVal;
   if (! displayVal.contains('.') )
    {
       displayVal += '.';
        ui-> Display ->setText( displayVal  );
    }
}

