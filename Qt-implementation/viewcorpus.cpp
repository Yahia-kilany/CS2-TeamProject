#include "viewcorpus.h"
#include "ui_viewcorpus.h"
#include "mainwindow.h"
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
void ViewCorpus::setCorpus(Corpus C)
{
    corpus=C;
}

void ViewCorpus::on_pushButton_3_clicked()
{
    main=new MainWindow();
    main->setCorpus(corpus);
    main->show();
    this->close();
}

