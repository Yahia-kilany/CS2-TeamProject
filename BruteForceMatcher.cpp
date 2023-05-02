/**
 * Project Untitled
 */


#include "BruteForceMatcher.h"

/**
 * BruteForceMatcher implementation
 */


/**
 * @param testDoc
 * @param corpus
 * @return vector<string>
 */
vector<string> BruteForceMatcher::match(const Document& testDoc, const Corpus& corpus) {
vector<string> matches;
        vector<string> sentences = splitIntoSentences (doc);
        for (const auto& s : sentences)
        {
            for (const auto& d : corpus.documents) {
                if (hammingDistance (s , d.content) <= threshold) {
                    matches.emplace_back (d.title);
                    break;
                }
            }
        }
        return matches;
    }
}

/**
 * @return int const
 */
int const BruteForceMatcher::getThreshold() {
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
        for (int i = 0; i < s1.size (); i++) {
            if (s1[i] != s2[i]) {
                dist++;
            }
        }
        return dist;
    }
}