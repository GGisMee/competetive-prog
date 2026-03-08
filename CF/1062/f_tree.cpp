#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

struct Node {
private:
  vector<Node> neighbours;
  int value;

private:
  Node(int value) { this->value = value; };
  void add_child(Node child) { this->neighbours.push_back(child); }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> u(n - 1), v(n - 1);
    rep(i, 0, n - 1) { cin >> u[i] >> v[i]; };
  }
}
