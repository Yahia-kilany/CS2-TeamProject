/**
CS2 project: 2- Simple palagarism detection utility using QString matching
 */
#include "MatcherQT.h"

QVector<QString> Matcher::splitIntoSentences(const Document& doc) {

        QVector<QString> sentences;
        QString sentence;
        for (QChar c : doc.getContent()) {
            if (c == '.' || c == '?' || c == '!') {
                if (!sentence.isEmpty()) {
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
            else if (c == '\n') {
                if (!sentence.isEmpty()) {
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
            else {
                sentence.push_back(c);
            }
        }
        if (!sentence.isEmpty()) {
            sentences.push_back(sentence);
        }
        return sentences;
    }
