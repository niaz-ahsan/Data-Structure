#include <iostream>

int * find_product(int arr[], int size)  { 
    int *product = new int[size]; 
    long total_product = 1;
    for(int i = 0; i < size; i++) {
        total_product *= arr[i];
    }
    for (int i = 0; i < size; i++) {
        product[i] = total_product / arr[i];
    }
    return product; 
} 

void display_result(int *p, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1,2,3,4};
    int *p = find_product(arr, 4);
    display_result(p, 4);
    return 0;
}