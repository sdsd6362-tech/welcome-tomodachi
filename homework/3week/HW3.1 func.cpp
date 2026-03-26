/*  Homework 3.1 - 함수의 인수 전달 방식에 대한 비교
*   Date : 2026 - 03 - 25
*   Author : Park soen gyu
* : Update List (Date) : 2026 - 03 - 25*/




#include <stdio.h>
double avg_callByValue(int array[], int num_data);
void avg_callByPointer(int array[], int num_data, double* pavg);
void avg_callByReference(int array[], int num_data, double& ravg);

#define NUM_DATA 10

int main(){
    double avg;
    int array_data[NUM_DATA] = {0};

    printf("input %d integer data to calculate average : ",NUM_DATA);
    for(int i =0 ; i<NUM_DATA ; i++){
        scanf("%d", &array_data[i]);
    }
    avg = avg_callByValue(array_data, NUM_DATA);
    printf("avg by add_callByValue() : %lf\n", avg);
    avg_callByPointer(array_data, NUM_DATA, &avg);
    printf("avg by add_callByPointer() : %lf\n", avg);
    avg_callByReference(array_data, NUM_DATA, avg);
    printf("avg by add_callByValue() : %lf\n", avg);
    return 0;
}

/*값에 의한 호출*/
double avg_callByValue(int array[], int num_data)
{
    double sum = 0.0, avg;
    for(int i=0 ; i<num_data ; i++){
        sum += array[i];
    }
    avg = sum / (double)num_data;
    return avg;                 //복사본의 값을 생성하여 전달하는 것으로 원본에 영향이 없다.
}

/*포인터에 의한 호출*/
void avg_callByPointer(int array[], int num_data, double *pavg)
{
    double sum = 0.0, avg;
    for(int i=0 ; i<num_data ; i++){
        sum += array[i];
    }
    avg = sum / (double)num_data;
    *pavg = avg;                //정의된 pavg라는 포인터가 avg를 가리키게 설정하여 avg를 나타낸다.
}

void avg_callByReference(int array[], int num_data, double &ravg)
{
    double sum = 0.0, avg;
    for(int i=0 ; i<num_data ; i++){
        sum += array[i];
    }
    ravg = sum / (double)num_data;  //변수의 별명을 전달하여 원본 그자체를 수정 가능하다. 즉 ravg는 avg의 또 다른 이름이라고 볼 수 있다.
}
