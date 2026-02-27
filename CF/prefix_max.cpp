#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

int get_max(vector<int> &vec) {
  int m = -1e9;
  for (int v : vec) {
    m = max(v, m);
  }
  return m;
}

int main() {
  int t;
  int n;
  int v;
  cin >> t;
  rep(i, 0, t) {
    vector<int> arr;
    cin >> n;
    rep(j, 0, n) {
      cin >> v;
      arr.push_back(v);
    }
    cout << get_max(arr) * n << endl;
  }
}
