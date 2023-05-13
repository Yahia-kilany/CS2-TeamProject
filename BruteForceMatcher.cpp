/**
 * CS2 project: 2- Simple plagiarism detection utility using string matching
 */

#include "BruteForceMatcher.h"
#include <algorithm>

 /**
  * BruteForceMatcher implementation
  */

  /**
   *Matches a given document against a corpus of documents using the brute force string matching algorithm
   *
   *testDoc The document to be matched against the corpus
   *corpus The corpus of documents to match the test document against
   *A map of document titles and their corresponding match scores
   */
map<string, double> BruteForceMatcher::match(const Document& testDoc, const Corpus& corpus) {
    map<string, double> matches;
    int threshold = 0;
    vector<string> sentences = splitIntoSentences(testDoc);

    // For each sentence in the test document
    for (const string& s : sentences) {
        // For each document in the corpus
        for (const Document& d : corpus.getDocuments()) {
            // If the Hamming distance between the sentence and the document content is less than or equal to the threshold
            if (hammingDistance(s, d.getContent(), threshold)) {
                // If the document title is not already in the matches map, insert it
                if (matches.find(d.getTitle()) == matches.end()) {
                    matches.insert(pair<string, double>(d.getTitle(), s.size()));
                }
                // Otherwise, increment the score for that document
                else {
                    matches[d.getTitle()] += s.size();
                }
            }
        }
    }

    // Calculate match scores as a percentage of the total length of the test document
    for (map<string, double>::iterator itr = matches.begin(); itr != matches.end(); itr++) {
        itr->second = (itr->second / testDoc.getContent().size()) * 100;
    }

    return matches;
}

/**
 *Returns the memory usage of the BruteForceMatcher object
 *
 *The memory usage of the BruteForceMatcher object in bytes
 */
size_t BruteForceMatcher::getMemoryUsage() {
    return sizeof(*this);
}

/**
 *Computes the Hamming distance between a pattern and a text string, up to a given threshold
 *
 *pattern The pattern to match against the text string
 *text The text string to match against the pattern
 *threshold The maximum allowable Hamming distance
 *True if the Hamming distance is less than or equal to the threshold, false otherwise
 */
bool BruteForceMatcher::hammingDistance(const string& pattern, const string& text, int threshold) {
    for (int i = 0; i < text.size() - pattern.size(); i++) {
        int dist = 0;
        string txtsub = text.substr(i, pattern.size());
        for (int j = 0; j < pattern.size(); j++) {
            if (pattern[j] != txtsub[j]) {
                dist++;
            }
        }
        if (dist <= threshold) {
            return true;
        }
    }
    return false;
}
