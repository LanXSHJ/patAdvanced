#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    char num[32];
    char dnum[32];
    int count[10];
    scanf("%s", num);
    for (int i = 0; i < 10; i++)
        count[i] = 0;
    for (int i = 0; i < strlen(num); i++)
        count[num[i] - '0']++;
    int carry = 0, index = 0;
    for (int i = strlen(num) - 1; i >= 0; i--)
    {
        int digit = num[i] - '0';
        digit *= 2;
        digit += carry;
        dnum[index++] = digit % 10 + '0';
        carry = digit / 10;
    }
    if (carry)
        dnum[index++] = carry + '0';
    for (int i = 0; i < index; i++)
        count[dnum[i] - '0']--;
    int flag = 1;
    for (int i = 0; i < 10; i++)
        if (count[i] != 0)
        {
            flag = 0;
            break;
        }
    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
    for (int i = index - 1; i >= 0; i--)
        putchar(dnum[i]);
    putchar('\n');
    return 0;
}
