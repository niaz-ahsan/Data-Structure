# include <iostream>

int find_second_max(int *arr, int size) {
    int max = INT_MIN;
    int second_max = INT_MIN;
    for(int i = 0; i < size; i++) {
        if(arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if(arr[i] > second_max) {
            second_max = arr[i];
        }
    }
    return second_max;
}

int main() {
    int *arr = new int[5];
    arr[0] = 4;
    arr[1] = 2;
    arr[2] = 1;
    arr[3] = 5;
    arr[4] = 0;

    std::cout << find_second_max(arr, 5) << std::endl;
    return 0; 
}