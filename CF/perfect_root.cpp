#include <bits/stdc++.h> // Innehåller allt
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < b; i++)

int main() {
  int t;
  int n;
  cin >> t;
  rep(i, 0, t) {
    cin >> n;
    rep(j, 0, n) { cout << j + 1 << endl; }
  }
}
