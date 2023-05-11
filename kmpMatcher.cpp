/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */


#include "kmpMatcher.h"
#include <iostream>

 /**
     * kmpMatcher implementation
 */


 /**
  * @param testDoc
  * @param corpus
  * @return vector<string>
  */
vector<string> kmpMatcher::match (const Document& testDoc , const Corpus& corpus) {
    vector<string> matches;
    vector<string> sentences = splitIntoSentences (testDoc);
    for (const string& s : sentences) {
        for (const Document& d : corpus.getDocuments ()) {
            if(KMPSearch(s,d.getContent()))
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

/**
 * @return size_t
 */
size_t kmpMatcher::getMemoryUsage () {
    return sizeof (*this);
}

/**
 * @param pattern
 * @param lps
 * @return void
 */
vector<int> kmpMatcher::computeLPS (const string& pattern) {
    int M = pattern.size();
    // length of the previous longest prefix suffix
    int len = 0;

    vector<int> lps(M); // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}