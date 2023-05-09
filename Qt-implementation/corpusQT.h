/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
#ifndef _CORPUSQT_H
#define _CORPUSQT_H
#include <QVector>
#include "DocumentQT.h"
class Corpus {
public:

    void addDocument (Document Doc);

    QVector<Document> getDocuments () const;

    Document getDocument (int index) const;
private:
    QVector<Document> Documents;
};

#endif //_CORPUSQT_H
