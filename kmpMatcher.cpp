/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */


#include "kmpMatcher.h"

/**
 * kmpMatcher implementation
 */


/**
 * @param testDoc
 * @param corpus
 * @return vector<string>
 */
vector<string> kmpMatcher::match(const Document& testDoc, const Corpus& corpus) {
vector<string> matches;
        vector<string> sentences = splitIntoSentences(testDoc);
        for (const auto& s : sentences) {
            vector<int> lps(s.size(), 0);
            int i = 0;
            int j = 0;
            for (const auto& d : corpus.getDocuments()) {
                int n = d.getContent().size();
                while (i < s.size() && j < n) {
                    if (s[i] == d.getContent().at(j)) {
                        i++;
                        j++;
                    }
                    if (i == s.size()) {
                        matches.emplace_back(d.getTitle());
                        break; // add break statement to avoid duplicate matches
                    }
                    else if (j < n && s[i] != d.getContent().at(j)) {
                        if (i != 0) {
                            i = lps[i - 1];
                        }
                        else {
                            j++;
                        }
                    }
                }
            }
        }
        return matches;}

/**
 * @return size_t
 */
size_t kmpMatcher::getMemoryUsage() {
    return sizeof(*this);
}

/**
 * @param pattern
 * @param lps
 * @return void
 */
void kmpMatcher::computeLPS(const string& pattern, vector<int>& lps) {
     int m = pattern.size();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }