#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

int main(void)
{
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    int T[K], E[K];
    for (int i = 0; i < K; i++)
        cin >> T[i];
    int W[N];
    for (int i = 0; i < N; i++)
        W[i] = 8 * 60;
    list<int> L[N];
    int customer = 0;
    int flag = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            L[j].push_back(customer++);
            if (customer == K)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    while (customer < K)
    {
        int min = 0;
        for (int i = 1; i < N; i++)
            if (W[i] + T[L[i].front()] < W[min] + T[L[min].front()])
                min = i;
        int index = L[min].front();
        if (W[min] < 17 * 60)
            E[index] = W[min] + T[index];
        else
            E[index] = 1000000;
        W[min] = E[index];
        L[min].pop_front();
        L[min].push_back(customer++);
    }
    for (int i = 0; i < N; i++)
        while (L[i].size())
        {
            int index = L[i].front();
            if (W[i] < 17 * 60)
                E[index] = W[i] + T[index];
            else
                E[index] = 1000000;
            W[i] = E[index];
            L[i].pop_front();
        }
    for (int i = 0; i < Q; i++)
    {
        int index;
        cin >> index;
        index--;
        if (E[index] >= 1000000)
            cout << "Sorry" << endl;
        else
            printf("%02d:%02d\n", E[index] / 60, E[index] % 60);
    }
    return 0;
}
