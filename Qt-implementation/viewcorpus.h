#ifndef VIEWCORPUS_H
#define VIEWCORPUS_H

#include <QWidget>
#include <corpusQT.h>
namespace Ui {
class ViewCorpus;
}
class MainWindow;
class ViewCorpus : public QWidget
{
    Q_OBJECT

public:
    explicit ViewCorpus(QWidget *parent = nullptr);
    void setCorpus(Corpus C);
    ~ViewCorpus();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::ViewCorpus *ui;
    Corpus corpus;
    MainWindow* main;
};

#endif // VIEWCORPUS_H
