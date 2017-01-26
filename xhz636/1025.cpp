#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{
    string id;
    int score;
    int loc;
    int lrank;
} T;

bool cmp(T a, T b)
{
    if (a.score != b.score)
        return b.score < a.score;
    else
        return a.id < b.id;
}

int main(void)
{
    int N;
    cin >> N;
    int K[N];
    int C[N];
    T P[30000];
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> K[i];
        C[i] = count;
        for (int j = 0; j < K[i]; j++)
        {
            cin >> P[C[i] + j].id >> P[C[i] + j].score;
            P[C[i] + j].loc = i + 1;
        }
        count += K[i];
    }
    for (int i = 0; i < N; i++)
    {
        sort(P + C[i], P + C[i] + K[i], cmp);
        int rank, score = -1;
        for (int j = 0; j < K[i]; j++)
        {
            if (P[C[i] + j].score != score)
            {
                rank = j + 1;
                score = P[C[i] + j].score;
            }
            P[C[i] + j].lrank = rank;
        }
    }
    sort(P, P + count, cmp);
    cout << count << endl;
    int rank, score = -1;
    for (int i = 0; i < count; i++)
    {
        if (P[i].score != score)
        {
            rank = i + 1;
            score = P[i].score;
        }
        cout << P[i].id << " " << rank << " " << P[i].loc
            << " " << P[i].lrank << endl;
    }
    return 0;
}
