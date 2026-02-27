#include <bits/stdc++.h> // Innehåller allt
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < b; i++)

int main() {
  int n = rand() % 2; // nummer: ett eller två
  int grader_inp;
  int won = 0;
  cout << endl;
  while (n < 100) {
    cin >> grader_inp; // userinput
    n += grader_inp;

    if (n == 99) { // user won
      won = 1;
      break;
    }
    if (n == 98) { // program chooses 99 if 98 before and wins
      won = 2;
      break;
    }
    n += rand() % 2;
    if (n == 99) {
      won = 2;
      break;
    }
  }
  cout << won;
}
