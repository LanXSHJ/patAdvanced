#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string name(int index)
{
    string num[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "11", "12", "13"};
    string type[5] = {"S", "H", "C", "D", "J"};
    index--;
    return type[index / 13] + num[index % 13];
}

int main(void)
{
    int pos[55];
    int card1[55];
    int card2[55];
    int K;
    cin >> K;
    for (int i = 1; i <= 54; i++)
    {
        cin >> pos[i];
        card1[i] = i;
    }
    for (int i = 0; i < K; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 1; j <= 54; j++)
                card2[pos[j]] = card1[j];
        }
        else
        {
            for (int j = 1; j <= 54; j++)
                card1[pos[j]] = card2[j];
        }
    }
    if (K % 2 == 0)
    {
        cout << name(card1[1]);
        for (int j = 2; j <= 54; j++)
            cout << " " << name(card1[j]);
        cout << endl;
    }
    else
    {
        cout << name(card2[1]);
        for (int j = 2; j <= 54; j++)
            cout << " " << name(card2[j]);
        cout << endl;
    }
    return 0;
}
