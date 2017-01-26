#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct
{
    int atime;
    int ptime;
    int vip;
} P;

bool cmp(P a, P b)
{
    return a.atime < b.atime;
}

int main(void)
{
    int N;
    cin >> N;
    P S[N];
    for (int i = 0; i < N; i++)
    {
        int h, m, s;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &S[i].ptime, &S[i].vip);
        if (S[i].ptime > 120)
            S[i].ptime = 120;
        S[i].atime = h * 3600 + m * 60 + s;
    }
    sort(S, S + N, cmp);
    int K, M;
    cin >> K >> M;
    int time[K];
    int vip[K];
    int count[K];
    for (int i = 0; i < K; i++)
    {
        time[i] = 8 * 3600;
        vip[i] = 0;
        count[i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        vip[num - 1] = 1;
    }
    for (int i = 0; i < N; i++)
    {
        int index;
        int fast = 0;
        for (int j = 1; j < K; j++)
            if (time[j] < time[fast])
                fast = j;
        if (time[fast] <= S[i].atime)
        {
            if (!S[i].vip)
            {
                for (index = 0; index < K; index++)
                    if (time[index] <= S[i].atime)
                        break;
            }
            else
            {
                for (index = 0; index < K; index++)
                    if (time[index] <= S[i].atime && vip[index])
                        break;
                if (index == K)
                {
                    for (index = 0; index < K; index++)
                        if (time[index] <= S[i].atime)
                            break;
                }
            }
        }
        else
        {
            int hasvip = 0;
            int hasviptable = 0;
            int vipindex;
            for (int j = i; j < N && S[j].atime <= time[fast]; j++)
                if (S[j].vip)
                {
                    hasvip = 1;
                    vipindex = j;
                    break;
                }
            for (int j = 0; j < K; j++)
                if (time[j] == time[fast] && vip[j])
                {
                    hasviptable = 1;
                    index = j;
                    break;
                }
            if (hasvip && hasviptable)
            {
                P temp = S[vipindex];
                for (int j = vipindex; j > i; j--)
                    S[j] = S[j - 1];
                S[i] = temp;
            }
            else
                index = fast;
        }
        int arrtime, sertime, waitime;
        arrtime = S[i].atime;
        if (arrtime > time[index])
            sertime = arrtime;
        else
            sertime = time[index];
        waitime = sertime - arrtime;
        if (sertime >= 21 * 3600)
            break;
        count[index]++;
        time[index] = sertime + S[i].ptime * 60;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
                arrtime / 3600, arrtime / 60 % 60, arrtime % 60,
                sertime / 3600, sertime / 60 % 60, sertime % 60,
                waitime / 60 + (waitime % 60 < 30 ? 0 : 1));
    }
    cout << count[0];
    for (int i = 1; i < K; i++)
        cout << " " << count[i];
    cout << endl;
    return 0;
}
