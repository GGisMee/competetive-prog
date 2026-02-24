#include <iostream>

int main() {
    int v_1;
    int v_2;
    int v_3;
    std::cin>>v_1;
    std::cin>>v_2;
    std::cin>>v_3;
    if (v_1 == 90 || v_2 == 90 || v_3 == 90 ) {
        std::cout<< "Ratvinklig Triangel";
    }
    else if (v_1 > 90 || v_2 > 90 || v_3 > 90) {
        std::cout<< "Trubbig Triangel";
    }
    else {
        std::cout << "Spetsig Triangel";
    }

    return 0;
}
