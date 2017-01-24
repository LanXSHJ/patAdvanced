#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    char N[110], M[110];
    int K;
    scanf("%s %d", N, &K);
    int len = strlen(N);
    int i;
    for (i = 0; i < len; i++)
        N[i] -= '0';
    for (i = 0; i < K; i++)
    {
        int pal = 1;
        for (int j = 0; j < len / 2; j++)
            if (N[j] != N[len - 1 - j])
            {
                pal = 0;
                break;
            }
        if (pal)
            break;
        for (int j = 0; j < len; j++)
            M[j] = N[len - 1 - j];
        int carry = 0;
        for (int j = 0; j < len; j++)
        {
            int digit = N[j] + M[j] + carry;
            N[j] = digit % 10;
            carry = digit / 10;
        }
        if (carry)
            N[len++] = carry;
    }
    for (int j = len - 1; j >= 0; j--)
        putchar(N[j] + '0');
    putchar('\n');
    printf("%d\n", i);
    return 0;
}
