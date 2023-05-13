/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
 // This is a C++ program for a simple plagiarism detection utility using string matching
 // The code includes the Document class, which has methods to set the title and content of a document,
 // create a document object from a file, and retrieve the title and content of a document.
#include "DocumentQT.h"
#include <stdexcept>
// set the title of the document to the given string
void Document::setTitle (QString str) {
    title = str;
}
// set the content of the document to the given string
void Document::setContent (QString str) {
    content = str;
}
// return the title of the document
QString Document::getTitle () const {
    return title;
}
// return the content of the document
QString Document::getContent () const {
    return content;
}
