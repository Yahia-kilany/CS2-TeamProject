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
    void setTestDoc(Document doc);
    ~ViewCorpus();

private slots:

    void on_Return_clicked();

    void on_Next_clicked();

    void on_back_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ViewCorpus *ui;
    Document testdoc;
    Corpus corpus;
    int i=0;
    MainWindow* main;
};

#endif // VIEWCORPUS_H
