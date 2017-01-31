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
char U[128][128];
int main() {
    string s;
    memset(U, ' ', sizeof(U));;
    cin >> s;
    int n = s.length();
    int t = (n + 2) / 3;
    int zz = 0;
    for (int i = 0; i < t; i++) {
        U[i][0] = s[zz++];
        U[i][n - 2 * t + 2] = '\0';
    }
    for (int i = 1; i <= n - 2 * t; i++) {
        U[t - 1][i] = s[zz++];
    }
    for (int i = t - 1; i >= 0; i--) {
        U[i][n - 2 * t + 1] = s[zz++];
    }
    for (int i = 0; i < t; i++) {
        cout << U[i] << endl;
    }
    return 0;
}