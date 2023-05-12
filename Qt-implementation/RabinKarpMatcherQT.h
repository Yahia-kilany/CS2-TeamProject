/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */


#ifndef _RABINKARPMATCHERQT_H
#define _RABINKARPMATCHERQT_H

#include "MatcherQT.h"


class RabinKarpMatcher : public Matcher {
public:
    QMap<QString,double> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    bool RabinKarp (const QString& text , const QString& pattern , int q) {
        int m = pattern.length ();
        int n = text.length ();
        int i , j;
        int p = 0;
        int t = 0;
        int h = 1;
        int d = 256;

        for (i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // hash value for string and pattern
        for (i = 0; i < m; i++) {
            p = (d * p + pattern[i].toLatin1()) % q;
            t = (d * t + text[i].toLatin1()) % q;
        }

        // Find the match
        for (i = 0; i <= n - m; i++) {
            if (p == t) {
                for (j = 0; j < m; j++) {
                    if (pattern[j] != text[i + j])
                        break;
                }

                if (j == m)
                return true;
            }

            if (i < n - m) {
                t = (d * (t - text[i].toLatin1() * h) + text[i + m].toLatin1()) % q;

                if (t < 0)
                    t = (t + q);
            }
        }
        return false;
    }
    // int calculateHash (const QString& str , int start , int end , int prime);


    // bool isEqual (const QString& str1 , int start1 , int end1 , const QString& str2 , int start2 , int end2);
};

#endif //_RABINKARPMATCHERQT_H
