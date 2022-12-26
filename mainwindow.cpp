#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm = QPixmap(1,1);
    pm.fill(QColor(0,0,0,0));
    setWindowIcon(QIcon(pm));
    

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = "Fail.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        qDebug("Файл открылся");
        QTextStream stream(&file);
        stream <<"                    "<< ui->comboBox->currentText() <<"   "<< ui->comboBox_2->currentText() << endl;
        stream <<"FIO PACIENT:"<< ui->lineEdit->text() << endl;
        stream <<"PATIENT'S DATE OF BIRTH:"<< ui->dateEdit->text() << endl;
        stream <<"PATIENT'S RESIDENTIAL ADDRESS:"<< ui->lineEdit_3->text() << endl;
        stream <<"COMPLAINTS WHEN CONTACTING:"<< ui->lineEdit_4->text() << endl;
        stream <<"ANAMNESIS:"<< ui->lineEdit_5->text() << endl;
        stream <<"OBJECTIVE STATUS:"<< ui->lineEdit_6->text() << endl;
        stream <<"RECOMMENDATIONS:"<< ui->lineEdit_7->text() << endl;
        stream <<"APPOINTMENTS:"<< ui->lineEdit_8->text() << endl;
        stream <<"DIAGNOSIS:"<< ui->lineEdit_9->text() << endl;
        stream <<"TRANSFERRED DISEASES:"<< ui->lineEdit_10->text() << endl;
        stream <<"INFORMATION ABOUT VACCINATIONS MADE:"<< ui->lineEdit_11->text() << endl;
        stream <<"DURATION OF INSPECTION:"<< ui->timeEdit->text() << endl;
        stream <<"DATE OF ADMISSION:"<< ui->dateEdit_2->text() << endl;
    }
    else {
        qDebug("Файл не открылся");
        QMessageBox::critical(this,"Error","Файл не открылся");
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
}
