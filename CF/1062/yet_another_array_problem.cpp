#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

// 1
// 4
// 6 6 12 12

int a_i_divisible_prime(vector<ll> &a, int prime) {
  rep(i, 0, a.size()) {
    if (a[i] % prime) { // ej delbar
      return prime;
    }
  }
  return 0;
}

int check_primes(vector<ll> &a) {
  vector<bool> prime_idxs(26, true); // cieve

  int d = a_i_divisible_prime(a, 2);
  if (d != 0) {
    return 2;
  }

  int i = 1; // Skippar 1.
  while (true) {
    if (!prime_idxs[i]) { // ej primtal
      i++;
      continue;
    }
    int new_prime = 2 * i + 1; // Eftersom vi skippar de jämna
    d = a_i_divisible_prime(a, new_prime);
    if (d != 0) {
      return d;
    }

    rep(j, i + 1,
        26) { // sätter alla delbara med new_prime över new_prime till 0.
      if (((2 * j + 1) % new_prime) == 0) {
        prime_idxs[j] = false;
      }
    }
    i++;
  }

  return -1;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) { cin >> a[i]; }
    int x = check_primes(a);
    cout << x << '\n';
  };
}
