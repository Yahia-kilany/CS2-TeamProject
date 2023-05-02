/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */

#include "Corpus.h"

/**
 * Corpus implementation
 */


void Corpus::addDocument(Document Doc) {
    return;
}
vector<Document> Corpus::getDocuments() const{
    return Documents;
}

Document Corpus::getDocument(int index) const{
    if(index>Documents.size()){
        exit(1);
    }
    return Documents[index];
}