#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    char str[81];
    scanf("%s", str);
    int N, nv, nh;
    N = strlen(str);
    nv = (N + 2) / 3 - 1;
    nh = N - 2 * nv;
    for (int i = 0; i < nv; i++)
    {
        putchar(str[i]);
        for (int j = 0; j < nh - 2; j++)
            putchar(' ');
        putchar(str[N - 1 - i]);
        putchar('\n');
    }
    str[N - nv] = '\0';
    printf("%s\n", str + nv);
    return 0;
}
