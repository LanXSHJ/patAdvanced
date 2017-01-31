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
vector<long int> s1;
vector<long int> s2;
int main() {
    int n, m;
    long int t;
    long int cur;
    int cnt = 0;
    int index1 = 0;
    cin >> n;
    s1.assign(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &t);
        s1[i] = t;
    }
    cin >> m;
    s2.assign(m, 0);
    for (int i = 0; i < m; i++) {
        scanf("%ld", &t);
        while (index1 < n && s1[index1] < t) {
            cur = s1[index1];
            index1++;
            cnt++;
            if (cnt == (n + m + 1) / 2) {
                printf("%ld", cur);
                return 0;
            }
        }
        cur = t;
        cnt++;
        if (cnt == (n + m + 1) / 2) {
            printf("%ld", cur);
            return 0;
        }
    }
    while (cnt != (n + m + 1) / 2) {
        cur = s1[index1++];
        cnt++;
    }
    printf("%ld", cur);
    return 0;
}