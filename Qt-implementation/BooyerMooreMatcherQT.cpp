/**
CS2 project: 2- Simple palagarism detection utility using QString matching
 */
#include "BooyerMooreMatcherQT.h"
QVector<QString> BooyerMooreMatcher::match(const Document& testDoc, const Corpus& corpus) {
  QVector<QString> matches;
        QVector<QString> sentences = splitIntoSentences(testDoc);
        for (const auto& s : sentences) {
            QVector<int> badCharacter = processBadCharacters(s);
            QVector<int> goodSuffix = processGoodSuffix(s);
            for (const auto& d : corpus.getDocuments()) {
                int i = s.size() - 1;
                int j = s.size() - 1;
                while (j >= 0 && i < d.getContent().size()) {
                    if (s[j] == d.getContent().at(i)) {
                        i--;
                        j--;
                    }
                     else {
                        i += s.size() - 1 - min(j, 1 + badCharacter.at(static_cast<int>(d.getContent().at(i).toLatin1())));
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




size_t BooyerMooreMatcher::getMemoryUsage() {
    return sizeof(*this);
}

QVector<int> BooyerMooreMatcher::processBadCharacters(const QString& pattern) {
  QVector<int> badCharacter(256, -1);
  int*data= badCharacter.data();
        for (int i = 0; i < pattern.size(); i++) {
            data[static_cast<int>(pattern.at(i).toLatin1())]= i;
        }
        return badCharacter;
    }

QVector<int> BooyerMooreMatcher::processGoodSuffix(const QString& pattern) {
    int m = pattern.size();
        QVector<int> goodSuffix(m, m);

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
