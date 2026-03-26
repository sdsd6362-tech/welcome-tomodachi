#include <stdio.h>
#include <stdlib.h>

/*pivote를 기준으로 배열을 나누는 역할을 하는 pertiton 알고리즘*/
int _partition(int *array, int size, int left, int right, int pivotIndex)
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

/*퀵 정렬 알고리즘 : (배열, 배열 크기, 배열의 시작, 배열의 끝)*/
void _quickSort(int *array, int size, int left, int right)
{
    int pI, newPI; // pivot index
    if (left >= right) {                //배열의 시작이 배열의 끝보다 크거나 같은 경우는 배열이 1개 인 경우 밖에 없다.
        return;
    } else if (left < right) { // subarray of 0 or 1 elements already sorted
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

void quickSort(int *array, int size){
    _quickSort(array, size, 0, size-1);
}

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
    shuffleBigArray(bigIntArray, bigSize);
    return bigIntArray;         //랜덤으로 셔플된 배열의 값을 반환한다.
}

int main(){
    int *array;
    array = genBigRandArray(100, 0);
    for(int i=0 ; i<10 ; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    quickSort(array, 10);

    for(int i=0 ; i<10 ; i++){
        printf("%d ", array[i]);
    }

    return 0;
}