#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
string nextString(string s) {
    int carry = 0;
    char ss[1000] = { 0 };
    int len = s.length();
    string s1 = s, s2 = s;
    reverse(s2.begin(), s2.end());
    for (int i = len - 1; i >= 0; i--) {
        int t = s1[i] - '0' + s2[i] - '0';
        t += carry;
        carry = t / 10;
        t %= 10; 
        ss[i + 1] = t + '0';
    }
    if (carry) {
        ss[0] = '1';
        return ss;
    }
    else {
        return ss + 1;
    }
}
bool isPalindromic(string s) {
    string ss = s;
    reverse(ss.begin(), ss.end());
    if (ss != s) {
        return false;
    }
    return true;
}
int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    int i = 1;
    while (s[0] == '0' && s.length() > 1) {
        s = s.substr(1);
    }
    if (isPalindromic(s)) {
        cout << s << endl << 0;
        return 0;
    }
    for (; i <= k; i++) {
        s = nextString(s);
        if (isPalindromic(s)) {
            break;
        }
    }
    if (i > k) {
        i = k;
    }
    cout << s << endl << i;
    return 0;
}