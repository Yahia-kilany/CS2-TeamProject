/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/


#ifndef _KMPMATCHERQT_H
#define _KMPMATCHERQT_H

#include "MatcherQT.h"


class kmpMatcher: public Matcher {
public:

    QVector<QString> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    void computeLPS (const QString& pattern , QVector<int>& lps);
};

#endif //_KMPMATCHERQT_H
