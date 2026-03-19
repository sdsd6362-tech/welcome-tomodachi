#include <stdio.h>
#include <stdlib.h>
#define NUM_DATA 20
#define PER_LINE 10


void printArray(int array[], int size, int per_line);                   //배열을 출력
void _mergeSort(int array[], int tmp_array[], int left, int right);     //재귀 함수를 이용한 병합 정렬
void mergeSort(int array[], int size);

/*main 함수 시작*/
int main(void)
{
    int data_array[NUM_DATA] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0};
    printf("Integer array before mergeSort:\n");
    printArray(data_array, NUM_DATA, 10);
    mergeSort(data_array, NUM_DATA);
    
    printf("Integer array after mergeSort:\n");
    printArray(data_array, NUM_DATA, 10);
    return 0;
}
/*main 함수 종료*/


void printArray(int array[], int size, int per_line){                   //배열을 출력 per_line마다 줄바꿈을 시행하는 함수
    for(int i=0 ; i<size ; i++){
        printf("%3d",array[i]);
        if((i+1)%per_line == 0)
            printf("\n");
    }
}

void _mergeSort(int array[], int tmp_array[], int left, int right){             //(원본 배열/임시저장용 배열/현재 처리중인 시작 인덱스/현재 처리중인 끝 인덱스)
    if(left>=right)                                                             //최저가 최고랑 같거나 더 큰 경우는 배열이 하나있는 경우 밖에 없음, 즉 배열이 1개있을때 반환, 재귀를 종료하는 시점
        return;
    int i, j, k;
    int mid = (left + right)/2;

    /*배열을 분리하는 과정*/
    _mergeSort(array,tmp_array,left,mid);       // 중앙을 기준으로 작은쪽
    _mergeSort(array,tmp_array,mid+1,right);    // 중앙을 기중으로 큰쪽으로 분리하는 재귀 함수

    /*현재 정렬 대상 구간을 임시 배열로 복사하는 과정*/
    for(k=left ; k<=right ; k++){
        tmp_array[k] = array[k];
    }

    for(i=left, j=mid+1, k=left; k<=right ; k++)
    {
        if((i<=mid) && (j<= right)){
            if(tmp_array[i] <tmp_array[j])
                array[k] = tmp_array[i++];
            else    
                array[k] = tmp_array[j++];
        }else if((i<=mid) && (j>right)){
            array[k] = tmp_array[i++];
        }else if((i>mid)&&(j<=right)){
            array[k] = tmp_array[j++];
        }    
    }
}

void mergeSort(int array[], int size){
    int * tmp_array = (int*)calloc(size, sizeof(int));  //size 크기의 배열을 INT 사이즈만큼 메모리 공간 할당
    if(tmp_array == NULL){                              //만일 유효한 메모리 주소가 없을때 null
        printf("Error in creation of tmp_array (size = %d) in mergeSort() !!!\n", size);  
        exit(1);
    }
    _mergeSort(array,tmp_array,0,size-1);   //정상일때 실행된다.
    free(tmp_array);                        //메모리 해제     
}