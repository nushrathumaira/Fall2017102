#include <iostream>
#include <algorithm>
#include "stdlib.h"

#include "Card.hpp"
#include "Deck.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  Deck player;

  player.shuffle();
  cout << player.print();

  cout << "Draw 5 cards" << endl;
  vector<Card> hand = player.draw(5);

  // const iterator for loop
  for (auto itr = hand.cbegin(); itr != hand.cend(); itr++) {
    cout << setw(6) << itr->print();
  }
  cout << endl;

  // C++11 const for each
  for (const Card& card : hand) {
    cout << setw(6) << card.print();
  }
  cout << endl;

  // C++11 const ref lambda for each
  for_each(hand.begin(), hand.end(), [](const Card& card) -> void {
    cout << setw(6) << card.print();
  });
  cout << endl;

  cout << player.print();

  return 0;
}
