#include <bits/stdc++.h>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

// Returns next idx for new number after the one att idx i.
ll next_idx_num(ll i, vector<ll> &a, ll n) {
  ll v = a[i];
  rep(j, i + 1, n) {
    if (a[j] != v) {
      return j;
    }
  }
  return 0;
}

bool possible(vector<ll> p, vector<ll> &a, ll n) {
  ll num_idx = 0;
  rep(i, 0, n) {
    if (a[num_idx] == p[i]) {
      num_idx = next_idx_num(num_idx, a, n);
      if (num_idx == 0) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> p(n), a(n);
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> a[i];
    cout << (possible(p, a, n) ? "Yes" : "No") << '\n';
  }
}
