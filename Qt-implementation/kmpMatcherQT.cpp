/**
CS2 project: 2- Simple palagarism detection utility using QString matching
 */


#include "kmpMatcherQT.h"
#include <iostream>

 /**
     * kmpMatcher implementation
 */


 /**
  * @param testDoc
  * @param corpus
  * @return QVector<QString>
  */
QMap<QString , double> kmpMatcher::match (const Document& testDoc , const Corpus& corpus) {
    QMap <QString , double> matches;
    QVector<QString> sentences = splitIntoSentences (testDoc);
    for (const QString& s : sentences) {
        for (const Document& d : corpus.getDocuments ()) {

            if (KMPSearch (s , d.getContent()))
            {
                if (matches.find (d.getTitle ()) == matches.end ())
                {
                    matches.insert (d.getTitle () , s.size ());
                }
                else {
                    matches[d.getTitle ()] += s.size ();
                }
            }
        }
    }
    QMap<QString, double>::iterator i;
            for (i =matches.begin(); i != matches.end(); ++i){
                double newval=(i.value()/testDoc.getContent().size()*100);
                i.value() = newval;
            }
        return matches;}

/**
 * @return size_t
 */
size_t kmpMatcher::getMemoryUsage () {
    return sizeof (*this);
}

/**
 * @param pattern
 * @param lps
 * @return void
 */
QVector<int> kmpMatcher::computeLPS (const QString& pattern) {
    int M = pattern.size ();
    // length of the previous longest prefix suffix
    int len = 0;

    QVector<int> lps (M); // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
