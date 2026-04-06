#include <bits/stdc++.h>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ull i = a; i < b; i++)

ull eval_wood(ull m, ull N, vector<ull> v, vector<ull> t) {
  ull wood = 0;
  rep(i, 0, N) { wood += min(m, t[i]) * v[i]; }
  return wood;
}

// Searches for smaullest t_0, such that needed_wood<t_0.
ull bin_search(ull N, ull t_max, ull needed_wood, vector<ull> v,
               vector<ull> t) {
  ull l = 0;
  ull h = t_max;
  ull m;
  while (l < h) {
    m = l + (h - l) / 2;
    ull m_val = eval_wood(m, N, v, t);
    if (needed_wood <= m_val) {
      h = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ull N, S;
  cin >> N >> S;
  vector<ull> v(N), t(N);
  ull start_wood = 0;
  ull wood_tree;
  ull t_max = 0;
  rep(i, 0, N) {
    cin >> wood_tree >> v[i] >> t[i];
    t_max = max(t_max, t[i]);
    start_wood += wood_tree;
  }
  // Finns redan tillräckligt med trä
  if (S < start_wood) {
    cout << 0;
    return;
  }
  ull t_sought = bin_search(N, t_max, S - start_wood, v, t);
  cout << t_sought;
}
