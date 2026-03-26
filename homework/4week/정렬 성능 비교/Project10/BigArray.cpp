#include "BigArray.h"
#include <stdio.h>
#include <stdlib.h>


void printBigArraySample(int* array, int size, int items_per_line, int sample_lines);
void shuffleBigArray(int* array, int size);
int* genBigRandArray(int size, int offset);
void insertSort(int* array, int size);
void selectionSort(int* array, int size);
void mergeSort(int* array, int size);
void _mergeSort(int array[], int tmp_array[], int left, int right);
void _quickSort(int* array, int size, int left, int right);
int _partition(int* array, int size, int left, int right, int pivotIndex);
void quickSort(int* array, int size);


void printBigArraySample(int* array, int size, int per_line, int sample_lines)
{
    int count = 0;
    for (int i = 0; i < sample_lines; i++) {        //출력하고 싶은 줄 갯수
        for (int j = 0; j < per_line; j++) {    //한줄에 출력할 배열의 수
            printf("%7d ", array[count++]);
            if (count >= size)                  //count가 배열의 갯수 만큼 많이지면 종료
            {
                printf("\n"); return;
            }
        }
        printf("\n");
    } // end for
    if (count >= size)
        return;

    if (count < (size - per_line * sample_lines))
        count = size - per_line * sample_lines; //1000 - 10 * 2 = count 로 마지막 20개전으로 돌려서 마지막 20개의 배열 출력
    printf("\n . . . . . \n");
    for (int i = 0; i < sample_lines; i++) {
        for (int j = 0; j < per_line; j++) {
            printf("%7d ", array[count++]);
            if (count >= size)
            {
                printf("\n"); return;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void shuffleBigArray(int* bigIntArray, int bigSize)
{
    int i2, temp;
    unsigned int u_int30 = 0;
    for (int i = 0; i < bigSize; i++)       //각 위치마다 i마다 한 번씩 랜덤 교환 수행한다.
    {
        u_int30 = ((long)rand() << 15) | rand();        //기존 rand()로 생성된 15비트 를 15만큼 오름으로 상위 비트로 움직인것과 
        i2 = u_int30 % bigSize;                         //기존 하위 비트를 | 논리 연산으로 합쳐 30비트로 더 큰 비트를 많든다.
        if (i != i2)                                    //그럴 경우 기존보다 더 커진 랜덤으로 나올수 있는 값이 더 많아진다.
        {
            temp = bigIntArray[i];
            bigIntArray[i] = bigIntArray[i2];
            bigIntArray[i2] = temp;
        }
    }
}

int* genBigRandArray(int bigSize, int offset = 0)
{
    int* bigIntArray;
    bigIntArray = (int*)calloc(bigSize, sizeof(int));   //배열의 크기 만큼 int형 동적 메모리 공간 확보
    for (int i = 0; i < bigSize; i++)
    {
        bigIntArray[i] = i + offset; //offset으로 배열에 숫자를 차례 대로 넣을 때 시작 숫자를 설정할 수 있다. 여기서는 0을 기준으로 설정함
    }
    void srand();
    shuffleBigArray(bigIntArray, bigSize);
    return bigIntArray;         //랜덤으로 셔플된 배열의 값을 반환한다.
}

void insertSort(int* array, int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i; j > 0; j--) {
            if (array[j] < array[j - 1]) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

void selectionSort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++) {                      //배열의 마지막은 자동 정렬이기 때문에 마지막 전까지 반복을 돌린다.  
        int least = i;                                  //반복을 돌리기 전에 첫 같은 가장 작다고 가정한다.
        for (int j = i + 1; j < size; j++) {                //배열의 가장 작다고 설정한 값과 그 다음 값들을 비교한다.
            if (array[j] < array[least])                       //만약 다음 값이 작다고 설정한 값보다 작으면 그 위치 값을 작다는 값으로 바꾼다.
                least = j;
        }
        if (array[i] != array[least]) {                      //루프를 한번 돌렸을 때 가장 작은 같이 처음과 같다면 다른 반복으로 넘어가고
            int temp = array[i];
            array[i] = array[least];
            array[least] = temp;           //루프를 돌았을 때 가장 작다고 하는 값이 현재랑 다르다면 두 위치를 교환한다.
        }
    }
}

void _mergeSort(int array[], int tmp_array[], int left, int right) {             //(원본 배열/임시저장용 배열/현재 처리중인 시작 인덱스/현재 처리중인 끝 인덱스)
    if (left >= right)                                                             //최저가 최고랑 같거나 더 큰 경우는 배열이 하나있는 경우 밖에 없음, 즉 배열이 1개있을때 반환, 재귀를 종료하는 시점
        return;
    int i, j, k;
    int mid = (left + right) / 2;

    /*배열을 분리하는 과정*/
    _mergeSort(array, tmp_array, left, mid);       // 중앙을 기준으로 작은쪽
    _mergeSort(array, tmp_array, mid + 1, right);    // 중앙을 기중으로 큰쪽으로 분리하는 재귀 함수

    /*현재 정렬 대상 구간을 임시 배열로 복사하는 과정*/
    for (k = left; k <= right; k++) {
        tmp_array[k] = array[k];
    }

    for (i = left, j = mid + 1, k = left; k <= right; k++)
    {
        if ((i <= mid) && (j <= right)) {
            if (tmp_array[i] < tmp_array[j])
                array[k] = tmp_array[i++];
            else
                array[k] = tmp_array[j++];
        }
        else if ((i <= mid) && (j > right)) {
            array[k] = tmp_array[i++];
        }
        else if ((i > mid) && (j <= right)) {
            array[k] = tmp_array[j++];
        }
    }
}

void mergeSort(int* array, int size) {
    int* tmp_array = (int*)calloc(size, sizeof(int));  //size 크기의 배열을 INT 사이즈만큼 메모리 공간 할당
    if (tmp_array == NULL) {                              //만일 유효한 메모리 주소가 없을때 null
        printf("Error in creation of tmp_array (size = %d) in mergeSort() !!!\n", size);
        exit(1);
    }
    _mergeSort(array, tmp_array, 0, size - 1);   //정상일때 실행된다.
    free(tmp_array);                        //메모리 해제     
}

int _partition(int* array, int size, int left, int right, int pivotIndex)
{
    int pivotValue; // 기존 pivote 선언
    int newPI; // 새로운 pivote 선언
    int temp, i;

    pivotValue = array[pivotIndex]; //매개변수로 받은 pivote의 값을 배열의 인덱스로 저장하여 pivote 저자
    array[pivotIndex] = array[right]; //정리를 편하게 하기 위해 pivote을 맨 뒤로 이동
    array[right] = pivotValue; // Move pivot element to end

    newPI = left;   //작은 값들을 저장할 가장 앞쪽 부분 지정
    for (i = left; i <= (right - 1); i++) {
        if (array[i] <= pivotValue) {       //pivote 값과 현재 값을 비교했을때 pivote의 값이 더 크면 작은 값들을 앞으로 모은다.
            temp = array[i];
            array[i] = array[newPI];
            array[newPI] = temp;
            newPI = newPI + 1;  //저장된 작은 값이 있기에 다음 칸으로 이동
        }

    }
    temp = array[newPI];
    array[newPI] = array[right];
    array[right] = temp;



    // swap array[newPI] and array[right]; Move pivot to its new final place
    // pivotValue = array[right]; array[right] = array[newPI]; array[newPI] = pivotValue;
    return newPI;
}




void _quickSort(int* array, int size, int left, int right)
{
    int pI, newPI; // pivot index
    if (left >= right) {                //배열의 시작이 배열의 끝보다 크거나 같은 경우는 배열이 1개 인 경우 밖에 없다.
        return;
    }
    else if (left < right) { // subarray of 0 or 1 elements already sorted
        pI = (left + right) / 2;        //pivote의 인덱스를 중앙 지점으로 지정
    }

    newPI = _partition(array, size, left, right, pI);

    if (left < (newPI - 1)) {       //pivote을 기준으로 왼쪽을 다시 퀵정렬한다.
        _quickSort(array, size, left, newPI - 1);
    }

    if ((newPI + 1) < right) {      //pivote을 기준으로 오른쪽을 다시 퀵정렬한다.
        _quickSort(array, size, newPI + 1, right);
    }
}

void quickSort(int* array, int size) {
    _quickSort(array, size, 0, size - 1);
}
