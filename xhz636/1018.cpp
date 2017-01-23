#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;
#define INF 0x7FFFFFFF
typedef struct
{
    int count;
    int S[500];
    int T[500];
} E;
typedef struct
{
    int Time, Take, Judg;
} V;

int C, N, S, M;
int B[501];
E R[501];
V D[501];
int btime = INF, btake, bjudg;
list<int> btrace;

void find(list<int>& trace, int index, int S, int* remain)
{
    for (int i = 0; i < R[index].count; i++)
    {
        int si;
        si = R[index].S[i];
        if (remain[si] == 0)
            continue;
        else
            remain[si] = 0;
        trace.push_back(si);
        D[si].Time = D[index].Time + R[index].T[i];
        D[si].Take = D[index].Take + B[si] - C / 2;
        D[si].Judg = D[si].Take < D[index].Judg ? D[si].Take : D[index].Judg;
        if (si == S)
        {
            if (btime > D[si].Time ||
                    (btime == D[si].Time &&
                     (bjudg < D[si].Judg ||
                      bjudg == D[si].Judg && btake > D[si].Take)))
            {
                btime = D[si].Time;
                btake = D[si].Take;
                bjudg = D[si].Judg;
                btrace = trace;
            }
        }
        else if (D[si].Time < btime)
        {
            find(trace, si, S, remain);
        }
        remain[si] = 1;
        trace.pop_back();
    }
}

int main(void)
{
    cin >> C >> N >> S >> M;
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    for (int i = 0; i <= N; i++)
        R[i].count = 0;
    for (int i = 0; i < M; i++)
    {
        int S1, S2, T;
        cin >> S1 >> S2 >> T;
        R[S1].S[R[S1].count] = S2;
        R[S1].T[R[S1].count] = T;
        R[S1].count++;
        R[S2].S[R[S2].count] = S1;
        R[S2].T[R[S2].count] = T;
        R[S2].count++;
    }
    int remain[501];
    for (int i = 0; i <= N; i++)
        remain[i] = 1;
    list<int> trace;
    trace.push_back(0);
    remain[0] = 0;
    D[0].Time = 0;
    D[0].Take = 0;
    D[0].Judg = 0;
    find(trace, 0, S, remain);
    if (bjudg >= 0)
        cout << 0 << " ";
    else
        cout << (-bjudg) << " ";
    cout << btrace.front();
    btrace.pop_front();
    while (btrace.size())
    {
        cout << "->" << btrace.front();
        btrace.pop_front();
    }
    cout << " " << btake - bjudg << endl;
    return 0;
}
