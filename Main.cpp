#include "mat.hpp"
#include <iostream>
#include <string>
#include "mat.cpp"
using namespace std;
using namespace ariel;
int main(){
    int row, col;
    char c1, c2;
    cout << "Enter number of rows:" << endl;
    cin >> row;
    if(row % 2 == 0){
        cout << "Row number must be odd. Enter an odd number:" << endl;
        cin >> row;
    }
    cout << "Enter number of columns:" << endl;
    cin >> col;
    if(col % 2 == 0){
        cout << "Column number must be odd. Enter an odd number:" << endl;
        cin >> col;
    }
    cout << "Enter first symbol:" << endl;
    cin >> c1;
    if(c1 < 33 || c1 > 126){
        cout << "Symbol is illegal. Change it:" << endl;
        cin >> c1;
    }
    cout << "Enter second symbol:" << endl;
    cin >> c2;
    if(c2 < 33 || c2 > 126){
        cout << "Symbol is illegal. Change it:" << endl;
        cin >> c2;
    }
    cout << endl;
    cout << "The Mat You Wished For: " << endl;
    cout << endl;
    cout << mat(col, row, c1, c2) << endl;
    return 0;
}