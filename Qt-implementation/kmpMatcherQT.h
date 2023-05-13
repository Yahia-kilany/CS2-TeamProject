/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/


#ifndef _KMPMATCHERQT_H
#define _KMPMATCHERQT_H

#include "MatcherQT.h"


class kmpMatcher : public Matcher {
public:

    QMap<QString , double> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    QVector<int> computeLPS (const QString& pattern);

    bool KMPSearch (const QString& pat , const QString& txt);
};

#endif //_KMPMATCHERQT_H
