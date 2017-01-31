#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
typedef struct {
    int distance;
    int cost;
} Node;
Node G[512][512];
bool V[512];
vector<int> path;
vector<int> res(512);
int minCost = 1000000000;
int curCost;
int minDis = 1000000000;
int curDis;
int N, M, S, D;
void dfs(int t) {
    V[t] = true;
    path.push_back(t);
    if (t == D) {
        if (minDis > curDis) {
            res = path;
            minDis = curDis;
            minCost = curCost;
        }
        else if (minDis == curDis) {
            if (minCost > curCost) {
                res = path;
                minDis = curDis;
                minCost = curCost;
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (G[t][i].distance && !V[i]) {
                curCost += G[t][i].cost;
                curDis += G[t][i].distance;
                dfs(i);
                curDis -= G[t][i].distance;
                curCost -= G[t][i].cost;
            }
        }
    }
    path.pop_back();
    V[t] = false;
    return;
}
int main(void) {
    memset(G, 0, sizeof(G));
    memset(V, false, sizeof(V));
    int c1, c2, d, c;
    cin >> N >> M >> S >> D;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &c1, &c2, &d, &c);
        G[c1][c2].distance = G[c2][c1].distance = d;
        G[c1][c2].cost = G[c2][c1].cost = c;
    }
    dfs(S);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << minDis << ' ' << minCost;
    return 0;
}