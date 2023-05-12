/*
CS2 project: 2- Simple palagarism detection utility using string matching
*/
#include "BooyerMooreMatcher.h"
#include <iostream>
map<string,double> BooyerMooreMatcher::match(const Document& testDoc, const Corpus& corpus) {
    map <string,double> matches;
    vector<string> sentences = splitIntoSentences(testDoc);
    for (const string& s : sentences) {
        for (const Document& d : corpus.getDocuments()) {
        
        if(BoyerMooreAlgorithm(d.getContent(),s))
        {
                if (matches.find(d.getTitle()) == matches.end()) {
                    matches.insert(pair<string,double>(d.getTitle(),s.size()));
                }
                else{
                    matches[d.getTitle()]+=s.size();
                }
        }
        }
    }
        for(map<string,double>::iterator itr=matches.begin();itr!=matches.end();itr++)
        {
            itr->second=(itr->second/testDoc.getContent().size())*100;
        }
    return matches;
}

size_t BooyerMooreMatcher::getMemoryUsage() {
    return sizeof(*this);
}
