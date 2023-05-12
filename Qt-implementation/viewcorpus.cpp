#include "viewcorpus.h"
#include "ui_viewcorpus.h"
#include "mainwindow.h"
#include <cmath>
ViewCorpus::ViewCorpus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewCorpus)
{
    ui->setupUi(this);
  }

ViewCorpus::~ViewCorpus()
{
    delete ui;
}
void ViewCorpus::setTestDoc(Document doc)
{
    testdoc=doc;
    if(corpus.getDocuments().empty())
    {
        ui->documentTitle->setText("Error: there are no corpus documents");
        return;
    }
    ui->documentTitle->setText(corpus.getDocument(0).getTitle());
    ui->DocumentContent->setText(corpus.getDocument(0).getContent());
}
void ViewCorpus::setCorpus(Corpus C)
{
    corpus=C;
}


void ViewCorpus::on_Return_clicked()
{
    main=new MainWindow();
    main->setCorpus(corpus);
    main->setTestDoc(testdoc);
    main->show();
    this->close();
}


void ViewCorpus::on_Next_clicked()
{
    i++;
    ui->documentTitle->setText(corpus.getDocument(abs(i)%(corpus.getDocuments().size())).getTitle());
    ui->DocumentContent->setText(corpus.getDocument(abs(i)%(corpus.getDocuments().size())).getContent());

}


void ViewCorpus::on_back_clicked()
{
    i--;
    ui->documentTitle->setText(corpus.getDocument(abs(i)%(corpus.getDocuments().size())).getTitle());
    ui->DocumentContent->setText(corpus.getDocument(abs(i)%(corpus.getDocuments().size())).getContent());

}


void ViewCorpus::on_pushButton_clicked()
{

    ui->documentTitle->setText("");
    ui->DocumentContent->setText("Document deleted successfully");
}


void ViewCorpus::on_pushButton_2_clicked()
{
    if(setText.getContent().isEmpty()){
        ui->documentTitle->setText("Error:testdoc is empty");
    }
    ui->documentTitle->setText(testdoc.title);
    ui->DocumentContent->setText(testdoc.getContent());
}

