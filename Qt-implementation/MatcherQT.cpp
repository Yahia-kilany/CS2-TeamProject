/**
CS2 project: 2- Simple palagarism detection utility using QString matching
 */
#include "MatcherQT.h"

/**
 * Matcher implementation
 */


QVector<QString> Matcher::splitIntoSentences(const Document& doc) {

        QVector<QString> sentences;
        QString sentence;
        QChar c;
        for (int i=0;i<doc.getContent().size();i++) {
            c=doc.getContent().at(i);
            if (c == '.' || c == '?' || c == '!') {
                if (!sentence.isEmpty()) {
                    i++;
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
            else if (c == '\n') {
                if (!sentence.isEmpty()) {
                    i++;
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
