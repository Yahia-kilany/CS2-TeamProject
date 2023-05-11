/*
CS2 project: 2- Simple palagarism detection utility using string matching
*/
#include "BooyerMooreMatcher.h"
#include <iostream>
vector<string> BooyerMooreMatcher::match(const Document& testDoc, const Corpus& corpus) {
    vector<string> matches;
    vector<string> sentences = splitIntoSentences(testDoc);
    for (const string& s : sentences) {
        for (const Document& d : corpus.getDocuments()) {
        if(BoyerMooreAlgorithm(d.getContent(),s))
        {
            if ( std::find(matches.begin(), matches.end(), d.getTitle()) == matches.end() )
                {
                    matches.emplace_back (d.getTitle());
                }
        }
        }
    }
    return matches;
}

size_t BooyerMooreMatcher::getMemoryUsage() {
    return sizeof(*this);
}
