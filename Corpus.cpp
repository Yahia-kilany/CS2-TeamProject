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
<<<<<<< HEAD
    if(index>Documents.size()){
        exit(1);
    }
=======
>>>>>>> d676a60ba5d1f011f02e0f6e95f4c4d72625a1f2
    return Documents[index];
}