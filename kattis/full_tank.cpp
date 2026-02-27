#include <bits/stdc++.h> // Innehåller allt
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < b; i++)

int main() {
  // Vi vet att Kpl är konstant, så vi är intresserade av snävaste intervallet.
  // Vi tar alltså den största mindre gränsen och minsta större gränsen.
  double N;
  cin >> N;
  double global_K_max = 1e8; // obs tar väldigt stor eftersom vi vill
                             // hitta minsta övre gränsen
  double global_K_min = -1e8;
  rep(i, 0, N) {
    int V, K;
    double K_max, K_min;
    cin >> V >> K;
    // Intervall för eg möjliga kostnader
    K_max = K + 4.99;
    K_min = K - 5;

    double Kpl_max, Kpl_min; // Kostnad per l intervall
    Kpl_max = K_max / V;
    Kpl_min = K_min / V;

    global_K_max = min(Kpl_max, global_K_max);
    global_K_min = max(Kpl_min, global_K_min);
  }
  int last;
  double max_last, min_last;
  cin >> last;
  max_last = last * global_K_max;
  min_last = last * global_K_min;
  cout << round(max_last / 10) * 10; // Avrundar med 10
}
