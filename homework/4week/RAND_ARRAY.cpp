#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10000 /* 10000000 */
#define PER_LINE 10
#define SAMPLE_LINES 2

void insertSort(int* arr, int size) //삽입 정렬
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 각 원소를 랜덤한 위치의 원소와 교환하는 셔플 알고리즘이다.
//기존 rand()만 사용하면 RAND_MAX값이 32767(2^15-1)정도로 랜덤 범위가 너무 작다.
void shuffleBigArray(int *bigIntArray, int bigSize)
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

int *genBigRandArray(int bigSize, int offset = 0)
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

//매개변수 해설 (배열, 배열크기, 출력 줄, 출 갯수)
void printArraySample(int *array, int size, int per_line, int sample_lines)
{
    int count = 0;
    for (int i=0; i<sample_lines; i++) {        //출력하고 싶은 줄 갯수
        for (int j = 0; j < per_line; j++) {    //한줄에 출력할 배열의 수
            printf("%7d ", array[count++]);
            if (count >= size)                  //count가 배열의 갯수 만큼 많이지면 종료
            { printf("\n"); return; }
        }
        printf("\n");
    } // end for
    if (count >= size)
    return;

    if (count < (size - per_line * sample_lines))
        count = size - per_line * sample_lines; //1000 - 10 * 2 = count 로 마지막 20개전으로 돌려서 마지막 20개의 배열 출력
    printf("\n . . . . . \n");
    for (int i = 0; i < sample_lines; i++) {
        for (int j = 0; j< per_line; j++) {
            printf("%7d ", array[count++]);
            if (count >= size)
            { printf("\n"); return; }
        }
        printf("\n");
    } // end for
    printf("\n");
}


int main()
{
int *array; //배열 선언
array = genBigRandArray(ARRAY_SIZE, 0); //선언 한 배열에 큰 랜덤 배열 대입
printf("Before sort : \n");             //
printArraySample(array, ARRAY_SIZE, PER_LINE, SAMPLE_LINES);       //1부터 9999까지 다 배열을 출력하는 것은 너무 많기에 앞뒤 샘플 20개만 출력하게 해주는 함수
insertSort(array, ARRAY_SIZE); // only for size <= 10000
printf("After sort : \n");
printArraySample(array, ARRAY_SIZE, PER_LINE, SAMPLE_LINES);        //정렬된 배열 샘플 출력
}