/**
CS2 project: 2- Simple palagarism detection utility using QString matching
*/

#include "RabinKarpMatcherQT.h"
#include <iostream>

QMap<QString , double> RabinKarpMatcher::match (const Document& testDoc , const Corpus& corpus) {
    int prime = 107;
    QMap <QString , double> matches;
    QVector<QString> sentences = splitIntoSentences (testDoc);
    for (const QString& s : sentences) {
        for (const Document& d : corpus.getDocuments ()) {

            if (RabinKarpSearch (d.getContent () , s , prime))
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
    QMap<QString , double>::iterator i;
    for (i = matches.begin (); i != matches.end (); ++i) {
        double newval = (i.value () / testDoc.getContent ().size () * 100);
        i.value () = newval;
    }
    return matches;
}
size_t RabinKarpMatcher::getMemoryUsage () {
    return sizeof (*this);
}
bool RabinKarpMatcher::RabinKarpSearch (const QString& text , const QString& pattern , int q)
{
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
        p = (d * p + pattern[i].toLatin1 ()) % q;
        t = (d * t + text[i].toLatin1 ()) % q;
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
            t = (d * (t - text[i].toLatin1 () * h) + text[i + m].toLatin1 ()) % q;

            if (t < 0)
                t = (t + q);
        }
    }
    return false;
}
// int RabinKarpMatcher::calculateHash(const QString& str, int start, int end, int prime) {
// int hash = 0;
//         int base = 256; // choose a base for the hash function
//         int powBase = 1; // store powers of base modulo prime
//         for (int i = start; i <= end; i++) {
//             hash = (hash + (str[i] * powBase) % prime) % prime; // add modulus operation
//             powBase = (powBase * base) % prime; // update power of base modulo prime
//         }
//         return hash;
//     }

// bool RabinKarpMatcher::isEqual(const QString& str1, int start1, int end1, const QString& str2, int start2, int end2) {
//     if (end1 - start1 != end2 - start2) {
//             return false;
//         }
//         for (int i = start1, j = start2; i <= end1 && j <= end2; i++, j++) {
//             if (str1[i] != str2[j]) {
//                 return false;
//             }
//         }
//         return true;
//     }
