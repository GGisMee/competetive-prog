#include <bits/stdc++.h>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

// 1
// 8
// ((())())
//
// 1
// 10
// ((()())())

//

// ll find_sub(vector<bool> b, ll n) {
//   ll pos = 0;    // index position in b
//   ll needed = 1; // Number of brackets needed in subsequence
//   rep(i, 0, n) {
//     if (!b[i]) // ) parantes
//       break;
//     else // ( parantes
//       ++needed;
//   }
//   pos = needed;
//
//   bool last_l_found = false;
//   rep(i, pos, n) {
//     if (b[i]) {
//       last_l_found = true;
//       pos = i + 1;
//       break;
//     }
//   }
//   if (!last_l_found)
//     return -1;
//
//   ll r_found = 0;
//   rep(i, pos, n) {
//     if (!b[i]) {
//       ++r_found;
//       if (r_found == needed) {
//         return 2 * needed;
//       }
//     }
//   }
//   return -1;
// }

ll find_sub(vector<bool> b, ll n) {
  ll needed = 0; // Needed
  rep(i, 0, n) {
    if (!b[i]) { // )
      break;
    }
    ++needed;
  }
  ll max_found = 0;
  ll current = needed - 1;
  rep(i, needed + 1, n) {
    max_found = max(current, max_found);
    if (b[i])
      ++current;
    else
      --current;
  }
  return (max_found > needed) ? 2 * max_found : -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<bool> b(n);
    rep(i, 0, n) {
      char c;
      cin >> c;
      b[i] = (c == '(');
    }
    cout << find_sub(b, n) << '\n';
  }
}
