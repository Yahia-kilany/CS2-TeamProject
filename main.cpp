#include <iostream>
#include "Document.h"
#include "Corpus.h"
#include "Matcher.h"
#include <iomanip>
#include <chrono>
#include "BruteForceMatcher.h"
#include "RabinKarpMatcher.h"
#include "kmpMatcher.h"
#include "BoyerMooreMatcher.h"
using namespace std;

int main () {
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision (2);

    Corpus corpus;
    Document doc;
    doc.createFromFile ("Corpus.txt");
    corpus.addDocument (doc);

    // doc.createFromFile ("Second essay.txt");
    // corpus.addDocument (doc);

    // doc.createFromFile ("Third essay.txt");
    // corpus.addDocument (doc);

    // doc.createFromFile("Fourth essay");
    // corpus.addDocument(doc);

    Document testdoc;

    testdoc.createFromFile ("Testdoc.txt");



    BruteForceMatcher bruteForceMatcher;
    RabinKarpMatcher rabinKarpMatcher;
    kmpMatcher kmpMatcher;
    BoyerMooreMatcher boyerMooreMatcher;

    map<string , double> rkMatches = rabinKarpMatcher.match (testdoc , corpus);
    map<string , double> bfMatches = bruteForceMatcher.match (testdoc , corpus);
    map<string , double> kmpMatches = kmpMatcher.match (testdoc , corpus);
    map<string , double> bmMatches = boyerMooreMatcher.match (testdoc , corpus);

    // Compare the results of the two algorithms
    std::cout << "The titles of the documents that were plagarized (As detected by brute force):" << std::endl;
    for (map<string , double>::iterator itr = bfMatches.begin ();itr != bfMatches.end ();itr++)
    {
        std::cout << itr->first << " was plagarised by " << itr->second << "%" << std::endl;
    }
    cout<<endl<<endl;
    std::cout << "The titles of the documents that were plagarized (As detected by Rabin Karp):" << std::endl;
    for (map<string , double>::iterator itr = rkMatches.begin ();itr != rkMatches.end ();itr++)
    {
        std::cout << itr->first << " was plagarised by " << itr->second << "%" << std::endl;
    }
    cout<<endl<<endl;
    std::cout << "The titles of the documents that were plagarized (As detected by KMP):" << std::endl;
    for (map<string , double>::iterator itr = kmpMatches.begin ();itr != kmpMatches.end ();itr++)
    {
        std::cout << itr->first << "was plagarised by " << itr->second << "%" << std::endl;
    }cout<<endl<<endl;
    std::cout << "The titles of the documents that were plagarized (As detected by Booyer Moore):" << std::endl;
    for (map<string , double>::iterator itr = bmMatches.begin ();itr != bmMatches.end ();itr++)
    {
        std::cout << itr->first << " was plagarised by " << itr->second << "%" << std::endl;
    }
    cout<<endl<<endl;
    auto start = chrono::high_resolution_clock::now ();
    bruteForceMatcher.match (testdoc , corpus);
    auto end = chrono::high_resolution_clock::now ();
    auto bfDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count ();
    cout << "The brute Force took :" << bfDuration << " nanoseconds" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    rabinKarpMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
    auto rkDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count ();
    cout << "The rabin karp took :" << rkDuration << " nanoseconds" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    kmpMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
    auto kmpDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count ();
    cout << "The KMP took :" << kmpDuration << " nanoseconds" << " to excute" << endl;
    start = chrono::high_resolution_clock::now ();
    boyerMooreMatcher.match (testdoc , corpus);
    end = chrono::high_resolution_clock::now ();
    auto bmDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count ();
    cout << "The Booyer Moore took :" << bmDuration << " nanoseconds" << " to excute" << endl;
    cout<<endl;
    cout<<"The brute force object ocuppies " <<bruteForceMatcher.getMemoryUsage()<<" bytes from memory"<<endl;
    cout<<"The rabin karp object ocuppies " <<rabinKarpMatcher.getMemoryUsage()<<" bytes from memory"<<endl;
    cout<<"The kmp object ocuppies " <<kmpMatcher.getMemoryUsage()<<" bytes from memory"<<endl;
    cout<<"The boyer moore object ocuppies" <<boyerMooreMatcher.getMemoryUsage()<< " bytes from memory"<<endl;
    return 0;
}
