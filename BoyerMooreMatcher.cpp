/*
CS2 project: 2- Simple palagarism detection utility using string matching
*/
#include "BoyerMooreMatcher.h"
map<string , double> BoyerMooreMatcher::match (const Document& testDoc , const Corpus& corpus) {
    map <string , double> matches;
    vector<string> sentences = splitIntoSentences (testDoc);
    for (const string& s : sentences) {
        for (const Document& d : corpus.getDocuments ()) {

            if (BoyerMooreSearch (d.getContent () , s))
            {
                if (matches.find (d.getTitle ()) == matches.end ()) {
                    matches.insert (pair<string , double> (d.getTitle () , s.size ()));
                }
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

size_t BoyerMooreMatcher::getMemoryUsage () {
    return sizeof (*this);
}
bool BoyerMooreMatcher::BoyerMooreSearch (const string& text , const string& pattern) {
    int s = 0 , j;
    int m = pattern.length ();
    int n = text.length ();
    vector<int> borderPosition (m + 1) , shift (m + 1 , 0);
    preprocess_suffix (shift , borderPosition , &pattern[0] , m);
    preprocess_prefix (shift , borderPosition , &pattern[0] , m);

    while (s <= n - m) {
        j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            return true;
        }
        s += shift[j + 1];
    }

    return false;
}
void BoyerMooreMatcher::preprocess_suffix (vector<int>& shift , vector<int>& borderPosition , const string& pattern , int m)
{
    int i = m , j = m + 1;
    borderPosition[i] = j;

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (shift[j] == 0)
                shift[j] = j - i;
            j = borderPosition[j];
        }
        i--;
        j--;
        borderPosition[i] = j;
    }
}
void BoyerMooreMatcher::preprocess_prefix (vector<int>& shift , vector<int>& borderPosition , const string& pattern , int m)
{
    int i , j;
    j = borderPosition[0];
    for (i = 0; i <= m; i++) {
        if (shift[i] == 0)
            shift[i] = j;
        if (i == j)
            j = borderPosition[j];
    }
}