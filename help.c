//수를 42로 나누었을 때 나머지의 종류의 갯수를 출력하는 프로그램
//작동은 하는데 예외처리를 못해서 그런가 정답이라고 안뜸 도와줘

#include <stdio.h>
int main(void)
{
    int num, size, seat=0;
    int arr[100];
    scanf("%d",&size);
    for(int i=0 ; i<size ; i++){
        scanf("%d", &num);
        if(num==0){
            seat -= 1;
        }
            
        else{
            arr[seat] = num;
            seat += 1;
        }
    }
    for(int i=0 ; i<seat ; i++)
        printf("%d ",arr[i]);
    return 0;
}