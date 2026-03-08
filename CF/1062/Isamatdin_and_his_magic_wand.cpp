#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)

// Felaktig kod!
// void quick_sort(ll l, ll h, vector<ll> &idxs, vector<ll> &v) {
//   // l,h idx till idxs listan.
//   // idxs är indexes till de värden i v som vi ska sortera. Obs idxs listan
//   är
//   // sorterad v är lista med värden
//   if (l >= h) {
//     return;
//   }
//
//   ll b = l + 1; // pointer to beginning
//   ll pivot = v[idxs[l]];
//   rep(i, l + 1, h + 1) {
//     if (v[idxs[i]] < pivot) { // mindre så ska mot början
//       // Swappa el b och i;
//       swap(v[idxs[i]], v[idxs[b]]);
//       ++b;
//     }
//   }
//   // Nu är pivot i början, så vi flyttar den i mitten.
//   // b-1 ty den vet vi är mindre än pivot
//   swap(v[idxs[l]], v[idxs[b - 1]]);
//   quick_sort(l, b - 2, idxs, v);
//   quick_sort(b + 1, h, idxs, v);
// }

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n; // number of elements
    cin >> n;

    vector<ll> a(n);
    rep(i, 0, n) { cin >> a[i]; }

    bool even_and_odd = false;
    rep(i, 1, n) {
      if ((a[0] % 2) != (a[i] % 2)) { // even and odd
        even_and_odd = true;
      };
    }

    if (even_and_odd) {
      sort(a.begin(), a.end());
    }
    rep(i, 0, n) { cout << a[i] << " "; }
    cout << endl;
  }
}
