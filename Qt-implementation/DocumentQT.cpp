/**
CS2 project: 2- Simple palagarism detection utility using QString matching
 */

#include "DocumentQT.h"
#include <QFile>
#include <stdexcept>

void Document::setTitle(QString str) {
    title = str;
}

void Document::setContent(QString str) {
    content = str;
}

void Document::createFromFile(QString filename) {
        title=filename;
        // Open the file in read-only mode
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        // Read the contents of the file into a QString
        content = file.readAll();

        // Close the file
        file.close();
    }
QString Document::getTitle() const {
    return title;
}
QString Document::getContent() const {
    return content;
}
