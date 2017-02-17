#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    char str[1004];
    gets(str);
    int len = strlen(str);
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        int lenc = 1, lenm = 0;
        int c = i, l = i + 1, r = i;
        int isc = 1, ism = 1;
        for (int j = 1; isc || ism; j++)
        {
            if (isc && c - j >= 0 && c + j < len
                    && str[c - j] == str[c + j])
            {
                lenc += 2;
            }
            else
                isc = 0;
            if (ism && l - j >= 0 && r + j < len
                    && str[l - j] == str[r + j])
            {
                lenm += 2;
            }
            else
                ism = 0;
        }
        if (lenc > max)
            max = lenc;
        if (lenm > max)
            max = lenm;
    }
    cout << max << endl;
    return 0;
}
