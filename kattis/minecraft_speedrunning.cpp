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
  ll t_overw_under, t_overw_over;

  int i = 1;
  while (i < N) {
    if (8 * x[i] > S) {
      in_between = true;
      t_overw_under = t_nether + t[i];
      t_nether = min(t_nether, x[i] * 8 + t[i]);
      t_overw_over = t_nether + t[N - 1]; // We reached the last
      break;
    }
    t_nether = min(t_nether, x[i] * 8 + t[i]);
  }
}
