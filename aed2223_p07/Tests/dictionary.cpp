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
bool WordMean::operator < (const WordMean& wm2) const {

     return true;
}


//TODO
void Dictionary::readFile(ifstream &f) {
    string word, meaning, textLine1, textLine2;
    while (getline(f, textLine1)) {
        word = textLine1;
        getline(f, textLine2);
        meaning = textLine2;
        addWord(WordMean(word, meaning));
    }
}

//TODO
string Dictionary::consult(const string& w1, WordMean& previous, WordMean& next) const {
    WordMean r(w1, "");
    auto i = words.begin();
    for (auto it = words.begin(); it != words.end(); it++) {
        it = i;
        if (it -> getWord() == w1) return it -> getMeaning();
        if (it -> getWord() > w1) break;
    }
    auto n = i;
    auto p = --i;
    if (p -> getWord().empty()) {
        previous.setWord("");
        previous.setMeaning("");
    }
    else {
        previous.setWord(p -> getWord());
        previous.setMeaning(p -> getMeaning());
    }
    if (n -> getWord().empty()) {
        next.setWord("");
        next.setMeaning("");
    }
    else {
        next.setWord(n -> getWord());
        next.setMeaning(n -> getMeaning());
    }
    return "word not found";
}

//TODO
bool Dictionary::update(string w1, string m1) {

    return true;
}

//TODO
void Dictionary::print() const {

}
