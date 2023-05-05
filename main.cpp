#include <iostream>
#include <time.h>
#include <Document.h>
#include <Corpus.h>
#include <Matcher.h>
#include <chrono>
#include <BruteForceMatcher.h>
#include <RabinKarpMatcher.h>
#include <kmpMatcher.h>
#include <BooyerMooreMatcher.h>
int main() {
    string text = "This is a sample text that contains some text.";
    string pattern = "text";
    
    BruteForceMatcher bruteForceMatcher;
    RabinKarpMatcher rabinKarpMatcher;
    
    vector<int> bfMatches = bruteForceMatcher.match(text, pattern);
    vector<int> rkMatches = rabinKarpMatcher.match(text, pattern);
    
    // Compare the results of the two algorithms
    if (bfMatches.size() == rkMatches.size()) {
        cout << "Both algorithms found the same number of matches." << endl;
    } else {
        cout << "The algorithms found a different number of matches." << endl;
    }
    
    // Compare the time it takes to run each algorithm
    auto start = chrono::high_resolution_clock::now();
    bruteForceMatcher.match(text, pattern);
    auto end = chrono::high_resolution_clock::now();
    auto bfDuration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    
    start = chrono::high_resolution_clock::now();
    rabinKarpMatcher.match(text, pattern);
    end = chrono::high_resolution_clock::now();
    auto rkDuration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    
    if (bfDuration < rkDuration) {
        cout << "Brute force algorithm is faster." << endl;
    } else if (bfDuration > rkDuration) {
        cout << "Rabin-Karp algorithm is faster." << endl;
    } else {
        cout << "Both algorithms took the same amount of time to run." << endl;
    }
    
    return 0;
}