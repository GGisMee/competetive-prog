
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define revrep(i, a, b) for (int i = b - 1; i >= a; i--)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  int n, s, x;
  int s_a;
  int a_i;
  while (t--) {
    cin >> n >> s >> x;
    s_a = 0;
    rep(i, 0, n) {
      cin >> a_i;
      s_a += a_i;
    }
    if (((s - s_a) % x == 0) && s >= s_a) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
