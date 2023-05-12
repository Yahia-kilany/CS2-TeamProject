/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
#ifndef _CORPUSQT_H
#define _CORPUSQT_H
#include <vector>
#include "DocumentQT.h"
class Corpus {
public:

    void addDocument (Document Doc);

    std::vector<Document> getDocuments () const;

    Document getDocument (int index) const;
private:
    std::vector<Document> Documents;
};

#endif //_CORPUSQT_H
