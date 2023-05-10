#include <iostream>
#include "Document.h"
#include "Corpus.h"
#include "Matcher.h"
#include <chrono>
#include "BruteForceMatcher.h"
#include "RabinKarpMatcher.h"
#include "kmpMatcher.h"
#include "BooyerMooreMatcher.h"
using namespace std;
int main () {
    
       Corpus corpus;
    Document doc;
    doc.createFromFile("First essay");
    corpus.addDocument(doc);
    
    doc.createFromFile("Second essay");
    corpus.addDocument(doc);
    
    doc.createFromFile("Third essay");
    corpus.addDocument(doc);
    
    doc.createFromFile("Fourth essay");
    corpus.addDocument(doc);
    
    Document testdoc;
    
    testdoc.createFromFile("Testdocpl");
    


    

    BruteForceMatcher bruteForceMatcher;
    RabinKarpMatcher rabinKarpMatcher;
    kmpMatcher kmpMatcher;
    BooyerMooreMatcher booyerMooreMatcher;

    vector<string> bfMatches = bruteForceMatcher.match (testdoc , corpus);
    vector<string> rkMatches = rabinKarpMatcher.match (testdoc , corpus);
    vector<string> kmpMatches = kmpMatcher.match (testdoc , corpus);
    vector<string> bmMatches = booyerMooreMatcher.match (testdoc , corpus);
    // Compare the results of the two algorithms
    std::cout << "The titles of the documents that were plagarized (As detected by brute force):" << std::endl;
    for (vector<string>::iterator itr = bfMatches.begin ();itr != bfMatches.end ();itr++)
    {
        std::cout << *itr << std::endl;
    }
    std::cout << "The titles of the documents that were plagarized (As detected by brute force):" << std::endl;
    for (vector<string>::iterator itr = rkMatches.begin ();itr != bfMatches.end ();itr++)
    {
        std::cout << *itr << std::endl;
    }
    std::cout << "The titles of the documents that were plagarized (As detected by brute force):" << std::endl;
    for (vector<string>::iterator itr = kmpMatches.begin ();itr != bfMatches.end ();itr++)
    {
        std::cout << *itr << std::endl;
    }
    std::cout << "The titles of the documents that were plagarized (As detected by brute force):" << std::endl;
    for (vector<string>::iterator itr = bmMatches.begin ();itr != bfMatches.end ();itr++)
    {
        std::cout << *itr << std::endl;
    }
    // Compare the time it takes to run each algorithm
    auto start = chrono::high_resolution_clock::now ();
    bruteForceMatcher.match (testdoc , corpus);
    auto end = chrono::high_resolution_clock::now ();
    auto bfDuration = chrono::duration_cast<chrono::microseconds>(end - start).count ();
    cout << "The brute Force took :" << bfDuration << " ms" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    rabinKarpMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
    auto rkDuration = chrono::duration_cast<chrono::microseconds>(end - start).count ();
    cout << "The rabin karp took :" << rkDuration << " ms" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    kmpMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
    auto kmpDuration = chrono::duration_cast<chrono::microseconds>(end - start).count ();
    cout << "The KMP took :" << kmpDuration << " ms" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    booyerMooreMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
    auto bmDuration = chrono::duration_cast<chrono::microseconds>(end - start).count ();
    cout << "The Booyer Moore took :" << bfDuration << " ms" << " to excute" << endl;
    Document doubledtestdoc;
    doubledtestdoc.setTitle ("doubleTestDoc");
    doubledtestdoc.setContent (testdoc.getContent () + testdoc.getContent ());
    Corpus doubledCorpus;
    for (vector<Document>::iterator itr = corpus.getDocuments().begin ();itr != corpus.getDocuments().end ();itr++)
    {
        Document tempdoc;
        tempdoc.setTitle (itr->getTitle ());
        tempdoc.setContent (itr->getContent () + itr->getContent ());
        doubledCorpus.addDocument (tempdoc);
    }
    start = chrono::high_resolution_clock::now ();
    bruteForceMatcher.match (testdoc , corpus);
     end = chrono::high_resolution_clock::now ();
     bfDuration = chrono::duration_cast<chrono::microseconds>(end - start).count ();
    cout << "The brute Force took :" << bfDuration << " ms" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    rabinKarpMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
     rkDuration = chrono::duration_cast<chrono::microseconds>(end - start).count ();
    cout << "The rabin karp took :" << rkDuration << " ms" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    kmpMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
     kmpDuration = chrono::duration_cast<chrono::microseconds>(end - start).count ();
    cout << "The KMP took :" << kmpDuration << " ms" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    booyerMooreMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
     bmDuration = chrono::duration_cast<chrono::microseconds>(end - start).count ();
    cout << "The Booyer Moore took :" << bfDuration << " ms" << " to excute" << endl;

    cout << "The Brute Force object is taking " << bruteForceMatcher.getMemoryUsage () << " bytes from memory" << endl;
    cout << "The rabin karp object is taking " << rabinKarpMatcher.getMemoryUsage () << " bytes from memory" << endl;
    cout << "The KMP object is taking " << kmpMatcher.getMemoryUsage () << " bytes from memory" << endl;
    cout << "The Booyer Moore object is taking " << booyerMooreMatcher.getMemoryUsage () << " bytes from memory" << endl;
    return 0;
}
