#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define revrep(i, a, b) for (int i = b - 1; i >= a; i--)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  string s;
  bool b;

  while (t--) {
    cin >> n;
    cin >> s;

    // Number of zeros in str
    int tot_z = 0;
    for (char C : s) {
      tot_z += (C == '0');
    }

    vector<int> i_s; // Sequence of indicies to move
    rep(i, 0, n) {
      if (i < tot_z) { // Space for zeros
        if (s[i] == '1') {
          i_s.push_back(i);
        }
      } else {
        if (s[i] == '0') {
          i_s.push_back(i);
        }
      }
    }
    if (i_s.empty()) { // Redan sorterad. Bob
      cout << "Bob\n";
    } else {
      cout << "Alice\n" << i_s.size() << '\n';
      for (int i : i_s) {
        cout << i + 1 << ' ';
      }
    }
  }
}
