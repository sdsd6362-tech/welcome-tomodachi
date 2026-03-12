#include <stdio.h>
#define ARRAY_SIZE 20
#define PER_LINE 10
void printArraySample(int * array, int size, int per_line){
    for(int i=0 ; i<size ; i++){
        printf("%3d",array[i]);
        if((i+1)%PER_LINE == 0)
            printf("\n");
    }
    printf("\n");
}

int binarySearch(int data_array[], int size, int key_to_serch){
    int low, mid, top;
    int loop=0;
    if(key_to_serch>data_array[size-1])
        return -1;
    low = 0;
    top = size-1;
    loop++;
    
    while(low <= top)
    {
        mid = low + (top-low)/2;
        printf("%d-th loop: Serch range: [%2d ~%2d]\n",loop,low,top);
        if(data_array[mid] == key_to_serch)
            return mid+1;
        if(data_array[mid]>key_to_serch)
            top = mid - 1;
        if(data_array[mid]<key_to_serch)
            low = mid + 1;
        loop++;
    }
    return mid;
        
}

int main()
{
    int array[ARRAY_SIZE] = {0,3, 12, 26, 37, 40, 43, 44, 45, 46, 54, 56, 59, 63, 66, 75, 82, 89, 94, 97};
    int key, pos;
    printArraySample(array,ARRAY_SIZE,PER_LINE);
    
    
    while(1)
    {
        printf("Input integer to be searched (-1 to quit) : ");
        scanf("%d",&key);
        if (key == -1)
            break;
        else{
            printf("Sequential searching key (%d) from array of %d data ... \n", key, ARRAY_SIZE);
            pos = binarySearch(array, ARRAY_SIZE, key);
            if (pos == -1) {
                printf("The key (%2d) was not found from the array\n", key);
            } 
            else {
                printf("The key (%2d) was found at position (%2d)\n", key, pos); 
            } 
        }
    }
    return 0;
}