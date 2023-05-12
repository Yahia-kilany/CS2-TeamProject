/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */


#ifndef _MATCHERQT_H
#define _MATCHERQT_H
#include <vector>
#include <map>
#include <algorithm>
#include "DocumentQT.h"
#include "CorpusQT.h"
using namespace std;
class Matcher {
public:

    virtual size_t getMemoryUsage () = 0;

    virtual map<string,double> match (const Document& testDoc , const Corpus& corpus) = 0;
protected:

    std::vector<std::string> splitIntoSentences (const Document& doc);
};

#endif //_MATCHERQT_H
