/**
 * CS2 project: 2- Simple palagarism detection utility using string matching
 */
#ifndef _BOYERMOOREMATCHER_H
#define _BOYERMOOREMATCHER_H

#include "Matcher.h"


class BoyerMooreMatcher : public Matcher {
public:

    map<string,double> match (const Document& testDoc , const Corpus& corpus);

    size_t getMemoryUsage ();
private:
    bool BoyerMooreSearch (const string& text , const string& pattern);
    void preprocess_suffix (vector<int>& shift , vector<int>& borderPosition , const string& pattern , int m);
    void preprocess_prefix (vector<int>& shift , vector<int>& borderPosition , const string& pattern , int m);
};

#endif //_BOYERMOOREMATCHER_H