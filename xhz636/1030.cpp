#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;
#define INF 0x7FFFFFFF

typedef struct
{
    int city;
    int dist;
    int cost;
} Way;

int dist = INF;
int cost = INF;
list<int> path;
int tempdist = 0;
int tempcost = 0;
list<int> temppath;
list<Way> way[500];
int visit[500];
int N, M, S, D;

void find(int index)
{
    if (visit[index])
        return;
    else
    {
        visit[index] = 1;
        temppath.push_back(index);
        if (index == D)
        {
            if (tempdist < dist ||
                    tempdist == dist && tempcost < cost)
            {
                dist = tempdist;
                cost = tempcost;
                path = temppath;
            }
        }
        else
        {
            list<Way>::iterator it;
            for (it = way[index].begin(); it != way[index].end(); it++)
            {
                tempdist += it->dist;
                tempcost += it->cost;
                find(it->city);
                tempdist -= it->dist;
                tempcost -= it->cost;
            }
        }
        temppath.pop_back();
        visit[index] = 0;
    }
}

int main(void)
{
    cin >> N >> M >> S >> D;
    for (int i = 0; i < M; i++)
    {
        int c1, c2, d, c;
        Way w1, w2;
        cin >> c1 >> c2 >> d >> c;
        w1.city = c2;
        w2.city = c1;
        w1.dist = w2.dist = d;
        w1.cost = w2.cost = c;
        way[c1].push_back(w1);
        way[c2].push_back(w2);
    }
    for (int i = 0; i < N; i++)
        visit[i] = 0;
    find(S);
    cout << S;
    path.pop_front();
    while (path.size())
    {
        cout << " " << path.front();
        path.pop_front();
    }
    cout << " " << dist << " " << cost << endl;
    return 0;
}
