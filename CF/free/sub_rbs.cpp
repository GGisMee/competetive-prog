#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
// 1
// 8
// (())(())
ll find_sub(string &s, ll n) { // Använd string istället för vector<bool>
  ll needed = 1;
  while (needed < n && s[needed] == '(') {
    needed++;
  }

  if (needed == 0)
    return -1;

  ll num_l = 0;
  ll num_r = 0;
  rep(i, 0, n) {
    if (s[i] == ')')
      ++num_l;
  }
  ll M = 0;
  rep(i, 0, n) {
    if (s[i] == ')') {
      --num_l;
    } else {
      ++num_r;
    }
    M = max(M, min(num_r, num_l));
  }

  if (M > needed)
    return 2 * M;

  // edge case
  ll pos = -1;
  bool l_found = false;
  rep(i, needed + 1, n) {
    if (s[i] == '(' && !l_found) {
      l_found = true;
    }
    if (l_found) {
    }
  }

  return (M > needed) ? 2 * M : -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    cout << find_sub(s, n) << '\n';
  }
}
