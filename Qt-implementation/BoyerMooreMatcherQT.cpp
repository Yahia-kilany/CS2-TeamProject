/*
CS2 project: 2- Simple palagarism detection utility using QString matching
*/
#include "BoyerMooreMatcherQT.h"
QMap<QString , double> BoyerMooreMatcher::match (const Document& testDoc , const Corpus& corpus) {
    QMap <QString , double> matches;
    QVector<QString> sentences = splitIntoSentences (testDoc);
    for (const QString& s : sentences) {
        for (const Document& d : corpus.getDocuments ()) {

            if (BoyerMooreSearch (d.getContent () , s))
            {
                if (matches.find (d.getTitle ()) == matches.end ()) {
                    matches.insert (d.getTitle () , s.size ());
                }
                else {
                    matches[d.getTitle ()] += s.size ();
                }
            }
        }

    }
    QMap<QString , double>::iterator i;
    for (i = matches.begin (); i != matches.end (); ++i) {
        double newval = ((i.value () / testDoc.getContent ().size ()) * 100);
        i.value () = newval;
    }
    return matches;
}

size_t BoyerMooreMatcher::getMemoryUsage () {
    return sizeof (*this);
}

bool BoyerMooreMatcher::BoyerMooreSearch (const QString text , const QString pattern)
{
    int s = 0 , j;
    int m = pattern.length ();
    int n = text.length ();
    QVector<int> borderPosition (m + 1) , shift (m + 1 , 0);
    preprocess_suffix (shift , borderPosition , pattern , m);
    preprocess_prefix (shift , borderPosition , pattern , m);

    while (s <= n - m) {
        j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            return true;
        }
        s += shift[j + 1];
    }

    return false;
}
void BoyerMooreMatcher::preprocess_suffix (QVector<int>& shift , QVector<int>& borderPosition , const QString& pattern , int m)
{
    int i = m , j = m + 1;
    borderPosition[i] = j;

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (shift[j] == 0)
                shift[j] = j - i;
            j = borderPosition[j];
        }
        i--;
        j--;
        borderPosition[i] = j;
    }
}
void BoyerMooreMatcher::preprocess_prefix (QVector<int>& shift , QVector<int>& borderPosition , const QString& pattern , int m)
{
    int i , j;
    j = borderPosition[0];
    for (i = 0; i <= m; i++) {
        if (shift[i] == 0)
            shift[i] = j;
        if (i == j)
            j = borderPosition[j];
    }
}
