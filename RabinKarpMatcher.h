/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */


#ifndef _RABINKARPMATCHER_H
#define _RABINKARPMATCHER_H

#include "Matcher.h"


class RabinKarpMatcher : public Matcher {
public:
    map<string,double> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    bool RabinKarp (const std::string& text , const std::string& pattern , int q) {
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
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
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
                t = (d * (t - text[i] * h) + text[i + m]) % q;

                if (t < 0)
                    t = (t + q);
            }
        }
        return false;
    }
    // int calculateHash (const std::string& str , int start , int end , int prime);


    // bool isEqual (const std::string& str1 , int start1 , int end1 , const std::string& str2 , int start2 , int end2);
};

#endif //_RABINKARPMATCHER_H