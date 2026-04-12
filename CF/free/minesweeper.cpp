
#include <bits/stdc++.h>
#include <ios>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main() {
  ios_base::sync_with_stdio();
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll k;
    cin >> k;
    ll fives = 0;
    bool begin_three = false;
    bool end_three = false;

    if (k == 1) {
      cout << "YES\n1\n*\n.\n";
      continue;
    }

    while (k >= 10) {
      k -= 5;
      ++fives;
    }
    if (k == 8) {
      ++fives;
      begin_three = true;
    } else if (k == 6) {
      begin_three = true;
      end_three = true;
    } else if (k == 5) {
      ++fives;
    } else if (k == 3) {
      begin_three = true;
    } else {
      cout << "No\n";
      continue;
    }
    cout << "YES\n";

    ll lines = fives * 3 + begin_three * 2 + end_three * 2;
    cout << lines << '\n';
    if (begin_three) {
      cout << "*.";
    }
    while (fives--) {
      cout << ".*.";
    }
    if (end_three) {
      cout << ".*";
    }
    cout << '\n' << string(lines, '.') << '\n';
  }
}
