/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */

#include "corpusQT.h"

void Corpus::addDocument(Document Doc) {
    Documents.push_back(Doc);
    return;
}
QVector<Document> Corpus::getDocuments() const{
    return Documents;
}
Document Corpus::getDocument(int index) const
{
    if(index>Documents.size())
        exit(1);
    return Documents[index];
}
