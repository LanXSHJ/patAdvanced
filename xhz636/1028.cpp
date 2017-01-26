#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct
{
    int id;
    char name[12];
    int score;
} T;

bool cmp1(T a, T b)
{
    return a.id < b.id;
}

bool cmp2(T a, T b)
{
    int result = strcmp(a.name, b.name);
    if (result != 0)
        return result < 0;
    else
        return a.id < b.id;
}

bool cmp3(T a, T b)
{
    if (a.score != b. score)
        return a.score < b.score;
    else
        return a.id < b.id;
}

int main(void)
{
    int N, C;
    cin >> N >> C;
    T S[N];
    for (int i = 0; i < N; i++)
        scanf("%d %s %d", &S[i].id, S[i].name, &S[i].score);
    if (C == 1)
        sort(S, S + N, cmp1);
    else if (C == 2)
        sort(S, S + N, cmp2);
    else if (C == 3)
        sort(S, S + N, cmp3);
    for (int i = 0; i < N; i++)
        printf("%06d %s %d\n", S[i].id, S[i].name, S[i].score);
    return 0;
}
