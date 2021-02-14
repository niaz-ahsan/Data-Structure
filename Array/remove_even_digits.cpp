#include <iostream>

int * removeEven( int *& Arr, int size ) {
  // Write your code here
    int index = 0;
    for(int i = 0; i < size; i++) {
        if(Arr[i] % 2 != 0) { // found odd number
            if(i != index) {
                Arr[index] = Arr[i];
            }
            index++;
        }
    }
    
    int *temp = new int[index];
    for(int i = 0; i < index; i++) {
        temp[i] = Arr[i];
    } 

    delete[] Arr;
    return temp;
}

int main() {
    int *p = new int[6]{1,3,4,2,5,7};
    p = removeEven(p, 6);
    
    for(int i = 0; i < 5; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
    delete[] p;

    return 0;
}