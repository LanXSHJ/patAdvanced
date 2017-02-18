#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int num[10001];

int main(void)
{
    int N;
    cin >> N;
    int bets[N];
    for (int i = 0; i < N; i++)
    {
        cin >> bets[i];
        num[bets[i]]++;
    }
    for (int i = 0; i < N; i++)
        if (num[bets[i]] == 1)
        {
            cout << bets[i] << endl;
            return 0;
        }
    cout << "None" << endl;
    return 0;
}
