#include <bits/stdc++.h>
typedef unsigned int uint;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define revrep(i, a, b) for (int i = b - 1; i >= a; i--)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> p;

    int m = 0;
    int i_m = 0;
    rep(i, 0, n) {
      cin >> p[i];
      m = max(p[i], m);
    }
  }
}
