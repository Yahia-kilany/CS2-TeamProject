/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/

#include "RabinKarpMatcher.h"
#include <iostream>

map<string , double> RabinKarpMatcher::match (const Document& testDoc , const Corpus& corpus) {
    int prime = 1007;
    // Define an empty map to store the matches and their similarity scores
    map <string , double> matches;
    // Split the test document into sentences
    vector<string> sentences = splitIntoSentences (testDoc);
    // Loop over each sentence in the test document
    for (const string& s : sentences) {
        // Loop over each document in the corpus
        for (const Document& d : corpus.getDocuments ()) {

            if (RabinKarpSearch (d.getContent () , s , prime))
            {
                if (matches.find (d.getTitle ()) == matches.end ())
                {
                    // If the current document is not already in the matches map, insert it with its sentence size as the similarity score
                    matches.insert (pair<string , double> (d.getTitle () , s.size ()));
                }
                // If the current document is already in the matches map, add its sentence size to its similarity score
                else {
                    matches[d.getTitle ()] += s.size ();
                }
            }
        }
    }
    for (map<string , double>::iterator itr = matches.begin ();itr != matches.end ();itr++)
    {
        itr->second = (itr->second / testDoc.getContent ().size ()) * 100;
    }
    return matches;
}
size_t RabinKarpMatcher::getMemoryUsage () {
    return sizeof (*this);
}

bool RabinKarpMatcher::RabinKarpSearch (const string& text , const string& pattern , int q)
{
    int m = pattern.length ();
    int n = text.length ();
    int i , j;
    int p = 0;
    int t = 0;
    int h = 1;
    int d = 256;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // hash value for string and pattern
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the match
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (pattern[j] != text[i + j])
                    break;
            }

            if (j == m)
                return true;
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
    return false;
}