#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
class people{
public:
    int hh, mm, ss, time;
    people(int hh, int mm, int ss, int time) :hh(hh), mm(mm), ss(ss), time(time) {};
    bool operator<(const people& a) {
        if (hh < a.hh) {
            return true;
        }
        else if (hh == a.hh) {
            if (mm < a.mm) {
                return true;
            }
            else if (mm == a.mm) {
                if (ss < a.ss) {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator==(const people& a) {
        if (hh == a.hh && mm == a.mm && ss == a.ss) {
            return true;
        }
        return false;
    }
    people& operator += (const int& a) {
        mm += a;
        if (mm >= 60) {
            mm %= 60;
            hh++;
        }
        return *this;
    }
    people& operator = (const people& a) {
        hh = a.hh;
        mm = a.mm;
        ss = a.ss;
        time = a.time;
        return *this;
    }
    int& operator - (const people& a) {
        int sum = 0;
        sum += (hh - a.hh) * 60 * 60;
        sum += (mm - a.mm) * 60;
        sum += (ss - a.ss);
        return sum;
    }
};
int main() {
    int n, k;
    vector<people> p;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        time = (time > 60) ? 60 : time;
        p.push_back(people(hh, mm, ss, time));
    }
    sort(p.begin(), p.end());
    vector<people> curTime;
    for (int i = 0; i < k; i++) {
        curTime.push_back(people(8, 0, 0, 0));
    }
    int waitTime = 0;
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        int index = 0;
        people min = curTime[0];
        for (int j = 1; j < curTime.size(); j++) {
            if (curTime[j] < min) {
                min = curTime[j];
                index = j;
            }           
        }
        if (curTime[index] < p[i]) {
            curTime[index] = p[i];
        }
        if (!(curTime[index] < people(17, 0, 0, 0) || curTime[index] == people(17, 0, 0, 0))) {
            break;
        }
        waitTime += curTime[index] - p[i];
        curTime[index] += p[i].time;
        cnt++;
    }
    double avgTime = 1.0 * waitTime / 60 / cnt;
    if (cnt != 0) {
        printf("%.1lf", avgTime);
    }
    else {
        printf("0.0");
    }
    
    return 0;
}