#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

// 1
// 8
// 3 2 2 3 7 3 6 7

// 1
// 5
// 1 2 3 4 5

int in_prod(int k, vector<int> &a) {
  int n = 0; // number in product
  bool changed = true;
  int prev;
  while (changed) {
    changed = false;
    for (int a_i : a) {
      if (a_i == 1) {
        if (k == 1) {
          return 1;
        }
      } else if ((k % a_i) == 0) {
        prev = k;
        k /= a_i;
        if (prev != k) {
          changed = true;
        }
        ++n;
        if (k == 1) {
          return n;
        }
      }
    }
  }
  return n;
}

int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) { cin >> a[i]; }

    // Sort and remove duplicates
    sort(a.begin(), a.end(), greater<>());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());
    rep(i, 1, n + 1) {
      int num = in_prod(i, a);
      if (num == 0) {
        cout << "-1 ";
      } else {
        cout << num << ' ';
      }
    }
    cout << '\n';
  }
}
