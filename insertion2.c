//더 직관적인 코드

#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {332,1345,12,4,3223,54,12,34,2,7};

    for(int i = 1; i < SIZE; i++) { // i=1인 이유는 두 번째 항목부터 보기 때문
        for(int j = i; j > 0; j--) { // j=i에서 시작해 숫자를 점점 줄여가며 비교한다
            if(arr[j] < arr[j-1]) { //비교
                //바꾸기
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            } else {
                break;
                //break인 이유는 2번째부터 쭉 오면서 그 앞은 이미 정렬되어 있기 때문
            }
        }
    }

    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
}