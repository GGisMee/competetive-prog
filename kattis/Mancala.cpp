#include <array>
#include <bits/stdc++.h>
#include <cstdint>
#include <queue>
// #include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i, a, b) for (uint8_t i = a; i < b; i++)

// Takes index i in curr and plant seeds as instructed. Right if right, else
// left
array<uint8_t, 5> reorder(uint8_t i, bool right, array<uint8_t, 5> curr) {
  uint8_t v = curr[i]; // value of said bowl
  curr[i] = 0;         // empties it to then redestribute
  uint8_t idx;
  rep(j, 0, v) {
    // If 5 is exceded, it returns back to 0, same with negative values
    if (right) {
      idx = (i + j) % 5;
    } else {
      idx = ((i - j) % 5 + 5) % 5; // logic to make sure its 0,1,2,3,4
    }
    curr[idx] += 1;
  }
  return curr;
}

int BFS(array<uint8_t, 5> a, array<uint8_t, 5> b) {
  queue<array<uint8_t, 5>> q;
  set<array<uint8_t, 5>> visited;
  q.push(a);
  visited.insert(a);
  ll d_size = 1; // Indicator when next depth is reached
  ll d = 0;
  while (!q.empty() && d <= 6) {
    while (d_size--) {
      array<uint8_t, 5> curr = q.front();
      q.pop();
      if (curr == b) {
        return d;
      }
      rep(i, 0, 5) {
        if (curr[i] == 1) { // Gör inget
          continue;
        }
        auto n1 = reorder(i, 0, curr);
        if (visited.find(n1) == visited.end()) {
          visited.insert(n1);
          q.push(n1);
        }

        auto n2 = reorder(i, 1, curr);
        if (visited.find(n2) == visited.end()) {
          visited.insert(n2);
          q.push(n2);
        }
      }
    }
    d++;
    d_size = q.size();
  }
  return -1; // Nothing found
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  array<uint8_t, 5> a, b;
  rep(i, 0, 5) {
    int a_i;
    cin >> a_i;
    a[i] = static_cast<uint8_t>(a_i);
  }
  rep(i, 0, 5) {
    int b_i;
    cin >> b_i;
    b[i] = static_cast<uint8_t>(b_i);
  }
  cout << BFS(a, b);
}
