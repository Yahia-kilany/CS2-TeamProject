/**
CS2 project: 2- Simple palagarism detection utility using QString matching
 */
#include "BruteForceMatcherQT.h"

/**
 * BruteForceMatcher implementation
 */

QVector<QString> BruteForceMatcher::match(const Document& testDoc, const Corpus& corpus) {
QVector<QString> matches;
int threshold= 0;
        QVector<QString> sentences = splitIntoSentences (testDoc);
        for (const auto& s : sentences)
        {
            for (const auto& d : corpus.getDocuments()) {
                    if(hammingDistance(s,d.getContent(),threshold)){
                        matches.emplace_back (d.getTitle());
                    break;
                }
            }
        }
        return matches;
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
bool BruteForceMatcher::hammingDistance(const QString& pattern, const QString& text, int threshold) {
   int dist = 0;

        for (int i = 0; i < text.size()-pattern.size(); i++) {
            QString txtsub=text.mid(i,pattern.size());
            if (pattern[i] != text[i]) {
                dist++;
            }
            if(dist<=threshold)
            {
                return true;
            }
        }
        return false;
    }
