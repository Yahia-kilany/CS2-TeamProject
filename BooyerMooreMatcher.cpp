/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
#include "BooyerMooreMatcher.h"
vector<string> BooyerMooreMatcher::match(const Document& testDoc, const Corpus& corpus) {
  vector<string> matches;
        vector<string> sentences = splitIntoSentences(testDoc);
        for (const auto& s : sentences) {
            vector<int> badCharacter = processBadCharacters(s);
            vector<int> goodSuffix = processGoodSuffix(s);
            for (const auto& d : corpus.getDocuments()) {
                int i = s.size() - 1;
                int j = s.size() - 1;
                while (j >= 0 && i < d.getContent().size()) {
                    if (s[j] == d.getContent().at(i)) {
                        i--;
                        j--;
                    }
                     else {
                        i += s.size() - 1 - min(j, 1 + badCharacter[d.getContent().at(i)]);
                        j = goodSuffix[j];
                    }
                }
                if (j < 0) {
                    matches.emplace_back(d.getTitle());
                    break; // add break statement to avoid duplicate matches
                }
            }
        }
        return matches;
    }



/**
 * @return size_t
 */
size_t BooyerMooreMatcher::getMemoryUsage() {
    return sizeof(*this);
}

/**
 * @param pattern
 * @return vector<int>
 */
vector<int> BooyerMooreMatcher::processBadCharacters(const string& pattern) {
  vector<int> badCharacter(256, -1);
        for (int i = 0; i < pattern.size(); i++) {
            badCharacter[pattern[i]] = i;
        }
        return badCharacter;
    }

/**
 * @param pattern
 * @return vector<int>
 */
vector<int> BooyerMooreMatcher::processGoodSuffix(const string& pattern) {
    int m = pattern.size();
        vector<int> goodSuffix(m, m);

        int i = m - 1, j = m;
        while (i >= 0) {
            while (j < m && pattern[i] != pattern[j]) {
                j = goodSuffix[j];
            }
            i--; j--;
            goodSuffix[i] = j;  
        }

        j = goodSuffix[0];
        for (i = 0; i < m; i++) {
            if (goodSuffix[i] == m) {
                goodSuffix[i] = j;
            }
            if (i == j) {
                j = goodSuffix[j];
            }
        }

        return goodSuffix;
    }
