#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
// 1
// 8
// 3 2 2 3 7 3 6 7

// 1
// 10
// 2 1 2 1 3 5 5 7 7 7

// lägger till värden i dist under max_val
void populate(vector<int> &dist, vector<int> &a, int stop) {
  rep(i, 1, stop / a[0] + 1) { // Vi multiplicerar med värden >= a[0]
    if (dist[i] == -1) {
      continue;
    }
    for (int a_j : a) {
      int m = a_j * i;
      if (m > stop) {
        break;
      } else if (dist[m] == -1) {
        dist[m] = dist[a_j] + dist[i];
      } else {
        dist[m] = min(dist[a_j] + dist[i], dist[m]);
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) { cin >> a[i]; }

    vector<int> dist(n + 1, -1); // vektor med avstånd till tal

    // Sort and remove duplicates
    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    for (int a_i : a) {
      dist[a_i] = 1;
    }
    populate(dist, a, n);
    rep(i, 1, n + 1) { cout << dist[i] << ' '; }
    cout << '\n';
  }
}
