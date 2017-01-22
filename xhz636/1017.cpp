#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, K;
    int P[10000];
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int h, m, s, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        if (p > 60)
            p = 60;
        P[i] = ((h * 3600 + m * 60 + s) << 12) + p * 60;
    }
    sort(P, P + N);
    int W[K];
    for (int i = 0; i < K; i++)
    {
        W[i] = 8 * 3600;
    }
    int sum, count;
    sum = 0;
    for (count = 0; count < N; count++)
    {
        if ((P[count] >> 12) > 17 * 3600)
            break;
        int min = 0;
        for (int i = 1; i < K; i++)
        {
            if (W[min] > W[i])
                min = i;
        }
        int wait = W[min] - (P[count] >> 12);
        if (wait >= 0)
        {
            sum += wait;
            W[min] += (P[count] & 0xFFF);
        }
        else
        {
            W[min] = (P[count] >> 12) + (P[count] & 0xFFF);
        }
    }
    if (count != 0)
        printf("%.1f\n", sum / 60.0 / count);
    else
        printf("0.0\n");
    return 0;
}
