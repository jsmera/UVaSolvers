#include <vector>
#include <stack>
#include <iterator>
#include <cstdio>

using namespace std;

struct Card {
  char range;
  char suit;
};

bool canStack(const Card& c1, const Card& c2) {
  return (c1.range == c2.range || c1.suit == c2.suit);
}

int main() {
  char card[2];
  int nCards = 0;
  vector< stack<Card> > cards;

  while(scanf("%s", &card)) {
    if ( card[0] == '#' ) break;
    cards.clear();
    stack<Card> temp;
    temp.push(Card{card[0], card[1]});
    cards.push_back(temp);

    for (int i = 0; i < 51; i++) {
      scanf("%s", &card);
      stack<Card> temp;
      temp.push(Card{card[0], card[1]});
      cards.push_back(temp);
      
      for (int i = 0; i < cards.size(); i++) {
        if (i >= 3 && canStack(cards[i-3].top(), cards[i].top()) ) {
          cards[i-3].push( cards[i].top() );
          cards[i].pop();
          if (cards[i].empty()) cards.erase(cards.begin()+i);
          i-=4;
        }
        else if (i >= 1 && canStack( cards[i-1].top(), cards[i].top() ) ) {
          cards[i-1].push( cards[i].top() );
          cards[i].pop();
          if (cards[i].empty()) cards.erase(cards.begin()+i);
          i-=2;
        }
        else continue;
      }
    }
    printf("%d pile%s remaining:", cards.size(), (cards.size() == 1 ? "": "s"));
    for (int i = 0; i < cards.size(); i++) {
      printf(" %d", cards[i].size());
    }
    printf("\n");
  }

  return 0;
}
