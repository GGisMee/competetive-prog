#include <bits/stdc++.h>
#include <ios>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

ll count_operations(vector<char> &b, ll n) {
  if (n < 2)
    return 0; // Inga par möjliga om n < 2

  ll ops = 0;
  // Starta på sista giltiga index i b: n - 2
  for (int i = n - 2; i >= 0; i--) {
    if (i > 0 && b[i] && b[i - 1]) {
      // Om vi har två intilliggande (i och i-1)
      ops++;
      i--; // Hoppa över nästa eftersom vi använde i-1
    } else if (b[i]) {
      // Ensam operation
      ops++;
    }
  }
  return ops;
}

int main() {
  ios_base::sync_with_stdio();
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<char> b(n - 1, 0); // alla ställen där operationer behövs
    rep(i, 0, n) { cin >> a[i]; }
    rep(i, 0, n - 1) { b[i] = ((a[i] + a[i + 1] == 7) || (a[i] == a[i + 1])); }

    cout << count_operations(b, n) << '\n';
  }
}
