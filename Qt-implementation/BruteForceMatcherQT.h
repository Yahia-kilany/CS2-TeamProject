/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/


#ifndef _BRUTEFORCEMATCHERQT_H
#define _BRUTEFORCEMATCHERQT_H

#include "MatcherQT.h"


class BruteForceMatcher: public Matcher {
public:
    QMap<QString,double> match (const Document& testDoc , const Corpus& corpus);
    size_t getMemoryUsage ();
private:
    bool hammingDistance (const QString& pattern , const QString& text, int threshold);
};

#endif //_BRUTEFORCEMATCHERQT_H
