/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */


#ifndef _RABINKARPMATCHERQT_H
#define _RABINKARPMATCHERQT_H

#include "MatcherQT.h"


class RabinKarpMatcher : public Matcher {
public:
    QMap<QString , double> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    bool RabinKarpSearch (const QString& text , const QString& pattern , int q);
    // int calculateHash (const QString& str , int start , int end , int prime);


    // bool isEqual (const QString& str1 , int start1 , int end1 , const QString& str2 , int start2 , int end2);
};

#endif //_RABINKARPMATCHERQT_H
