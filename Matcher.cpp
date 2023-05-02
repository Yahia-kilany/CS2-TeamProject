/**
 * Project Untitled
 */


#include "Matcher.h"

/**
 * Matcher implementation
 */


/**
 * @return size_t
 */
virtual size_t Matcher::getMemoryUsage() {
    return null;
}

/**
 * @param testDoc
 * @param corpus
 * @return vector<string>
 */
virtual vector<string> Matcher::match(const Document& testDoc, const Corpus& corpus) {
    return null;
}

/**
 * @param doc
 * @return vector<string>
 */
vector<string> Matcher::splitIntoSentences(const Document& doc) {

        vector<string> sentences;
        string sentence;
        for (char c : document.content) {
            if (c == '.' || c == '?' || c == '!') {
                if (!sentence.empty()) {
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
            else if (c == '\n') {
                if (!sentence.empty()) {
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
            else {
                sentence.push_back(c);
            }
        }
        if (!sentence.empty()) {
            sentences.push_back(sentence);
        }
        return sentences;
    }
};}