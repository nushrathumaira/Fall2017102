#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>

#include "Card.hpp"

using namespace std;

class Deck {

  private:
    vector<Card> cards;
    void build_deck();

  public:
    Deck ();
    ~Deck ();

    int num_cards() const;

    void shuffle();
    void reset();
    Card draw();
    vector<Card> draw(int num);

    string print();
};

#endif
