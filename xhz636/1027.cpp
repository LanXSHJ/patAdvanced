#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void put13(int num)
{
    int high = num / 13;
    int low = num % 13;
    if (high < 10)
        putchar('0' + high);
    else
        putchar('A' + high - 10);
    if (low < 10)
        putchar('0' + low);
    else
        putchar('A' + low - 10);
}

int main(void)
{
    int R, G, B;
    cin >> R >> G >> B;
    putchar('#');
    put13(R);
    put13(G);
    put13(B);
    putchar('\n');
    return 0;
}
