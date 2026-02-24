#include <iostream>
#include <string>

int count(std::string* str, char c) {
    int len = str -> length();
    int n = 0;

    for (int i = 0; i<=len; i++){
        if ((*str)[i] == c){
            n++;
        }
    }
    return n;
}
    


int main(){
    std::string inp;
    std::cin >> inp;
    int bs;
    int ks;

    // Get num
    bs = count(&inp, 'b');
    ks = count(&inp, 'k');

    std::string out;
    if (ks == bs && bs == 0){
        out = "none";
    }
    else if (ks == bs){
        out = "boki";
    }
    else if (bs > ks){
        out = "boba";
    }
    else {
        out = "kiki";
    }
    std::cout << out;
}