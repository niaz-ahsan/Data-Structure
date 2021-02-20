#include <iostream>

void right_rotate(int *arr, int size) {
    // start from end for right shift and put prev elem.
    int temp = arr[size - 1];
    for(int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

void display_result(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int *arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    right_rotate(arr, 5);
    display_result(arr, 5);
    return 0;
}