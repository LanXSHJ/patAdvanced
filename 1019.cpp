#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N, b;
    int num[100];
    int count = 0;
    cin >> N >> b;
    while (N > 0)
    {
        num[count++] = N % b;
        N /= b;
    }
    if (count == 0)
        num[count++] = 0;
    int flag = 1;
    for (int i = 0; i < count; i++)
        if (num[i] != num[count - 1 - i])
        {
            flag = 0;
            break;
        }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << num[count - 1];
    for (int i = count - 2; i >= 0; i--)
        cout << " " << num[i];
    cout << endl;
    return 0;
}
