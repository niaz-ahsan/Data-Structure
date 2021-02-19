#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> frequency_mapper;

void find_frequency(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        // check if elem exist in map (key)
        // if yes, increment value
        // if no, add new key and initialize value to 1
        if(frequency_mapper.find(arr[i]) == frequency_mapper.end()) {
            // not found
            frequency_mapper[arr[i]] = 1;
        } else {
            // found
            frequency_mapper[arr[i]]++; 
        }
    }
} 

void display_result() {
    std::unordered_map<int, int>::iterator itr;
    for(itr = frequency_mapper.begin(); itr != frequency_mapper.end(); itr++) {
        std::cout << "[" << itr->first << "] : " << itr->second << std::endl; 
    }
    std::cout << std::endl;
}

int main() {
    int *arr = new int[6];
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 9;
    arr[3] = 2;
    arr[4] = 3;
    arr[5] = 6;

    find_frequency(arr, 6);
    display_result();

    return 0;
}