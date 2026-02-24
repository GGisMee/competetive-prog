// #include <iostream>
// #include <string>
#include <bits/stdc++.h> // Innehåller allt
using namespace std;

typedef long long ll;
#define rep(i, a, b) for(ll i = a; i < b; i++)

int next_num(string input, int start){
    // finner nästa nummer i input från index start och returnerar det indexet 
    int idx = start;
    while (!isdigit(input[idx])){
        cout<<idx;
        idx++;
    }
    return idx;
}
int get_num(string input, int start){
    // hämtar numret som finns efter indexet start
    string num;
    int idx = start;
    while (isdigit(input[idx])){
        idx++;
        num+=input[idx];
    }
    cout<<num;
    return stoi(num);
}

int main(){
    int N;
    int max_int;
    string inp;
    cin >> N;
    cin>>inp;
    
    int idx = 0;
    while (next_num(inp, idx) != idx){

        idx = next_num(inp, idx);
        int num = get_num(inp, idx);
        max_int = max(max_int, num);
    }
    cout<<max_int;
}