#include <iostream>

void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void re_arrange(int *arr, int size) {
    int negative_number_index = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] < 0) {
            if(i != negative_number_index) {
                swap(arr[i], arr[negative_number_index]);
            }    
            negative_number_index++;
        }
    }
}

void display_result(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int *arr = new int[5];
    arr[0] = 10;
    arr[1] = -1;
    arr[2] = 20;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = -9;
    arr[6] = -6;

    re_arrange(arr, 7);
    display_result(arr, 7);
    return 0;
}