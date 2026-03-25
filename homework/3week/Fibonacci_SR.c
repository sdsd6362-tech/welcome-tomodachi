//재귀 함수를 이용한 피보나치 수열 계산 
//이미 계산된 피보나치 수열의 값도 저장되기 때문에 40이 넘어가는 피보나치 수열의 경우 시간이 오래 걸리는 것을 확인할 수 있다.

#include <stdio.h>
#include <Windows.h>            //LONGLONG, 고해상도 타이머를 사용하기 위해서 윈도우 전용 라이브러리 호출
#include <stdlib.h>
#define FIBO_TBL_SIZE 200


LONGLONG Fibo_SR(int n)
{
    LONGLONG fibo_n;
    if((n==0)||(n==1)){         //n이 0또는 1일 경우 n을 반환
        return (LONGLONG)n;
    }
    else{
        return fibo_n = Fibo_SR(n-1) + Fibo_SR(n-2);
    }
}

LONGLONG Fibo_Dyn(int n)
{
    LONGLONG fibo_n;
    static LONGLONG fibo_series[FIBO_TBL_SIZE] = {0};

    if((n==0) || (n==1))
    {
        return n;
    }else if(fibo_series[n]!=0){
        return fibo_series[n];
    }else{
        fibo_n = Fibo_Dyn(n-2) + Fibo_Dyn(n-1);
        fibo_series[n] = fibo_n;
        return fibo_n;
    }
}



int main(){
    LONGLONG fibo_n_SR, fibo_n_Dyn;               //재귀(피보나치), 동적(피보나치)선언
    double t_diff;
    LONGLONG t_diff_pc;                         //카운터 차이
    LARGE_INTEGER pc_freq, t1, t2;              //타이머 주파수, 시작, 종료 시간, (window에서 정의된 구조체이다.)
    double t_elapse_us_Dyn, t_elapse_ms_SR;                     //실행 시간(ms)
    int line_len = 90;
    char *star_line = (char *)malloc(line_len * sizeof(char));

    QueryPerformanceFrequency(&pc_freq);        //시간 단위 변환 기준, 시스템의 ㄹ타이머 주파수(초당 카운터)를 가져온다.
    printf("Fibonacci Series :\n");

    
    for (int i = 0; i < line_len; i++)
        star_line[i] = '-';
    star_line[line_len - 1] = '\0';
    printf("%s\n", star_line);
    printf("%8s %23s %15s %23s %15s\n", "n", "FiboDyn()", "Elapse_Time[ms]", "FiboSR()", "Elapse_Time[ms]");
    printf("%s\n", star_line);


    for (int n = 0; n <= 100; n++) 
    {
        QueryPerformanceCounter(&t1);       //시작 시간
        fibo_n_Dyn = Fibo_Dyn(n);
        QueryPerformanceCounter(&t2);       //종료 시간
        t_diff_pc = t2.QuadPart - t1.QuadPart;     //t1, t2를 64비트로 읽어 큰단위 읽어 (경과 시간) 계산
        t_elapse_us_Dyn = (double)t_diff_pc / (double)pc_freq.QuadPart * 1000000;      //실행 시간 = (카운터 차이 / 초당 카운터 수)  * 1000
        printf("%8d %23lld %15.3lf", n, fibo_n_Dyn, t_elapse_us_Dyn);

        if (n <= 44) {
            QueryPerformanceCounter(&t1);
            fibo_n_SR = Fibo_SR(n);
            QueryPerformanceCounter(&t2);
            t_diff_pc = t2.QuadPart - t1.QuadPart;
            t_elapse_ms_SR = ((double)t_diff_pc / (double)pc_freq.QuadPart) * 1000;
            printf(" %23lld %15.3lf", fibo_n_SR, t_elapse_ms_SR); 
        }
        else {
            n += 4;
        }
        printf("\n");
    }
    printf("%s\n", star_line);
}

