#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

int f(vector<int> &a, vector<int> &d) {
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

    while
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

    vector<int> d(n + 1, -1); // vektor med avstånd till tal

    // Sort and remove duplicates
    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    f(a, d);
  }
}
