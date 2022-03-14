#include "mat.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int const x = 33;
int const y = 126;
void delete_mat(char** mat, int size);
std::string mat_to_string(vector<vector<char>> mat, int row, int col);
vector<vector<char>> build_mat(int col, int row, char sym1, char sym2);
////
std::string ariel::mat(int col, int row, char sym1, char sym2){
    vector<vector<char>> mat = build_mat(col, row, sym1, sym2);
    string s = mat_to_string(mat, row, col);
    // delete_mat(mat, row);
    return s;
}

vector<vector<char>> build_mat(int col, int row, char sym1, char sym2){
    if(col % 2 == 0 || row % 2 == 0 || col < 0 || row < 0){
        throw std::invalid_argument("Row or Column must not divide by 2 or cant be negative");
    }
    if(sym1 < x || sym1 > y || sym2 < x || sym2 > y){
         throw std::invalid_argument("Cannot apply those symbols");
    }
    // char** mat = new char*[row];
    // for (int i = 0; i < row; i++){
    //     mat[i] = new char[col];
    // }
    vector<vector<char>> mat(row, vector<char>(col));
    int temp_row = row;
    int temp_col = col;
    int i = 0;
    int start_index = 0;
    int row_idx = 0;
    char c = sym1;
    int count = 0;
    while(count != row * col){
    for(int j = start_index; j < col; j++){
        mat[i][j] = c;
        count++;  
    }
     if(count == temp_row * temp_col){
        break;
    }
    row_idx++;      
    for(int j = row_idx; j < row - 1; j++){ // left column
        mat[j][i] = c;
        if(count == temp_row * temp_col){
        break;
    }
        count++;    
    }

    i = col - 1;
    for(int j = row_idx; j < row - 1; j++){ // right column
        mat[j][i] = c;
        if(count == temp_row * temp_col){
        break;
    }
        count++;
    }
     
    i = row - 1;
    for(int j = start_index; j < col; j++){
        mat[i][j] = c;
        if(count == temp_row * temp_col){
        break;
    }
        count++;
    }
    
     
    row--; 
    col--;
    start_index++; 
    i = start_index; 
    if(c == sym1){
        c = sym2;
    }else{
        c = sym1;
    }  
}
return mat;
}

std::string mat_to_string(vector<vector<char>> mat, int row, int col){
    int i = 0;
    string s;
    for(int i = 0; i < row; i ++){
        for (int j = 0; j < col; j++){
            s += mat[i][j];
        } 
        s += "\n";
    }
    return s;
}

// void delete_mat(char** mat, int size){
//     for(int i = 0; i < size; i++){
//         delete[] mat[i];
//     }
//     delete[] mat;
// }


// int main(){
//     int row, col;
//     char c1, c2;
//     cout << "Enter number of rows:" << endl;
//     cin >> row;
//     cout << "Enter number of columns:" << endl;
//     cin >> col;
//     cout << "Enter first symbol:" << endl;
//     cin >> c1;
//     cout << "Enter second symbol:" << endl;
//     cin >> c2;
//     cout << ariel::mat(col, row, c1, c2) << endl;
//     return 0;
// }
