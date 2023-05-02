/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
#ifndef _CORPUS_H
#define _CORPUS_H
#include <vector>
#include "Document.h"
class Corpus {
public:

    void addDocument (Document Doc);

    std::vector<Document> getDocuments () const;

    Document getDocument (int index) const;
private:
    std::vector<Document> Documents;
};

#endif //_CORPUS_H