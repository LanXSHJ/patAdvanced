#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> G;
int visited[10005];
int n;
int maxH = -1;
vector<int> res;
int getHeight(int index) {
    visited[index] = 1;
    int hmax = 1;
    for (int i = 0; i < G[index].size(); i++) {
        if (!visited[G[index][i]]) {
            int h = getHeight(G[index][i]) + 1;
            hmax = (h > hmax) ? h : hmax;
        }
    }
    return hmax;
}
void find(int index) {
    visited[index] = 1;
    for (int i = 0; i < G[index].size(); i++) {
        if (!visited[G[index][i]]) {
            find(G[index][i]); 
        }
    }
    return;
}
int main() {
    cin >> n;
    G.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int con = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            con++;
            find(i);
        }
    }
    if (con > 1) {
        cout << "Error: " << con << " components" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int h = getHeight(i);
        if (h > maxH) {
            maxH = h;
            res.clear();
            res.push_back(i);
        }
        else if (h == maxH) {
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}