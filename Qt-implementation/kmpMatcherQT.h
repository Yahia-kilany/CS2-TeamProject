/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/


#ifndef _KMPMATCHERQT_H
#define _KMPMATCHERQT_H

#include "MatcherQT.h"


class kmpMatcher: public Matcher {
public:

    QMap<QString,double> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    QVector<int> computeLPS (const QString& pattern);

bool KMPSearch(const QString& pat, const QString& txt) {
    int M = pat.length();
    int N = txt.length();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    QVector<int> lps= computeLPS(pat);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            return true;
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return false;
}

};

#endif //_KMPMATCHERQT_H
