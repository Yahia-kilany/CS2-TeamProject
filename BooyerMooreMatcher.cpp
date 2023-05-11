/*
CS2 project: 2- Simple palagarism detection utility using string matching
*/
#include "BooyerMooreMatcher.h"
#include <iostream>
vector<string> BooyerMooreMatcher::match(const Document& testDoc, const Corpus& corpus) {
    vector<string> matches;
    vector<string> sentences = splitIntoSentences(testDoc);
    for (const string& s : sentences) {
        vector<int> badChar=processBadCharacters(s);
        vector<int> goodsuffix = processGoodSuffix(s);
        for (const Document& d : corpus.getDocuments()) {
            cout<<1<<" "<<d.getTitle();
            int i = s.size()-1;
            while (i < d.getContent().size()) {
                int j = s.size() - 1;
                while (j >= 0 && s[j] == d.getContent().at(i)) {
                cout<<s[j]<<" "<<d.getContent().at(i)<<endl;
                    i--;
                    j--;
                }
                if (j < 0) {
                    if (std::find(matches.begin(), matches.end(), d.getTitle()) == matches.end()) {
                        matches.emplace_back(d.getTitle());
                    }
                } else {
                    int badcharShift = j - badChar[static_cast<int>(d.getContent().at(i)) * s.size() + j];
                    int goodSuffShift = goodsuffix[j + 1];
                    if (j < s.size() - 1) {
                        goodSuffShift = goodsuffix[j + 1];
                    }
                    i += max(badcharShift, goodSuffShift);
                }
            }
        }
    }
    return matches;
}

size_t BooyerMooreMatcher::getMemoryUsage() {
    return sizeof(*this);
}

vector<int> BooyerMooreMatcher::processBadCharacters(const string& pattern) {
    vector<int> badChar(256 * pattern.size(), -1);
    for (int i = 0; i < pattern.size(); i++) {
        badChar[static_cast<int>(pattern[i]) * pattern.size() + i] = i;
    }
    for (int i = 0; i < 256; i++) {
        
        for (int j = pattern.size() - 2; j >= 0; j--) {
            if (badChar[i * pattern.size() + j] == -1) {
                badChar[i * pattern.size() + j] = badChar[i * pattern.size() + j + 1];
            }
        }
    }
    return badChar;
}


vector<int> BooyerMooreMatcher::processGoodSuffix(const string& pattern) {
    vector<int> goodsuffix(pattern.size(), 0);
    int lastPrefixPosition = pattern.size();
    for (int i = pattern.size() - 1; i >= 0; i--) {
        if (pattern.substr(i + 1) == pattern.substr(0, pattern.length() - i - 1)) {
            lastPrefixPosition = i + 1;
        }
        goodsuffix[i] = lastPrefixPosition - i + pattern.size() - 1;
    }
    for (int i = 0; i < pattern.size() - 1; i++) {
        int slen = goodsuffix[i + 1];
        if (i + slen < pattern.size() && pattern[i + slen] != pattern[i]) {
            goodsuffix[i + 1] = slen - 1;
        }
    }
    return goodsuffix;
}