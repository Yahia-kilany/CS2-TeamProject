#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "CorpusQT.h"
#include "viewcorpus.h"
#include "DocumentQT.h"
#include "MatcherQT.h"
#include "BruteForceMatcherQT.h"
#include "RabinKarpMatcherQT.h"
#include "BoyerMooreMatcherQT.h"
#include "kmpMatcherQT.h"
#include <QVector>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class ViewCorpus;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget* parent = nullptr);
    ~MainWindow ();
    void setCorpus (Corpus C);
    void setTestDoc (Document doc);

private slots:
    void on_BruteForce_clicked ();

    void on_addTest_clicked ();

    void on_RabinKarp_clicked ();

    void on_KMP_clicked ();

    void on_BooyerMoore_clicked ();

    void on_VeiwCorpus_clicked ();

    void on_addToCorpus_clicked ();

private:
    Document testdoc;
    Corpus corpus;
    BruteForceMatcher bruteForceMatcher;
    RabinKarpMatcher rabinKarpMatcher;
    BoyerMooreMatcher booyerMooreMatcher;
    kmpMatcher kmpmatcher;
    ViewCorpus* corpuswindow;
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
