/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/


#ifndef _DOCUMENTQT_H
#define _DOCUMENTQT_H
#include <QString>
class Document {
public:

    void setTitle (QString str);

    void setContent (QString str);

    QString  getTitle () const;

    QString  getContent () const;
private:
    QString title = "";
    QString content = "";
};

#endif //_DOCUMENTQT_H
