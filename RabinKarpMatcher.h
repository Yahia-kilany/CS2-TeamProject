/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */


#ifndef _RABINKARPMATCHER_H
#define _RABINKARPMATCHER_H

#include "Matcher.h"


class RabinKarpMatcher : public Matcher {
public:
    map<string , double> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    bool RabinKarpSearch (const std::string& text , const std::string& pattern , int q);
};

#endif //_RABINKARPMATCHER_H