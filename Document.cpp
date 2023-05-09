/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
 // This is a C++ program for a simple plagiarism detection utility using string matching
 // The code includes the Document class, which has methods to set the title and content of a document,
 // create a document object from a file, and retrieve the title and content of a document.
#include "Document.h"
#include <fstream>
#include <stdexcept>

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
    title=filename;  // set the title to the filename
    std::ifstream file(filename); // create an input file stream for the specified file
    if (file.is_open()) { // check if the file is open
        std::string line;
        // read the file line by line and append it to the document content
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close(); // close the file stream
    }
    else {
        // if the file could not be opened, throw a runtime error
        throw std::runtime_error("Failed to open file " + filename);
    }
}
// return the title of the document
std::string Document::getTitle() const {
    return title;
}
// return the content of the document
std::string Document::getContent() const {
    return content;
}
