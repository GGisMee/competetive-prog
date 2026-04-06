#include <bits/stdc++.h>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

// 1
// 5
// -26 -32 -24 -4 2

void diff(vector<ll> &f, ll c, ll n) {
  ll f_0 = f[0];
  rep(i, 0, n - 1) f[i] -= f[i + 1];
  f.back() += f_0;
  f.back() /= c;
}

void get_coeff(vector<ll> &f, ll n) {
  diff(f, -n + 1, n);
  diff(f, -1, n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> f(n);
    rep(i, 0, n) { cin >> f[i]; }
    get_coeff(f, n);
    cout << f.back() / 2 << ' ';
    rep(i, 0, n - 1) { cout << f[i] / 2 << ' '; }
    cout << '\n';
  }
}
