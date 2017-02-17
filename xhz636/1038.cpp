#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    string ab = a + b;
    string ba = b + a;
    return ab < ba;
}

int main(void)
{
    int N;
    cin >> N;
    string num[N];
    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N, cmp);
    int index = 0;
    do {
        while (num[index][0] == '0')
            num[index] = num[index].substr(1);
        index++;
    } while (index < N && num[index - 1].size() == 0);
    if (index == N && num[index - 1].size() == 0)
        num[index - 1] = "0";
    for (int i = 0; i < N; i++)
        cout << num[i];
    cout << endl;
    return 0;
}
