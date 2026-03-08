
#include <bits/stdc++.h> // Innehåller allt
using namespace std;

typedef unsigned int uint;
#define rep(i, a, b) for (uint i = a; i < b; ++i)

void reset(vector<uint> &a, unordered_map<uint, uint> &changed) {
  // vi går igenom alla ändrade index och sätter till originalvärdena.
  for (const auto &[b_i, a_b_i_original] : changed) {
    a[b_i] = a_b_i_original;
  }
  changed.clear();
}

int main() {
  uint t;
  cin >> t;
  rep(j, 0, t) {
    uint n, m, h;
    cin >> n >> m >> h;

    vector<uint> a(n); // n st element ska den innehålla.

    unordered_map<uint, uint> changed;

    uint a_i;
    rep(i, 0, n) { cin >> a[i]; }

    rep(i, 0, m) {
      uint b_i, c_i;
      cin >> b_i >> c_i;
      --b_i; // Vi vill ha index, inte nummer
      // skapar key value pair om key inte finns
      changed.try_emplace(b_i, a[b_i]);

      a[b_i] += c_i;

      if (a[b_i] > h) {
        reset(a, changed); // resets values
      }
    }
    rep(i, 0, n) { cout << a[i] << " "; }
    cout << endl;
  }
}
