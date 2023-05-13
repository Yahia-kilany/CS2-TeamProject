#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "viewcorpus.h"
#include <QString>
#include <QTime>
#include <chrono>
MainWindow::MainWindow (QWidget* parent)
    : QMainWindow (parent) , ui (new Ui::MainWindow)
{
    Document doc;
    ui->setupUi (this);
}

MainWindow::~MainWindow ()
{
    delete ui;
}
void MainWindow::setCorpus (Corpus C)
{
    corpus = C;
}
void MainWindow::setTestDoc (Document doc)
{
    testdoc = doc;
}

void MainWindow::on_BruteForce_clicked ()
{
    ui->results->setText ("");
    if (testdoc.getContent () == "")
    {
        ui->results->setText ("error: testdoc is empty\n");
        return;
    }
    QMap<QString , double> matches;
    auto start = chrono::high_resolution_clock::now ();
    matches = bruteForceMatcher.match (testdoc , corpus);
    auto end = chrono::high_resolution_clock::now ();
    double time = chrono::duration_cast<chrono::nanoseconds>(end - start).count ();
    if (matches.empty ()) {
        ui->results->setText ("The test document is not plagarised \n");
        ui->results->setText (ui->results->text () + "The algorithm took: " + QString::number (time) + "nanoseconds\n" + "The algorithm occubied: " + QString::number (bruteForceMatcher.getMemoryUsage ()) + " bytes\n");
        return;
    }
    ui->results->setText ("The test document was plagarised from the following documents from the corpus \n");
    QMap<QString , double>::iterator i;
    for (i = matches.begin (); i != matches.end (); ++i) {
        ui->results->setText (ui->results->text () + i.key () + " with similarity of " + QString::number (i.value (),'f',2) + "%\n");
    }
    ui->results->setText (ui->results->text () + "The algorithm took: " + QString::number (time) + " nanoseconds\n" + "The algorithm occubied: " + QString::number (bruteForceMatcher.getMemoryUsage ()) + "\n");
}


void MainWindow::on_addTest_clicked ()
{
    testdoc.setTitle ("test document");
    testdoc.setContent (ui->lineEdit->text ());
    ui->lineEdit->setText ("");
}


void MainWindow::on_RabinKarp_clicked ()
{
    ui->results->setText ("");
    if (testdoc.getContent () == "")
    {
        ui->results->setText ("error: testdoc is empty\n");
        return;
    }
    QMap<QString , double> matches;
    auto start = chrono::high_resolution_clock::now ();
    matches = rabinKarpMatcher.match (testdoc , corpus);
    auto end = chrono::high_resolution_clock::now ();
    double time = chrono::duration_cast<chrono::nanoseconds>(end - start).count ();
    if (matches.empty ()) {
        ui->results->setText ("The test document is not plagarised \n");
        ui->results->setText (ui->results->text () + "The algorithm took: " + QString::number (time , 'f' , 2) + "nanoseconds\n" + "The algorithm occubied: " + QString::number (rabinKarpMatcher.getMemoryUsage ()) + " bytes\n");
        return;
    }
    ui->results->setText ("The test document was plagarised from the following documents from the corpus \n");
    QMap<QString , double>::iterator i;
    for (i = matches.begin (); i != matches.end (); ++i) {
        ui->results->setText (ui->results->text () + i.key () + " with similarity of " + QString::number (i.value (),'f',2) + "%\n");
    }
    ui->results->setText (ui->results->text () + "The algorithm took: " + QString::number (time) + " nanoseconds\n" + "The algorithm occubied: " + QString::number (bruteForceMatcher.getMemoryUsage ()) + "\n");
}

void MainWindow::on_KMP_clicked ()
{
    ui->results->setText ("");
    if (testdoc.getContent () == "")
    {
        ui->results->setText ("error: testdoc is empty\n");
        return;
    }
    QMap<QString , double> matches;
    auto start = chrono::high_resolution_clock::now ();
    matches = kmpmatcher.match (testdoc , corpus);
    auto end = chrono::high_resolution_clock::now ();
    double time = chrono::duration_cast<chrono::nanoseconds>(end - start).count ();
    if (matches.empty ()) {
        ui->results->setText ("The test document is not plagarised \n");
        ui->results->setText (ui->results->text () + "The algorithm took: " + QString::number (time ) + "nanoseconds\n" + "The algorithm occubied: " + QString::number (kmpmatcher.getMemoryUsage ()) + " bytes\n");
        return;
    }
    ui->results->setText ("The test document was plagarised from the following documents from the corpus \n");
    QMap<QString , double>::iterator i;
    for (i = matches.begin (); i != matches.end (); ++i) {
        ui->results->setText (ui->results->text () + i.key () + " with similarity of " + QString::number (i.value (),'f',2) + "%\n");
    }
    ui->results->setText (ui->results->text () + "The algorithm took: " + QString::number (time ) + " nanoseconds\n" + "The algorithm occubied: " + QString::number (bruteForceMatcher.getMemoryUsage ()) + "\n");
}


void MainWindow::on_BooyerMoore_clicked ()
{
    ui->results->setText ("");
    if (testdoc.getContent () == "")
    {
        ui->results->setText ("error: testdoc is empty\n");
        return;
    }
    QMap<QString , double> matches;
    auto start = chrono::high_resolution_clock::now ();
    matches = booyerMooreMatcher.match (testdoc , corpus);
    auto end = chrono::high_resolution_clock::now ();
    double time = chrono::duration_cast<chrono::nanoseconds>(end - start).count ();
    if (matches.empty ()) {
        ui->results->setText ("The test document is not plagarised \n");
        ui->results->setText (ui->results->text () + "The algorithm took: " + QString::number (time) + "nanoseconds\n" + "The algorithm occubied: " + QString::number (booyerMooreMatcher.getMemoryUsage ()) + " bytes\n");
        return;
    }
    ui->results->setText ("The test document was plagarised from the following documents from the corpus \n");
    QMap<QString , double>::iterator i;
    for (i = matches.begin (); i != matches.end (); ++i) {
        ui->results->setText (ui->results->text () + i.key () + " with similarity of " + QString::number (i.value (),'f',2) + "%\n");
    }
    ui->results->setText (ui->results->text () + "The algorithm took: " + QString::number (time ) + " nanoseconds\n" + "The algorithm occubied: " + QString::number (bruteForceMatcher.getMemoryUsage ()) + "\n");
}


void MainWindow::on_VeiwCorpus_clicked ()
{
    corpuswindow = new ViewCorpus ();
    corpuswindow->setCorpus (corpus);
    corpuswindow->setTestDoc (testdoc);
    corpuswindow->show ();
    this->close ();
}


void MainWindow::on_addToCorpus_clicked ()
{
    Document doc;
    doc.setTitle ("corpusDoc#" + QString::number (corpus.getDocuments ().size () + 1));
    doc.setContent (ui->lineEdit->text ());
    ui->lineEdit->setText ("");
    corpus.addDocument (doc);
}

