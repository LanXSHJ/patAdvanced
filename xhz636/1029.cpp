#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N1, N2;
    scanf("%d", &N1);
    int S1[N1];
    for (int i = 0; i < N1; i++)
        scanf("%d", &S1[i]);
    scanf("%d", &N2);
    int S2[N2];
    for (int i = 0; i < N2; i++)
        scanf("%d", &S2[i]);
    int sum = N1 + N2;
    int median = sum / 2 + sum % 2 - 1;
    int i1 = 0, i2 = 0;
    while (i1 + i2 < median)
    {
        if (i1 < N1 && i2 < N2)
        {
            if (S1[i1] < S2[i2])
                i1++;
            else
                i2++;
        }
        else if (i1 < N1)
            i1 = median - i2;
        else
            i2 = median - i1;
    }
    if (i1 < N1 && i2 < N2)
        printf("%d\n", S1[i1] < S2[i2] ? S1[i1] : S2[i2]);
    else if (i1 < N1)
        printf("%d\n", S1[i1]);
    else
        printf("%d\n", S2[i2]);
    return 0;
}
