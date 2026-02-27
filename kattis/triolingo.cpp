#include <bits/stdc++.h> // Innehåller allt
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define rep(i, a, b) for (ull i = a; i < b; i++)

int main() {
  ull N;
  cin >> N;
  ull s_im1 = 1;
  ull s_i = 2;
  ull temp;

  if (N == 1) {
    cout << 1;
    return 0;
  } else if (N == 2) {
    cout << 2;
    return 0;
  }

  rep(i, 2, N) {
    temp = s_i;
    s_i += s_im1 + 1;
    s_im1 = temp;
  }
  cout << s_i;
}
