#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
char ss[32];
int mark[10];
int mark_[10];
int heiheihei = 0;
int main() {
    cin >> s;
    if (s[0] > '4') {
        heiheihei = 1;
    }
    int carry = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        int t = s[i] - '0';
        mark[t]++;
        t *= 2;
        t += carry;
        carry = t / 10;
        t %= 10;
        mark_[t]++;
        ss[i + heiheihei] = t + '0';
    }
    if (carry) {
        ss[0] = '1';
    }
    if (heiheihei) {
        cout << "No" << endl;
        cout << ss;
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (mark[i] != mark_[i]) {
            cout << "No" << endl;
            cout << ss;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << ss;
    return 0;
}