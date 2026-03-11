#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {123,34,12,43,657,43,23,56,23,6};

    for(int i = 1; i < SIZE; i++) {
        int cur = arr[i];
        int j = i;
        while(cur < arr[j-1] && j > 0){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = cur;
    }

    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
}