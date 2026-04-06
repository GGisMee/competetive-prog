#include <bits/stdc++.h>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

ll min_moves(ll a, ll b, ll c, ll d) {
  ll moves = 0;

  // Lets reassign smaller tower as m and larger as M
  // and what it should reach as m_t and M_t
  ll m, M, m_t, M_t;
  if (a < b) {
    m = a;
    m_t = c;
    M = b;
    M_t = d;
  } else {
    m = b;
    m_t = d;
    M = a;
    M_t = c;
  }
  while (m != M && m < m_t) {
    ++m;
    ++moves;
  }
  while (m < m_t && M < M_t) {
    ++m;
    ++M;
    ++moves;
  }

  while (m < m_t) {
    ++m;
    ++moves;
  }

  while (M < M_t) {
    ++M;
    ++moves;
  }

  return moves;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min_moves(a, b, c, d) << '\n';
  }
}
