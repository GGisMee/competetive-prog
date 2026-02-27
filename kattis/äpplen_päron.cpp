#include <bits/stdc++.h> // Innehåller allt
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < b; i++)

int main() {
  int A;
  int P;
  cin >> A >> P;
  A *= 7;
  P *= 13;
  if (A == P) {
    cout << "lika";
  } else if (A > P) {
    cout << "Axel";
  } else {

    cout << "Petra";
  }
}
