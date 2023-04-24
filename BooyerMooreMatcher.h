/**
 * CS2 project: 2- Simple palagarism detection utility using string matching
 */


#ifndef _BOOYERMOOREMATCHER_H
#define _BOOYERMOOREMATCHER_H

#include "Matcher.h"


class BooyerMooreMatcher: public Matcher {
public:

    std::vector<std::string> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:

    std::vector<int> processBadCharacters (const std::string& pattern);

    std::vector<int> processGoodSuffix (const std::string& pattern);
};

#endif //_BOOYERMOOREMATCHER_H