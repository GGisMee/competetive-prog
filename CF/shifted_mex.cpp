#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev_rep(i, a, b) for (ll i = b - 1; i > a - 1; i--)

int mex(vector<ll> &arr, ll arr_len) {
  ll max_len = 1; // length of such sequence
  ll cur_len = 1;
  rep(i, 1, arr_len) {
    if (arr[i - 1] + 1 == arr[i]) { // är i sekvens
      cur_len += 1;
    } else if (arr[i - 1] + 1 < arr[i]) { // glapp
      cur_len = 1;
    }
    if (cur_len > max_len) { // vi har hittat en ny bästa sekvens
      max_len = cur_len;
    }
  }
  return max_len;
}

int main() {
  int t;
  cin >> t; // Antal listor att kolla på
  rep(i, 0, t) {
    int n; // Antal nummer
    cin >> n;
    vector<ll> arr;

    // appends numbers, change x to min value of arr
    rep(j, 0, n) {
      ll v;
      cin >> v;
      arr.push_back(v);
    }
    sort(arr.begin(), arr.end());
    cout << mex(arr, n) << endl;
  }
}
