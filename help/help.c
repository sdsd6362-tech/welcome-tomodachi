//수를 42로 나누었을 때 나머지의 종류의 갯수를 출력하는 프로그램
//작동은 하는데 예외처리를 못해서 그런가 정답이라고 안뜸 도와줘

#include <stdio.h>

int main(void)
{
    int a, count=0;
    int arr[10],cout[100];

    for(int i=0 ; i<10 ; i++){
        scanf("%d",&a);
        arr[i] = a%42;
    }

    for(int i=0 ; i<10 ; i++){
        if(cout[arr[i]] == 0){ //처음 선언된 배열은 0으로 저장되있는 특성을 이용
            cout[arr[i]] = 1;  //찾는 값이 처음 이변 0에서 변환하기에 그 변환 된 횟수를 1증가시켜
            count += 1;        //중복된 값을 찾는다. 만일 중복된 값이면 그자리는 0이 아니기에 카운트 안함
        }
    }
    printf("%d",count);
    return 0;
}