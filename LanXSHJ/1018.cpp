#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct GNode* MGraph;
struct GNode {
    int Nv;
    int Ne;
    int G[512][512];
};
typedef struct {
    int bringBack;
    int takeAway;
}BikeNum;
vector<int> nowBikeNum;
int dist[512];
vector<int> path[512];
vector<int> result;
vector<int> realResult;
int minBikeNum = 1000000000;
int backBikeNum;
int CMax;
MGraph ReadG(int V, int E);
void ShortestDist(MGraph Graph, int S);
void DFS(int src, int des);
BikeNum caculateBikeNum(vector<int> resPath);
int main() {
    int N, badStation, M;
    cin >> CMax >> N >> badStation >> M;
    nowBikeNum.push_back(0);
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        nowBikeNum.push_back(t);
    }
    MGraph G = ReadG(N, M);
    ShortestDist(G, 0);
    result.clear();
    DFS(0, badStation);
    cout << minBikeNum << ' ';
    cout << 0;
    for (int i = realResult.size() - 1; i >= 0; i--) {
        cout << "->" << realResult[i];
    }
    cout << ' ' << backBikeNum;
    return 0;
}
BikeNum caculateBikeNum(vector<int> resPath) {
    int min = 1000000000;
    int now = 0;
    for (int i = resPath.size() - 1; i >= 0; i--) {
        now += nowBikeNum[resPath[i]] - CMax / 2;
        if (now < 0) {
            min = (min > now) ? now : min;
        }
    }
    BikeNum t;
    if (min < 0) {
        t.takeAway = -min;
        t.bringBack = now + t.takeAway;
    }
    else {
        t.takeAway = 0;
        t.bringBack = now;
    }
    return t;
}
void DFS(int src, int des) {
    if (src == des) {
        BikeNum bikeNum = caculateBikeNum(result);
        if (bikeNum.takeAway < minBikeNum || (bikeNum.takeAway == minBikeNum && bikeNum.bringBack < backBikeNum)) {
            minBikeNum = bikeNum.takeAway;
            backBikeNum = bikeNum.bringBack;
            realResult = result;
        }
        return;
    }
    for (int i = 0; i < path[des].size(); i++) {
        result.push_back(des);
        DFS(src, path[des][i]); 
        result.pop_back();
    }
    return;
}

void ShortestDist(MGraph Graph, int S) {
    int V;
    int min;
    int i, know[512];
    memset(know, 0, sizeof(know));
    for (i = 0; i < Graph->Nv; i++) {
        dist[i] = 100000000;
        path[i].clear();
        know[i] = 0;
    }
    dist[S] = 0;
    know[S] = 1;
    for (i = 0; i < Graph->Nv; i++) {
        if (i != S && Graph->G[S][i] > 0 && dist[i] > dist[S] + Graph->G[S][i]) {
            dist[i] = dist[S] + Graph->G[S][i];
            path[i].push_back(S);
        }
    }
    while (true) {
        min = 100000000;
        for (i = 0; i < Graph->Nv; i++) {
            if (!know[i]) {
                if (dist[i] < min) {
                    V = i;
                    min = dist[i];
                }
            }
        }
        if (min == 100000000)break;
        know[V] = 1;
        for (i = 0; i < Graph->Nv; i++) {
            if (i != V && Graph->G[V][i] > 0 && dist[i] >= dist[V] + Graph->G[V][i]) {
                if (dist[i] == dist[V] + Graph->G[V][i]) {
                    path[i].push_back(V);
                }
                else {
                    dist[i] = dist[V] + Graph->G[V][i];
                    path[i].clear();
                    path[i].push_back(V);
                }
            }
        }
    }
    for (i = 0; i < Graph->Nv; i++) {
        if (dist[i] == 100000000) {
            dist[i] = -1;
            path[i].clear();
        }
    }
    return;
}
MGraph ReadG(int V, int E) {
    MGraph G;
    int i, j, a, b;
    G = (MGraph)malloc(sizeof(struct GNode));
    G->Nv = V + 1;
    G->Ne = E;
    for (i = 0; i < G->Nv; i++) {
        for (j = 0; j < G->Nv; j++) {
            G->G[i][j] = -1;
        }
    }
    for (i = 0; i < G->Ne; i++) {
        scanf("%d %d", &a, &b);
        scanf("%d", &G->G[a][b]);
        G->G[b][a] = G->G[a][b];
    }
    return G;
}