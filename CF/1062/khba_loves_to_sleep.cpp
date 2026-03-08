#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

// 1
// 4 1 4
// 1 0 2 4

// 1
// 5 5 4
// 0 1 2 3 4

// 1
// 2 1 4
// 4 0

// 1
// 3 4 6
// 2 4 3
ll fits(ll D, vector<ll> &a, vector<int> &p) {
  // How many points fit between a given that distance D is to be held

  // Till början

  rep(i, 0, a[0] - D + 1) { p[i] = 1; }

  for (ll i = 0; i < a.size() - 1; i++) {
    rep(j, a[i] + D, a[i + 1] - D + 1) { p[j] = 1; }
  }
  rep(i, a.back() + D, p.size() - D) { p[i] = 1; }
  return count(p.begin(), p.end(), 1);
}

void bin_search(vector<ll> &a, vector<int> &p, const ll k) {
  ll l = 0;
  ll h = p.size() - 1;
  ll best_D = -1;

  while (l <= h) {
    fill(p.begin(), p.end(), 0);
    ll D = l + (h - l) / 2; // mittvärde
    ll s = fits(D, a, p);   // possible number of points for D
    if (s > k) {
      best_D = D;
      l = D + 1;
    } else if (s < k) {
      h = D - 1;
    } else {
      best_D = D;
      break;
    }
  }

  fill(p.begin(), p.end(), 0);
  fits(best_D, a, p);
}

void print_points(vector<int> &p) {
  rep(i, 0, p.size()) {
    if (p[i] == 1) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;

    vector<ll> a(n);
    rep(i, 0, n) { cin >> a[i]; }
    sort(a.begin(), a.end());
    vector<int> p(x + 1);

    bin_search(a, p, k);
    print_points(p);
  }
}
