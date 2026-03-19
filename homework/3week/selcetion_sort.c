#include <stdio.h>

void swep(int *arr1, int *arr2){  //저장된 배열 위치 바꾸기 함수
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void selcetion_sort(int *arr, int size){
    for(int i=0 ; i<size-1 ; i++){                      //배열의 마지막은 자동 정렬이기 때문에 마지막 전까지 반복을 돌린다.  
        int least = i;                                  //반복을 돌리기 전에 첫 같은 가장 작다고 가정한다.
        for(int j = i+1 ; j<size ; j++){                //배열의 가장 작다고 설정한 값과 그 다음 값들을 비교한다.
            if(arr[j]<arr[least])                       //만약 다음 값이 작다고 설정한 값보다 작으면 그 위치 값을 작다는 값으로 바꾼다.
            least = j;
        }
        if(arr[i] != arr[least])                        //루프를 한번 돌렸을 때 가장 작은 같이 처음과 같다면 다른 반복으로 넘어가고
            swep(&arr[i], &arr[least]);                 //루프를 돌았을 때 가장 작다고 하는 값이 현재랑 다르다면 두 위치를 교환한다.
    }       
}

int main(){
    int arr1[20] = {37, 97, 75, 44, 65, 63, 0, 59, 82, 46, 56, 43, 40, 3, 89, 45, 26, 94, 54, 12};
    selcetion_sort(arr1, 20);
    for(int i =0 ; i<20 ; i++)
        printf("%d ",arr1[i]);
    return 0;
}



