#include <stdio.h>
#include <Windows.h>
LONGLONG Fibo_SR(int n)
{
    LONGLONG fibo_n;
    if ((n == 0) || (n == 1)) {
        return LONGLONG(n);
    }
    else {
        fibo_n = Fibo_SR(n - 1) + Fibo_SR(n - 2);
        return fibo_n;
    }   
}
void main()
{
    LONGLONG fibo_n;
    LONGLONG t_diff_pc;
    LARGE_INTEGER pc_freq, t1, t2;
    double elapsed_time_ms;
    QueryPerformanceFrequency(&pc_freq);
    printf("Fibonacci Series :\n");
    for (int n = 0; n <= 50; n++) {
        QueryPerformanceCounter(&t1);
        fibo_n = Fibo_SR(n);
        QueryPerformanceCounter(&t2);
        t_diff_pc = t2.QuadPart - t1.QuadPart;
        elapsed_time_ms = (double)t_diff_pc / (double)pc_freq.QuadPart * 1000;
        printf("Fibo(%3d) = %20lld, took %15.3lf msec\n", n, fibo_n, elapsed_time_ms);
    }
}