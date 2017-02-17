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
int dp[1024][1024];
int main(void) {
    string s;
    getline(cin, s);
    string reverseS(s);
    reverse(begin(reverseS), end(reverseS));
    int sLen = s.size();
    memset(dp, 0, sizeof(dp));
    int max = -1, index = -1;
    for (int i = 0; i < sLen; i++) {
        for (int j = 0; j < sLen; j++) {
            if (s[i] == reverseS[j]) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (max < dp[i][j]) {
                    max = dp[i][j];
                    index = i - max + 1;
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}