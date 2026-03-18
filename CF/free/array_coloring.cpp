#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<bool> b(n);
    int v;
    bool color_red = true;
    rep(i, 0, n) {
      cin >> v;
      b[v - 1] = color_red; // Byter till varannan
      color_red = !color_red;
    }
    bool following = false;
    rep(v, 1, n) {
      if (b[v] == b[v - 1]) {
        following = true;
        break;
      }
    }
    cout << ((following) ? "NO\n" : "YES\n");
  }
}
