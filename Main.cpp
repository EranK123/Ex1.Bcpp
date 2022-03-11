#include "mat.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;
int main(){
    int row, col;
    char c1, c2;
    cout << "Enter number of rows:" << endl;
    cin >> row;
    cout << "Enter number of columns:" << endl;
    cin >> col;
    cout << "Enter first symbol:" << endl;
    cin >> c1;
    cout << "Enter second symbol:" << endl;
    cin >> c2;
    cout << mat(col, row, c1, c2) << endl;
    return 0;////
}