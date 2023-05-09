/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
#include "BruteForceMatcher.h"

/**
 * BruteForceMatcher implementation
 */

vector<string> BruteForceMatcher::match(const Document& testDoc, const Corpus& corpus) {
vector<string> matches;
int threshold = 0;
        vector<string> sentences = splitIntoSentences (testDoc);
        for (const auto& s : sentences)
        {
            for (const auto& d : corpus.getDocuments()) {
                    if(hammingDistance(s,d.getContent(),threshold)){
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

/**
 * @param pattern
 * @param text
 * @return int
 */
bool BruteForceMatcher::hammingDistance(const string& pattern, const string& text, int threshold) {
   int dist = 0;
   
        for (int i = 0; i < text.size()-pattern.size(); i++) {
            string txtsub=text.substr(i,pattern.size()+i);
            if (pattern[i] != text[i]) {
                dist++;
            }
            if(dist<=threshold)
            {
                return true;
            }
        }
        return false;
    }
