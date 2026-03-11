#include <stdio.h>

const int SIZE = 10;

int main() {
    int arr[10] = {2,54,1,4,12,32,12,23,12,65};
    
    for(int i = 0; i < SIZE; i++){
        int min = i;
        for(int j = i; j < SIZE; j++){
            min = arr[min] > arr[j] ? j : min; 
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
}