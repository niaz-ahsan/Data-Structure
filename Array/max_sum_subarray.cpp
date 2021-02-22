#include <iostream>
#include <algorithm>
// using Kadane's algoithm to solve it

int max_sum_subarray(int *arr, int size) {
    int local_max = 0;
    int global_max = 0;
    for(int i = 0; i < size; i++) {
        local_max = std::max(arr[i], (local_max + arr[i]));
        if(local_max > global_max) {
            global_max = local_max;
        }
    }
    return global_max;
}

int main() {
    int *arr = new int[6];
    arr[0] = 1;
    arr[1] = 7;
    arr[2] = -2;
    arr[3] = -5;
    arr[4] = 10;
    arr[5] = -1;

    std::cout << max_sum_subarray(arr, 6) << std::endl;
    return 0;
}