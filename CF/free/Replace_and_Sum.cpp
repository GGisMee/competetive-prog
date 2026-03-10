#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define revrep(i, a, b) for (int i = b - 1; i >= a; i--)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);

    rep(i, 0, n) { cin >> a[i]; }
    rep(i, 0, n) { cin >> b[i]; }

    rep(i, 0, n) { a[i] = max(a[i], b[i]); }
    revrep(i, 1, n) { a[i - 1] = max(a[i - 1], a[i]); }

    vector<int> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    int s = 0;
    rep(i, 1, n + 1) {
      s += a[i - 1];
      prefix_sum[i] = s;
    }

    int l, r;
    rep(i, 0, q) {
      cin >> l >> r;
      cout << prefix_sum[r] - prefix_sum[l - 1] << ' ';
    }
    cout << endl;
  }
}
