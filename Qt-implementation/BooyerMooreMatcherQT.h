/**
 * CS2 project: 2- Simple palagarism detection utility using string matching
 */
#ifndef _BOOYERMOOREMATCHERQT_H
#define _BOOYERMOOREMATCHERQT_H

#include "MatcherQT.h"


class BooyerMooreMatcher: public Matcher {
public:

    QVector<QString> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    QVector<int> processBadCharacters (const QString& pattern);

    QVector<int> processGoodSuffix (const QString& pattern);
};

#endif //_BOOYERMOOREMATCHERQT_H
