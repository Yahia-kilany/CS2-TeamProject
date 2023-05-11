/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
 // This is a C++ program for a simple plagiarism detection utility using string matching
 // The code includes the Document class, which has methods to set the title and content of a document,
 // create a document object from a file, and retrieve the title and content of a document.
#include "Document.h"
#include <fstream>
#include <stdexcept>
#include <iterator>
#include <iostream>
// set the title of the document to the given string
void Document::setTitle(std::string str) {
    title = str;
}
// set the content of the document to the given string
void Document::setContent(std::string str) {
    content = str;
}
// create a new document object by reading from the specified file
void Document::createFromFile(std::string filename) {
    title=filename;
    std::ifstream file(filename, std::ios_base::binary | std::ios_base::in);
    if(!file.is_open())
        throw std::runtime_error("Failed to open " + filename);
    using Iterator = std::istreambuf_iterator<char>;
    std::string cont(Iterator{file}, Iterator{});
    if(!file)
        throw std::runtime_error("Failed to read " + filename);
    content= cont;

}
// return the title of the document
std::string Document::getTitle() const {
    return title;
}
// return the content of the document
std::string Document::getContent() const {
    return content;
}
