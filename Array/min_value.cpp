#include <iostream>

int find_minimum(int arr[], int size) {
	int minimum = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }
    }
	return minimum;
}

int main() {
    int arr[] = {4,2,1,5,0};
    std::cout << "Minimum is: " << find_minimum(arr, 5) << std::endl;
    return 0;
}