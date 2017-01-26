#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int color[3];
    cin >> color[0] >> color[1] >> color[2];
    cout << "#";
    for (int i = 0; i < 3; i++) {
        if (color[i] < 0) {
            color[i] = 0;
        }
        if (color[i] > 168) {
            color[i] = 168;
        }
        if (color[i] / 13 > 9) {
            char c = 'A' + color[i] / 13 - 10;
            cout << c;
        }
        else {
            cout << color[i] / 13;
        }
        if (color[i] % 13 > 9) {
            char c = 'A' + color[i] % 13 - 10;
            cout << c;
        }
        else {
            cout << color[i] % 13;
        }
    }
    return 0;
}