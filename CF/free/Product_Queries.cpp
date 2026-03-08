#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
// 1
// 8
// 3 2 2 3 7 3 6 7

int f(vector<int> &a, vector<int> &dist) {
  if (a[0] == 1) {
    d[1] = 1;
  } else {
    d[1] = 0;
  }
  queue<int> q;

  for (int a_i : a) {
    // tömmer kön
    queue<int>().swap(q);

    rep(j, 2, a.size() + 1) { q.push(j); }

    int depth = 0; // multiples

    while (!q.empty()) {
      bool found = false;
      // I ett visst djup
      int level_size = q.size();
      rep(i, 0, level_size) {
        int d = q.front();
        q.pop();
        //
        if ((a_i % d) != 0) { // fel d som ej delar
          continue;
        } else if (dist[a_i] != -1) { // redan mappad;
          break;
        } else if (a_i / d == 1) {
          found = true;
          break;
        } else {
          q.push(a_i / d);
        }
      }
      if (found) {
        break;
      }
      ++depth;
    }
  }

  return 0;
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

    f(a, dist);
  }
}
