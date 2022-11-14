#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(std::move(w)), meaning(std::move(m)) {}

string WordMean::getWord() const {return word;}

string WordMean::getMeaning() const {return meaning;}

void WordMean::setMeaning(string m) {meaning = std::move(m);}

void WordMean::setWord(string w) {word = std::move(w);}

set<WordMean> Dictionary::getWords() const {return words;}

void Dictionary::addWord(const WordMean& wm)  {words.insert(wm);}

// ---------------------------------------------

//TODO
bool WordMean::operator< (const WordMean& wm2) const {

     return true;
}


//TODO
void Dictionary::readFile(ifstream &f) {

}

//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {

    return "";
}

//TODO
bool Dictionary::update(string w1, string m1) {

    return true;
}

//TODO
void Dictionary::print() const {

}
