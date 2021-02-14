#include <iostream>

int main() {
    int row = 2, col = 2;

    int ** matrix = new int *[row];

    for(int i =0 ; i < row; i++) {
        matrix[i] = new int[col];
    }

    // inserting value

    int k=1;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            matrix[i][j] = k++;
        }
    }

    // Output value

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            std::cout << matrix[i][j] << " "; 
        }
        std::cout << std::endl;
    }

    return  0;
}