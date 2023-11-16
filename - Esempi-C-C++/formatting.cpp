#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const size_t N = 3;
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            std::cout << std::setw(2) << std::setfill('0') << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    float p = M_PI;
    cout << fixed; // così precision riguarda solo i decimali e non tutte le cifre anche quelle intere
    cout << setprecision(2);
    cout << p << endl;
    cout << p << endl;


    string parola = "Ciao";
    cout << setw(10);
    cout << setfill(' ');
    cout << parola << " " << parola << endl;
    cout << parola << " " << setw(10) << parola << endl; // setw e setfill vanno settati prima di ogni parola stampata a differenza di fixed e setprecision

    return 0;
}