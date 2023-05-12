/*
 * CS2 project: 2- Simple plagiarism detection utility using string matching
 *
 * This program uses the Boyer-Moore string matching algorithm to compare a test document
 * against a corpus of known documents to detect instances of plagiarism.
 */

#include "BoyerMooreMatcher.h"
#include <iostream>

 // The match function takes a testDoc object and a corpus object, and returns a map
 // that contains the titles of matching documents and their percentage score.
map<string, double> BoyerMooreMatcher::match(const Document& testDoc, const Corpus& corpus) {
    map<string, double> matches;

    // Split the test document into sentences.
    vector<string> sentences = splitIntoSentences(testDoc);

    // For each sentence in the test document, compare it to each document in the corpus.
    for (const string& s : sentences) {
        for (const Document& d : corpus.getDocuments()) {
            // If a match is found, add the document title and the length of the matching
            // sentence to the matches map.
            if (BoyerMooreAlgorithm(d.getContent(), s)) {
                if (matches.find(d.getTitle()) == matches.end()) {
                    matches.insert(pair<string, double>(d.getTitle(), s.size()));
                }
                else {
                    matches[d.getTitle()] += s.size();
                }
            }
        }
    }

    // Normalize the scores by dividing by the length of the test document and multiplying by 100.
    for (auto& match : matches) {
        match.second = (match.second / testDoc.getContent().size()) * 100;
    }

    return matches;
}

// The getMemoryUsage function returns the size of the BoyerMooreMatcher object in memory.
size_t BoyerMooreMatcher::getMemoryUsage() {
    return sizeof(*this);
}
