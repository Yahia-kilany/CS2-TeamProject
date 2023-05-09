#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QElapsedTimer"
#include "viewcorpus.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setCorpus(Corpus C)
{
    corpus=C;
}


void MainWindow::on_BruteForce_clicked()
{
    if(testdoc.getContent().isEmpty())
    {
        ui->results->setText("error: testdoc is empty\n");
                return;
    }
    QElapsedTimer Timer;
    Timer.start();
    QVector<QString> results= bruteForceMatcher.match(testdoc,corpus);
    auto time=Timer.elapsed();
    if(results.empty()){
        ui->results->setText("The test document is not plagarised \n");
        ui->results->setText(ui->results->text()+"The algorithm took: "+QString::number(time)+"milliseconds\n"+"The algorithm occubied: "+QString::number(bruteForceMatcher.getMemoryUsage())+" bytes\n");
        return;
    }
    ui->results->setText("The test document was plagarised from the following documents from the corpus \n");
    for(QVector<QString>::iterator itr=results.begin();itr!=results.end();itr++)
    {
        ui->results->setText(ui->results->text()+*itr+"\n");
    }
    ui->results->setText(ui->results->text()+"The algorithm took: "+QString::number(time)+"milliseconds\n"+"The algorithm occubied: "+QString::number(bruteForceMatcher.getMemoryUsage())+"\n");
}


void MainWindow::on_addTest_clicked()
{
    testdoc.setTitle("test document");
    testdoc.setContent(ui->lineEdit->text());
}


void MainWindow::on_RabinKarp_clicked()
{
    if(testdoc.getContent().isEmpty())
    {
        ui->results->setText("error: testdoc is empty\n");
                return;
    }
    QElapsedTimer Timer;
    Timer.start();
    QVector<QString> results= rabinKarpMatcher.match(testdoc,corpus);
    auto time=Timer.elapsed();
    if(results.empty()){
        ui->results->setText("The test document is not plagarised \n");
        ui->results->setText(ui->results->text()+"The algorithm took: "+QString::number(time)+"milliseconds\n"+"The algorithm occubied: "+QString::number(rabinKarpMatcher.getMemoryUsage())+" bytes\n");
        return;
    }
    ui->results->setText("The test document was plagarised from the following documents from the corpus \n");
    for(QVector<QString>::iterator itr=results.begin();itr!=results.end();itr++)
    {
        ui->results->setText(ui->results->text()+*itr+"\n");
    }
    ui->results->setText(ui->results->text()+"The algorithm took: "+QString::number(time)+"milliseconds\n"+"The algorithm occubied: "+QString::number(rabinKarpMatcher.getMemoryUsage())+" bytes\n");
}


void MainWindow::on_KMP_clicked()
{

    if(testdoc.getContent().isEmpty())
    {
        ui->results->setText("error: testdoc is empty\n");
        return;
    }
    QElapsedTimer Timer;
    Timer.start();
    QVector<QString> results= kmpmatcher.match(testdoc,corpus);
    auto time=Timer.elapsed();
    if(results.empty()){
        ui->results->setText("The test document is not plagarised \n");
        ui->results->setText(ui->results->text()+"The algorithm took: "+QString::number(time)+"milliseconds\n"+"The algorithm occubied: "+QString::number(kmpmatcher.getMemoryUsage())+" bytes\n");
        return;
    }
    ui->results->setText("The test document was plagarised from the following documents from the corpus \n");
    for(QVector<QString>::iterator itr=results.begin();itr!=results.end();itr++)
    {
        ui->results->setText(ui->results->text()+*itr+"\n");
    }
    ui->results->setText(ui->results->text()+"The algorithm took: "+QString::number(time)+"milliseconds\n"+"The algorithm occubied: "+QString::number(kmpmatcher.getMemoryUsage())+" bytes\n");
}



void MainWindow::on_BooyerMoore_clicked()
{
    if(testdoc.getContent().isEmpty())
    {
        ui->results->setText("error: testdoc is empty\n");
        return;
    }
    QElapsedTimer Timer;
    Timer.start();
    QVector<QString> results= booyerMooreMatcher.match(testdoc,corpus);
    auto time=Timer.elapsed();
    if(results.empty()){
        ui->results->setText("The test document is not plagarised \n");
        ui->results->setText(ui->results->text()+"The algorithm took: "+QString::number(time)+"milliseconds\n"+"The algorithm occubied: "+QString::number(booyerMooreMatcher.getMemoryUsage())+" bytes\n");
        return;
    }
    ui->results->setText("The test document was plagarised from the following documents from the corpus \n");
    for(QVector<QString>::iterator itr=results.begin();itr!=results.end();itr++)
    {
        ui->results->setText(ui->results->text()+*itr+"\n");
    }
    ui->results->setText(ui->results->text()+"The algorithm took: "+QString::number(time)+"milliseconds\n"+"The algorithm occubied: "+QString::number(booyerMooreMatcher.getMemoryUsage())+" bytes\n");
}


void MainWindow::on_VeiwCorpus_clicked()
{
    corpuswindow= new ViewCorpus();
    corpuswindow->setCorpus(corpus);
    corpuswindow->show();
    this->close();
}

