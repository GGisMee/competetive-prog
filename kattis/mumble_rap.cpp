#include <bits/stdc++.h> // Innehåller allt
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < b; i++)

int next_num(const string &input, int start) {
  // finner nästa nummer i input från index start och returnerar det indexet
  int idx = start;
  while (idx < input.length() && !isdigit(input[idx])) {
    // cout<<idx;
    idx++;
  }
  return idx;
}
int get_num(const string &input, int &idx) {
  // hämtar numret som finns efter indexet start
  string num;
  while (idx < input.length() && isdigit(input[idx])) {
    num += input[idx];
    idx++;
  }
  return stoi(num);
}

int main() {
  int N;
  int max_int = 0;
  string inp;
  cin >> N >> inp;

  int idx = next_num(inp, 0);
  while (idx != inp.length()) {
    int num = get_num(inp, idx);
    max_int = max(max_int, num);
    idx = next_num(inp, idx);
  }
  cout << max_int << "\n";
}
