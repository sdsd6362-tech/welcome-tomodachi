#include <stdio.h>
#define ARRAY_SIZE 20
#define PER_LINE 10
void getArray(int *array, int size)
{
    printf("input %d integer : ",ARRAY_SIZE);
    for(int i=0 ; i<size ; i++)
    {
        scanf("%d",&array[i]);
    }
}

void printArraySample(int * array, int size, int per_line){
    for(int i=0 ; i<size ; i++){
        printf("%3d",array[i]);
        if((i+1)%PER_LINE == 0)
            printf("\n");
    }
}

void inserSort(int array[],int size){
    int i, j;
    for(i=0 ; i<size ; i++){
        for(j=i;j>0;j--){
            if(array[j]<array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }

}



int main(){
    int array[ARRAY_SIZE];
    getArray(array,ARRAY_SIZE);
    inserSort(array, ARRAY_SIZE);
    printArraySample(array, ARRAY_SIZE,PER_LINE);
    return 0;
}