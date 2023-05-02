/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
#include "BruteForceMatcher.h"

/**
 * BruteForceMatcher implementation
 */

vector<string> BruteForceMatcher::match(const Document& testDoc, const Corpus& corpus) {
vector<string> matches;
        vector<string> sentences = splitIntoSentences (testDoc);
        for (const auto& s : sentences)
        {
            for (const auto& d : corpus.getDocuments()) {
                if (hammingDistance (s , d.getContent()) <= threshold) {
                    matches.emplace_back (d.getTitle());
                    break;
                }
            }
        }
        return matches;
    }


/**
 * @return int const
 */
int BruteForceMatcher::getThreshold() const
{
    return null;
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
int BruteForceMatcher::hammingDistance(const string& pattern, const string& text) {
   int dist = 0;
        for (int i = 0; i < pattern.size (); i++) {
            if (pattern[i] != text[i]) {
                dist++;
            }
        }
        return dist;
    }
