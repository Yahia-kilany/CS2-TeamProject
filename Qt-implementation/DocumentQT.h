/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/


#ifndef _DOCUMENTQT_H
#define _DOCUMENTQT_H
#include <string>
using namespace std;
class Document {
public:

    void setTitle (std::string str);

    void setContent (std::string str);

    void createFromFile (std::string filename);

    std::string  getTitle () const;

    std::string  getContent () const;
private:
    std::string title;
    std::string content;
};

#endif //_DOCUMENTQT_H
