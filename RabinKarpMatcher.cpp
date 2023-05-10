/**
CS2 project: 2- Simple palagarism detection utility using string matching
*/

#include "RabinKarpMatcher.h"

vector<string> RabinKarpMatcher::match(const Document& testDoc, const Corpus& corpus) {
     vector<string> matches;
        vector<string> sentences = splitIntoSentences(testDoc);
        int prime = 1000000007; // choose a large prime number for the modulus operation
        for (const string& s : sentences) {
            int sHash = calculateHash(s, 0, s.size() - 1, prime);
            for (const Document& d : corpus.getDocuments()) {
                int dHash = calculateHash(d.getContent(), 0, s.size() - 1, prime);
                int base = 31; // choose a base for the hash function
                int powBase = 1; // store powers of base modulo prime
                for (int i = 0; i <= d.getContent().size() - s.size(); i++) {
                    if (dHash == sHash && isEqual(s, 0, s.size() - 1, d.getContent(), i, i + s.size() - 1)) {
                        if ( std::find(matches.begin(), matches.end(), d.getTitle()) == matches.end() )
                        matches.emplace_back (d.getTitle());
                    }
                    if (i < d.getContent().size() - s.size()) {
                        dHash = ((dHash - s[i] * powBase % prime) * base % prime + d.getContent()[i + s.size()]) % prime; // add modulus operation
                        if (dHash < 0) dHash += prime; // handle negative values after modulus
                        powBase = (powBase * base) % prime; // update power of base modulo prime
                    }
                }
            }
        }
        return matches;
    }
size_t RabinKarpMatcher::getMemoryUsage() {
    return sizeof(*this);
}

int RabinKarpMatcher::calculateHash(const string& str, int start, int end, int prime) {
   int hash = 0;
        int base = 31; // choose a base for the hash function
        int powBase = 1; // store powers of base modulo prime
        for (int i = start; i <= end; i++) {
            hash = (hash + (str[i] * powBase) % prime) % prime; // add modulus operation
            powBase = (powBase * base) % prime; // update power of base modulo prime
        }
        return hash;
    }

bool RabinKarpMatcher::isEqual(const string& str1, int start1, int end1, const string& str2, int start2, int end2) {
     if (end1 - start1 != end2 - start2) {
            return false;
        }
        for (int i = start1, j = start2; i <= end1 && j <= end2; i++, j++) {
            if (str1[i] != str2[j]) {
                return false;
            }
        }
        return true;
    }