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
    title = filename;// set the title of the document to the filename
    std::ifstream file(filename, std::ios_base::binary | std::ios_base::in);// open the file in binary input mode
    if (!file.is_open()) // if the file failed to open
        throw std::runtime_error("Failed to open " + filename);// throw an exception with an error message
    using Iterator = std::istreambuf_iterator<char>;
    std::string cont(Iterator{ file }, Iterator{});// read the content of the file into a string
    if (!file) // if the read operation failed
        throw std::runtime_error("Failed to read " + filename); // throw an exception with an error message
    content = cont; // set the content of the document to the string containing the file's content

}
// return the title of the document
std::string Document::getTitle() const {
    return title;
}
// return the content of the document
std::string Document::getContent() const {
    return content;
}
