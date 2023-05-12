/*
CS2 project: 2- Simple palagarism detection utility using QString matching
*/
#include "BooyerMooreMatcherQT.h"
QMap<QString,double> BooyerMooreMatcher::match(const Document& testDoc, const Corpus& corpus) {
    QMap <QString,double> matches;
    QVector<QString> sentences = splitIntoSentences(testDoc);
    for (const QString& s : sentences) {
        for (const Document& d : corpus.getDocuments()) {
        
        if(BoyerMooreAlgorithm(d.getContent(),s))
        {
                if (matches.find(d.getTitle()) == matches.end()) {
                    matches.insert(d.getTitle(),s.size());
                }
                else{
                    matches[d.getTitle()]+=s.size();
                }
        }
        }

    }
    QMap<QString, double>::iterator i;
            for (i =matches.begin(); i != matches.end(); ++i){
                double newval=((i.value()/testDoc.getContent().size())*100);
                i.value() = newval;
            }
        return matches;
}

size_t BooyerMooreMatcher::getMemoryUsage() {
    return sizeof(*this);
}
