#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <functional>

enum class Suit {
  HEART, DIAMOND, CLUB, SPADE
};

Suit get_suit_from_string(const std::string &s) {
  assert(s.size() == 2);

  switch (s[1]) {
    case 'H':
      return Suit::HEART;
    case 'D':
      return Suit::DIAMOND;
    case 'C':
      return Suit::CLUB;
    case 'S':
      return Suit::SPADE;
  }

  assert(false);
}

int get_value_from_string(const std::string &s) {
  assert(s.size() == 2);

  switch (s[0]) {
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'T': return 10;
    case 'J': return 11;
    case 'Q': return 12;
    case 'K': return 13;
    case 'A': return 14;
  }

  assert(false);
}

struct Card {
  const Suit suit;
  const int value;

  Card(std::string s) :
    suit(get_suit_from_string(s)), value(get_value_from_string(s)) {}
};

struct Hand {
  const std::vector<Card> cards;

  Hand(const std::vector<Card> cards) : cards(cards) {
    assert(cards.size() == 5);
  }

  Card get_highest() const {
    auto highest = this->cards.begin();
    for (auto iter = this->cards.begin(); iter != this->cards.end(); iter++) {
      if (iter->value > highest->value) {
        highest = iter;
      }
    }
    return *highest;
  }
};

enum class RankResult {
  PLAYER1_WIN, PLAYER2_WIN, DRAW
};

void handle_hand(const Hand &a, const Hand &b) {
  typedef std::function<RankResult(const Hand&, const Hand&)> RankFunction;

  RankFunction high_card = [](const Hand &h1, const Hand &h2) {
    Card h1_highest = h1.get_highest();
    Card h2_highest = h2.get_highest();
    if (h1_highest.value == h2_highest.value) {
      return RankResult::DRAW;
    } else if (h2_highest.value > h1_highest.value) {
      return RankResult::PLAYER1_WIN;
    } else {
      return RankResult::PLAYER2_WIN;
    }
  };
}

int main() {
  std::ifstream file;
  file.open("p054_poker.txt");

  std::vector<Card> card_buffer;

  while (file.is_open()) {
    std::string input;
    file >> input;
    if (input == "") {
      break;
    }

    card_buffer.emplace_back(input);

    if (card_buffer.size() == 10) {
      handle_hand(
          Hand(std::vector<Card>(
              card_buffer.begin(),
              card_buffer.begin() + 5)),
          Hand(std::vector<Card>(
              card_buffer.begin() + 5,
              card_buffer.end())));
    }
  }

  file.close();
}

