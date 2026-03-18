#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define revrep(i, a, b) for (int i = b - 1; i >= a; i--)

// 1
// 4
// 4 3 2 1

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> p(n);

    int start_idx = 0;
    rep(i, 0, n) { cin >> p[i]; }

    // Finn start_idx
    rep(i, 0, n) {
      if (p[i] != n - i) {
        start_idx = i;
        break;
      }
    }
    int m = 0;
    int i_m = 0;
    rep(i, start_idx, n) {
      if (p[i] > m) {
        m = p[i];
        i_m = i;
      }
    }

    rep(i, 0, start_idx) { cout << p[i] << ' '; }
    revrep(i, start_idx, i_m + 1) { cout << p[i] << ' '; }
    rep(i, i_m + 1, n) { cout << p[i] << ' '; }
    cout << '\n';
  }
}
