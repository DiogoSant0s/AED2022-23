#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

unsigned int Game::numberOfWords(string phrase) {
  if (phrase.length() == 0) return 0;
  unsigned n = 1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {this -> kids.clear();}

Game::Game(list<Kid>& l2) {this -> kids = l2;}

void Game::addKid(const Kid& k1) {kids.push_back(k1);}

list<Kid> Game::getKids() const {return this -> kids;}

void Game::setKids(const list<Kid>& l1) {this -> kids = l1;}

//-----------------------------------------------------------------

// TODO
Kid Game::loseGame(const string& phrase) {
    while (kids.size() > 1) {
        unsigned int num = numberOfWords(phrase);
        while (num > 1) {
            Kid kid = kids.front();
            kids.pop_front();
            kids.push_back(kid);
            num--;
        }
        kids.pop_front();
    }
    return kids.front();
}

// TODO
list<Kid> Game::rearrange() {
    list<Kid> res;

    return res;
}

// TODO
list<Kid> Game::shuffle() const {
	list<Kid> newList;

	return newList;
}
