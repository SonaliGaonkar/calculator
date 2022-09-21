﻿#include<QFile>
#include "support.h"
#include "calculators.h"
#include "ui_calculators.h"

calculators::calculators(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::calculators)
{
    ui->setupUi(this);

    QPushButton *numButtons[10];
    for(int i = 0; i< 10; ++i){
    QString butName = "Button" + QString::number(i);
    numButtons[i] = calculators::findChild<QPushButton *>(butName);

    connect(numButtons[i], SIGNAL(released()),this, SLOT(numText()));
    }
    connect(ui->Addition,    SIGNAL(released()), this, SLOT(unaryoperator()));
    connect(ui->Subtraction, SIGNAL(released()), this, SLOT(unaryoperator()));
    connect(ui->Multiply,    SIGNAL(released()), this, SLOT(unaryoperator()));
    connect(ui->Division,    SIGNAL(released()), this, SLOT(unaryoperator()));
    connect(ui->Exponent,    SIGNAL(released()), this, SLOT(unaryoperator()));
    connect(ui->openbracket, SIGNAL(released()), this, SLOT(unaryoperator()));
    connect(ui->closebracket,SIGNAL(released()), this, SLOT(unaryoperator()));
    connect(ui->decimal,     SIGNAL(released()), this, SLOT(numText()));
    connect(ui->Equal,       SIGNAL(released()), this, SLOT(equalButtonPressed()));
    connect(ui->Theme1,      SIGNAL(released()), this, SLOT(theme1()));
    connect(ui->Theme2,      SIGNAL(released()), this, SLOT(theme2()));
    connect(ui->Theme3,      SIGNAL(released()), this, SLOT(theme3()));
  }

calculators::~calculators()
{
  delete ui;
}

void calculators::numText()
{
    QPushButton *button=(QPushButton*)sender();
    ui->mainDisplay->setText(ui->mainDisplay->text() + button->text());
    ui->subDisplay->setText(ui->mainDisplay->text());
}
void calculators::unaryoperator(){

    QPushButton *button=(QPushButton*)sender();
    ui->mainDisplay->setText(ui->mainDisplay->text() +' '+ button->text() +' ');
    ui->subDisplay->setText(ui->mainDisplay->text());
}

void calculators::equalButtonPressed()
{
    std::string expression=ui->mainDisplay->text().toStdString();
    double result = evaluate(expression);
    ui->mainDisplay->setText(QString::number(result,'g',15));
}

void calculators::theme1()
{
    QFile file ("C:/Users/Sonali Gaonkar/Desktop/Qt/calculator/Adaptic.qss");
    file.open(QFile::ReadOnly);
    QString stylesheets = QLatin1String(file.readAll());
    setStyleSheet(stylesheets);
}

void calculators ::theme2()
{
    QFile fib("C:/Users/Sonali Gaonkar/Desktop/Qt/calculator/fibers.qss");
    fib.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(fib.readAll());
    setStyleSheet(stylesheet);
}

void calculators ::theme3()
{
    QFile fib("C:/Users/Sonali Gaonkar/Desktop/Qt/calculator/Irrorater.qss");
    fib.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(fib.readAll());
    setStyleSheet(stylesheet);
}
