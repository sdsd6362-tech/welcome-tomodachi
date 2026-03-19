#include <stdio.h>
#include <stdarg.h>                 //인자 개수가 가변일 때 사용하는 라이브러리
int sum_vargs_int(int count, ...)   //count 까지, ... 인자가 여러개 올 수 있다.
{
    int result_sum = 0, arg_data;
    va_list ap;                     //인자 목록 저장 ap는 일종의 포인터 역할을 하는 객체
    va_start(ap, count);            //가변 인자의 시작 위치를 설정 (ap부터 ~ count까지)
    printf("arg_data in va_list : ");
    for (int i = 0; i < count; i++){
        arg_data = va_arg(ap, int); //가변 인자 하나씩 꺼내오기, 현재의 값을 읽고 다음 위치로 이동한다. 이때 형식을 지정해주어 움직이는 포인터 크기 지정
        printf("%3d", arg_data);    //뽑아온 데이터 출력
        result_sum += arg_data;     //포인터 result에 더해서 넣기
        }
    printf("\n");
    va_end(ap);                     //사용이 끝났다는 것을 시스템에 알린다.
    return result_sum;
}

int main()
{
    int sum_varg, num_data;
    num_data = 5;
    sum_varg = sum_vargs_int(num_data, 1, 2, 3, 4, 5);
    printf("sum(1..%d) = %d\n", num_data, sum_varg);
    num_data = 10;
    sum_varg = sum_vargs_int(num_data, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("sum(1..%d) = %d\n", num_data, sum_varg);
}