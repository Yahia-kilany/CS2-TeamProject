/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */


#ifndef _MATCHER_H
#define _MATCHER_H
#include <vector>
#include <map>
#include <algorithm>
#include "Document.h"
#include "Corpus.h"
using namespace std;
class Matcher {
public:

    virtual size_t getMemoryUsage () = 0;

    virtual map<string,double> match (const Document& testDoc , const Corpus& corpus) = 0;
protected:

    std::vector<std::string> splitIntoSentences (const Document& doc);
};

#endif //_MATCHER_H