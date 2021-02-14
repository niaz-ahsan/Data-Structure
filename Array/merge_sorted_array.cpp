#include <iostream>

void displayArray(int *p, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size)
{
    int * arr3 = new int[arr1Size + arr2Size]; // creating new array
    // Write your code here
    int i = 0, j = 0, k = 0;
    while(i < arr1Size || j < arr2Size) {
        if((arr1[i] < arr2[j] && i < arr1Size) || (j >= arr2Size)) { // checking which is small if it's still accessible otherwise access all if the other arr is fully exhausted
            //std::cout << arr1[i] << " < " << arr2[j] << " index arr1: " << i << " index arr2: " << j << std::endl;
            arr3[k] = arr1[i];
            i++;
            k++;
        } else if( (arr1[i] > arr2[j] && j < arr2Size) || (i >= arr1Size) ) {
            //std::cout << arr1[i] << " > " << arr2[j] << " index arr1: " << i << " index arr2: " << j << std::endl;
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    displayArray(arr3, arr1Size + arr2Size);
    return arr3; // returning array
}

int main() {
    int arr1[4] = {1,3,4,9};
    int arr2[4] = {2,6,7,8};
    int *p = mergeArrays(arr1, arr2, 4, 4);
    delete[] p;
    return 0;
}