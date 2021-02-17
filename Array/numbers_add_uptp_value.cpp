// Solving problem using Hash set for constant lookup

#include <iostream>
#include <unordered_set>

//Return 2 elements of arr that sum to the given value
int * findSum(int arr[], int value, int size) {
    int *result = new int[2];
    std::unordered_set<int> complements;
    std::unordered_set<int>::const_iterator found;

    for(int i = 0; i < size; i++) {
        // check if this number is in complement collection, if yes we've found 2 numbers. Otherwise just insert this number in complement collection
        found = complements.find(value - arr[i]);
        if(found == complements.end()) {
            // not found, iterate
            complements.insert(arr[i]);
        } else {
            // found, get the other number and return
            result[0] = value - arr[i];
            result[1] = arr[i];
            return result;
        }
    }

	return arr; 
} 

void display_result(int *p) {
    for(int i = 0; i < 2; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1,21,3,14,5,60,7,6};
    int value = 81;
    int *result = findSum(arr, value, 8);

    display_result(result);

    //delete[] result;
    return 0;
}