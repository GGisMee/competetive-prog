#include <bits/stdc++.h>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

bool check_and_sieve(ll n, ll a) {
  // 1. Skapa sållet (uint8_t för snabbhet)
  std::vector<uint8_t> is_prime(a, 1);
  is_prime[0] = is_prime[1] = 0;

  for (ll p = 2; p <= a; p++) {
    if (is_prime[p]) {
      // Vi itererar upp och tar bort alla delbara med den.
      for (ll i = p * p; i <= a; i += p)
        is_prime[i] = 0;

      // Custom logik för denna
      if ((n % p == 0) & (a % p == 0)) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    if (check_and_sieve(n, a) || check_and_sieve(m, b)) {
      cout << "NO\n";
    } else
      cout << "YES\n";
  }
}
