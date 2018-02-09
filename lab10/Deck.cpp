#include "Deck.hpp"

void Deck::build_deck() {
  for(int i = 0; i < 52; i++) {
    auto value = (i%13)+2;
    auto suit = Card::Suit::HEARTS;
    switch (i%4) {
      case 0: suit = Card::Suit::HEARTS; break;
      case 1: suit = Card::Suit::SPADES; break;
      case 2: suit = Card::Suit::CLUBS; break;
      case 3: suit = Card::Suit::DIAMONDS; break;
    }
    this->cards.push_back(Card(value, suit));
  }
}

Deck::Deck() { build_deck(); }
Deck::~Deck() {}

void Deck::reset() {
  this->cards.clear();
  this->build_deck();
}

void Deck::shuffle() {
  random_shuffle(this->cards.begin(), this->cards.end());
}

int Deck::num_cards() const { return this->cards.size(); }

Card Deck::draw() {
  Card dealt = this->cards.back();
  this->cards.pop_back();
  return dealt;
}

vector<Card> Deck::draw(int num) {
  vector<Card> dealt;
  int i = 0;
  while (i < num && this->num_cards() > 0) {
    dealt.push_back(this->cards.back());
    this->cards.pop_back();
    i++;
  }
  return dealt;
}

string Deck::print() {
  stringstream ss;

  ss << "Deck has " << this->num_cards() << " cards" << endl;

  for(int i = 0; i < this->num_cards(); i++) {
    if ( i%13 == 0 && i != 0) { ss << endl; }
    ss << setw(6) << right
       << this->cards[i].print();
  }

  ss << endl;
  return ss.str();
}
