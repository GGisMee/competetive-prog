#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rev_rep(i, a, b) for (ll i = b - 1; i > a - 1; i--)

// Search for k in l, h with binary search
int bin_search(ll l, ll h, ll k, vector<ll> &v) {
  ll mid = (l + h) / 2; // blir floor genom int konvertering

  // Vi skippar v[mid]==k, då vi vet att spik och robot ej på samma

  if (l == h) {
    return mid;
  } else if (k < v[mid]) {
    return bin_search(l, mid, k, v);
  } else {
    return bin_search(mid + 1, h, k, v);
  }
}

int main() {
  ll t;
  cin >> t;

  while (t--) {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n); // robots
    rep(i, 0, n) cin >> a[i];

    vector<ll> b(m); // spikes
    rep(i, 0, m) cin >> b[i];
    sort(b.begin(), b.end()); // sorterar för bin_search sen

    string s;
    cin >> s;

    vector<ll> l_spike_d; // left spike distance
    vector<ll> r_spike_d; // right spike distance
    ll prev_l_spike_idx = 0;

    for (ll a_i : a) {
      ll closest_spike_idx = bin_search(prev_l_spike_idx, m - 1, a_i, b);
      if (a_i < b[closest_spike_idx]) {
        --closest_spike_idx; // vi vill att closest_spike_idx ska vara den under
      }
      // Lägger till avstånden
      if (closest_spike_idx >= 0) {
        l_spike_d.push_back(a_i - b[closest_spike_idx]);
      } else {
        l_spike_d.push_back(1e7); // Något som aldrig blir 0;
      }

      if (closest_spike_idx <
          m - 1) { // Mindre än slutindex, ty annars hamnar den utanför
        r_spike_d.push_back(a_i - b[closest_spike_idx + 1]);
      } else {
        r_spike_d.push_back(1e7);
      }

      // Makes sure that lower pointer is atleast 0
      closest_spike_idx = max(0ll, closest_spike_idx);
      prev_l_spike_idx = closest_spike_idx;
    }
    ll len_robots = n - 1;

    for (char &C : s) {  // För varje steg
      ll i = len_robots; // Sista index
      ll add = (C == 'L') ? -1 : 1;
      while (i >= 0) { // Flytta alla robotar och se om de förstörs
        l_spike_d[i] += add;
        r_spike_d[i] += add;
        if (l_spike_d[i] == 0 || r_spike_d[i] == 0) {
          l_spike_d[i] += 1e7; // radera, fast mindre resurskrävande
          r_spike_d[i] += 1e7; // radera fast mindre resurskrävnade
          --len_robots;
        }
        --i;
      }
      cout << len_robots + 1 << " " << flush;
    }
    cout << endl;
  }
}
