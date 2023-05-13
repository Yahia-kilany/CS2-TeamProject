/**
CS2 project: 2- Simple palagarism detection utility using QString matching
 */
#include "BruteForceMatcherQT.h"
#include <algorithm>
 /**
  * BruteForceMatcher implementation
  */

QMap<QString , double> BruteForceMatcher::match (const Document& testDoc , const Corpus& corpus) {
    QMap<QString , double> matches;
    int threshold = 0;
    QVector<QString> sentences = splitIntoSentences (testDoc);
    for (const QString& s : sentences)
    {
        for (const Document& d : corpus.getDocuments ()) {
            if (hammingDistance (s , d.getContent () , threshold)) {
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
    QMap<QString , double>::iterator i;
    for (i = matches.begin (); i != matches.end (); ++i) {
        double newval = (i.value () / testDoc.getContent ().size () * 100);
        i.value () = newval;
    }
    return matches;
}




/**
 * @return size_t
 */
size_t BruteForceMatcher::getMemoryUsage () {
    return sizeof (*this);
}

bool BruteForceMatcher::hammingDistance (const QString& pattern , const QString& text , int threshold) {
    for (int i = 0; i < text.size () - pattern.size (); i++) {
        int dist = 0;
        QString txtsub = text.mid (i , pattern.size ());
        for (int j = 0; j < pattern.size ();j++)
        {
            if (pattern[j] != txtsub[j]) {
                dist++;
            }
        }
        if (dist <= threshold)
        {
            return true;
        }
    }
    return false;
}
