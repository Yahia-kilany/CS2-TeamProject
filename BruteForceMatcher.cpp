/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
#include "BruteForceMatcher.h"
#include <algorithm>
/**
 * BruteForceMatcher implementation
 */

vector<string> BruteForceMatcher::match(const Document& testDoc, const Corpus& corpus) {
vector<string> matches;
int threshold = 0;
        vector<string> sentences = splitIntoSentences (testDoc);
        for (const string& s : sentences)
        {
            for (const Document& d : corpus.getDocuments()) {
                    if(hammingDistance(s,d.getContent(),threshold)){
                        if ( std::find(matches.begin(), matches.end(), d.getTitle()) == matches.end() )
                        matches.emplace_back (d.getTitle());
                    break;
                    }
                
            }
        }
        return matches;
    }




/**
 * @return size_t
 */
size_t BruteForceMatcher::getMemoryUsage() {
    return sizeof(*this);
}

bool BruteForceMatcher::hammingDistance(const string& pattern, const string& text, int threshold) {
   
        for (int i = 0; i < text.size()-pattern.size(); i++) {
               int dist = 0;
            string txtsub=text.substr(i,pattern.size());
            for(int j=0; j<pattern.size();j++)
            {
                if (pattern[j] != txtsub[j]) {
                    dist++;
                }
            }
                if(dist<=threshold)
                {
                    return true;
                }
        }
        return false;
    }
