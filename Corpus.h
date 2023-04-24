#ifndef _CORPUS_H
#define _CORPUS_H
#include <vector>
#include "Document.h"
class Corpus {
public:

    void addDocument (Document Doc);

    std::vector<std::string> getDocuments () const;

    Document getDocument (int index) const;
private:
    std::vector<std::string> Documents;
};

#endif //_CORPUS_H