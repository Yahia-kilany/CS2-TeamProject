/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/


#ifndef _BRUTEFORCEMATCHER_H
#define _BRUTEFORCEMATCHER_H

#include "Matcher.h"


class BruteForceMatcher: public Matcher {
public:
    BruteForceMatcher ();
    BruteForceMatcher (int);
    std::vector<std::string> match (const Document& testDoc , const Corpus& corpus);
    size_t getMemoryUsage ();
private:
    bool hammingDistance (const std::string& pattern , const std::string& text, int threshold);
};

#endif //_BRUTEFORCEMATCHER_H