#include <bits/stdc++.h>
#include <ios>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

int set_states(ll pos, vector<ll> &L, vector<ll> &R, vector<uint8_t> &S,
               vector<ll> &T) {
  if ((!L[pos - 1])) { // leaf
    return 0;
  } else if (!S[pos - 1]) { // Nothing
    S[pos - 1] = 1;         // set left
    T[pos - 1] = set_states(L[pos - 1], L, R, S, T) + 2;

  } else if (S[pos - 1] == 1) { // Left
    S[pos - 1] = 2;             // set right
    T[pos - 1] = set_states(R[pos - 1], L, R, S, T) + 2;
  } else {          // Right
    S[pos - 1] = 0; // Set empty
    return T[pos - 1];
  }
  return set_states(pos, L, R, S, T) + 2;
}

int main() {
  ios_base::sync_with_stdio();
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> L(n, 0), R(n, 0), T(n), P(n);
    // Vectors for left, right, time to run through its nodes and its parent
    vector<uint8_t> S(n);
    // State of node. 0 is nothing, 1 is left, 2 is right
    rep(i, 0, n) {
      ll i_L, i_R;
      cin >> i_L >> i_R;
      L[i] = i_L;
      R[i] = i_R;
      if (i_L)
        P[i_L] = i + 1;
      if (i_R)
        P[i_R] = i + 1;
    }

    set_states(1, L, R, S, T);
    rep(i, 0, n) { cout << T[i]; }
  }
}
