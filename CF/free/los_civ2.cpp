#include <bits/stdc++.h>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

ll shorten(const vector<ll> &a, ll n) {
  ll l = 1;
  ll hook_idx = 0;

  // 2. Performance optimization: Enkel linjär scan O(n)
  for (ll i = 1; i < n; ++i) {
    if (a[i] <= a[hook_idx] || a[i] > a[i - 1] + 1) {
      ++l;
      hook_idx = i;
    }
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) { cin >> a[i]; }
    ll l = shorten(a, n);
    cout << l << '\n';
  }
}
