/**
CS2 project: 2- Simple palagarism detection utility using string matching
 */
#include "Matcher.h"

 /**
  * Matcher implementation
  */

  //This function splits a document into individual sentences.
  //eturn A vector of strings, where each string is an individual sentence from the document.
vector<string> Matcher::splitIntoSentences(const Document& doc) {

    vector<string> sentences;// initialize an empty vector to store the sentences
    string sentence; // initialize an empty string to store each sentence
    char c;
    for (int i = 0;i < doc.getContent().size();i++) {// iterate through the characters in the document's content
        c = doc.getContent().at(i);
        if (c == '.' || c == '?' || c == '!') { // if a sentence-ending punctuation mark is encountered
            if (!sentence.empty()) {// check if the sentence is non-empty
                i++; // increment the iterator to skip the punctuation mark
                sentences.push_back(sentence);// add the sentence to the vector of sentences
                sentence.clear();// reset the sentence variable
            }
        }
        else if (c == '\n') { // if a newline character is encountered
            if (!sentence.empty()) {// check if the sentence is non-empty
                i++;// increment the iterator to skip the newline character
                sentences.push_back(sentence); // add the sentence to the vector of sentences
                sentence.clear();// reset the sentence variable
            }
        }
        else { // if the character is not a sentence-ending punctuation mark or a newline 
            sentence.push_back(c);// add the character to the current sentence
        }
    }
    if (!sentence.empty()) {// if there is a non-empty sentence left over
        sentences.push_back(sentence);// add it to the vector of sentences
    }
    return sentences;
}
