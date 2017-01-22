#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
void itoa(int N, vector<int>& a, int base,int ttttt) {
    vector<int> t;
    while (N) {
        t.push_back(N%base);
        N /= base;
    }
    int i = 0;
    while (!t.empty()) {
        a.push_back(t[t.size() - 1]);
        t.pop_back();
    }
    return;
}
int main() {
    int N, b;
    cin >> N >> b;
    vector<int> res;
    itoa(N, res, b, 0);
    bool flag = true;
    for (int i = 0; i < res.size() / 2; i++) {
        if (res[i] != res[res.size() - i - 1]) {
            flag = false;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    flag = false;
    for (int i = 0; i < res.size(); i++) {
        if (flag) {
            cout << ' ';
        }
        flag = true;
        cout << res[i];
    }
    if (!N) {
        cout << 0;
    }
    return 0;
}