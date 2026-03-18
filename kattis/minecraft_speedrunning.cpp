#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < b; i++)

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  ll N, S;
  cin >> N >> S;
  // x - position portal in nether
  // t - time to fix portal
  vector<ll> x(N), t(N);
  rep(i, 0, N) { cin >> x[i] >> t[i]; }
  // time to reach portal i in nether and overworld
  ll t_nether = x[0] * 8 + t[0]; // tid att ta sig till nether genom första
  ll t_overw = x[0];

  int i = 1;
  while (i != N && (8 * x[i] > S)) { // tills vi är vid portalen innan S
    // från förra portal i nether till nuvarande eller från overworld upp till
    // nuvarande
    t_nether = min(t_nether + (x[i] - x[i - 1]), x[i] * 8 + t[i]);
    t_overw =
        min(t_nether + t[i], x[i] * 8); // Från nether eller rakt från spawn
    ++i;
  }
  // i är portal innan S
  if (i == N) {                               // S ej mellan portaler
    cout << t_overw + 8 * (S - x[i]) << '\n'; // Ta sig till S.
  } else {
    // Tid till portal i overworld som är efter S
    ll t_overw_over = t_nether + (x[i + 1] - x[i]) + t[i + 1];
    // Minsta mellan portal över och under
    ll t = min(t_overw + (S - x[i]), t_overw_over + (x[i + 1] - S));
    cout << t << '\n';
  }
}
