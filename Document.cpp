/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */

#include "Document.h"
#include <fstream>
#include <stdexcept>

void Document::setTitle(std::string str) {
    title = str;
}

void Document::setContent(std::string str) {
    content = str;
}

void Document::createFromFile(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    }
    else {
        throw std::runtime_error("Failed to open file " + filename);
    }
}

std::string Document::getTitle() const {
    return title;
}

std::string Document::getContent() const {
    return content;
}
