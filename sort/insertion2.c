#include <stdio.h>
#include <sys/time.h>

long long Fibo_SR(int n)
{
    if (n == 0 || n == 1)
        return n;
    return Fibo_SR(n - 1) + Fibo_SR(n - 2);
}

int main(void)
{
    long long fibo_n;
    struct timeval t1, t2;
    double elapsed_time_ms;

    printf("Fibonacci Series :\n");

    for (int n = 0; n <= 40; n++) { // 50은 너무 느림
        gettimeofday(&t1, NULL);

        fibo_n = Fibo_SR(n);

        gettimeofday(&t2, NULL);

        elapsed_time_ms =
            (t2.tv_sec - t1.tv_sec) * 1000.0 +
            (t2.tv_usec - t1.tv_usec) / 1000.0;

        printf("Fibo(%3d) = %20lld, took %10.3lf ms\n",
               n, fibo_n, elapsed_time_ms);
    }

    return 0;
}