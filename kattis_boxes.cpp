#include <iostream>
#include <cmath>

int main() {
    int N; 
    std::cin >> N;
    int n = 0; // Antalet
    int i = 1;
    while (i*(i+1)*(i+2) < N){
        i++;
    }
    std::cout<<i-1;
}