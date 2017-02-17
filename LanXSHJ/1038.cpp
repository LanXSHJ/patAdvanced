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
vector<string> seg;
bool cmp(string s1, string s2)
{
    return s1 + s2 < s2 + s1;
}
int main(void) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string t;
        cin >> t;
        seg.push_back(t);
    }
    sort(seg.begin(), seg.end(),cmp);
    string res;
    for (int i = 0; i < seg.size(); i++) {
        res += seg[i];
    }
    int index = 0;
    while (res[index] == '0' && index != res.length() - 1) {
        index++;
    }
    cout << res.substr(index);
    return 0;
}