#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

bool bob_won(ll p, ll q) {
  bool c1 = 2 * q <= 3 * p;
  bool c2 = q >= 1 + p;
  return c1 && c2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll p, q;
    cin >> p >> q;
    cout << (bob_won(p, q) ? "Bob\n" : "Alice\n");
  }
}
