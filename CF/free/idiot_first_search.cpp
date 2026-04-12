#include <bits/stdc++.h>
#include <ios>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// This function traverses through the tree and sets the time to go through
// everything beneith node
int set_time_part(ll pos, vector<ll> &L, vector<ll> &R, vector<ll> &T) {
  if (!L[pos - 1]) { // leaf
    T[pos - 1] = 0;
    return 0;
  }

  T[pos - 1] += set_time_part(L[pos - 1], L, R, T) + 2;
  T[pos - 1] += set_time_part(R[pos - 1], L, R, T) + 2;
  return T[pos - 1];
}

// This function sets the time for each node to traverse its subtree and larger
// subtrees above
void set_time_up(ll prev_val, ll pos, vector<ll> &L, vector<ll> &R,
                 vector<ll> &T) {
  T[pos - 1] += prev_val % 1000000007;
  if (L[pos - 1]) {
    set_time_up(T[pos - 1] + 1, L[pos - 1], L, R, T);
    set_time_up(T[pos - 1] + 1, R[pos - 1], L, R, T);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> L(n, 0), R(n, 0), T(n);
    // Vectors for left, right, time to run through its nodes and its parent
    rep(i, 0, n) {
      ll i_L, i_R;
      cin >> i_L >> i_R;
      L[i] = i_L;
      R[i] = i_R;
    }

    set_time_part(1, L, R, T);
    set_time_up(1, 1, L, R, T);
    rep(i, 0, n) { cout << T[i] % 1000000007 << ' '; }
    cout << '\n';
  }
}
