/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/


#ifndef _KMPMATCHER_H
#define _KMPMATCHER_H

#include "Matcher.h"


class kmpMatcher: public Matcher {
public:

    std::vector<std::string> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    void computeLPS (const std::string& pattern , std::vector<int>& lps);
};

#endif //_KMPMATCHER_H