/**
 * CS2 project: 2- Simple palagarism detection utility using QString matching
 */
#ifndef _BOYERMOOREMATCHERQT_H
#define _BOYERMOOREMATCHERQT_H

#include "MatcherQT.h"


class BoyerMooreMatcher : public Matcher {
public:

    QMap<QString , double> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:
    bool BoyerMooreSearch (QString text , QString pattern);
    void preprocess_suffix (QVector<int>& shift , QVector<int>& borderPosition , const QString& pattern , int m);
    void preprocess_prefix (QVector<int>& shift , QVector<int>& borderPosition , const QString& pattern , int m);
};

#endif //_BOYERMOOREMATCHERQT_H
