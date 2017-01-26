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
class people {
public:
    int hh, mm, ss, time, isVIP;
    people(int hh, int mm, int ss, int time, int isVIP) :hh(hh), mm(mm), ss(ss), time(time), isVIP(isVIP) {};
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
                else if (ss == a.ss) {
                    if (isVIP > a.isVIP) {
                        return true;
                    }
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
    bool operator>(const people& a) {
        return !(*this < a || *this == a);
    }
    people& operator += (const int& a) {
        mm += a;
        if (mm >= 60) {
            mm %= 60;
            hh++;
        }
        return *this;
    }
    int operator - (const people& a) {
        int sum = 0;
        sum += (hh - a.hh) * 60 * 60;
        sum += (mm - a.mm) * 60;
        sum += (ss - a.ss);
        return ceil(1.0 * sum / 60);
    }
};
int isVIPTable[128];
int main() {
    int n, k, vn;
    vector<people> p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, time, isVIP;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &time, &isVIP);
        time = (time > 120) ? 120 : time;
        p.push_back(people(hh, mm, ss, time, isVIP));
    }
    sort(p.begin(), p.end());
    scanf("%d%d", &k, &vn);
    vector<people> tableTime;
    for (int i = 0; i < vn; i++) {
        int tt;
        scanf("%d", &tt);
        isVIPTable[tt - 1] = true;
    }
    for (int i = 0; i < k; i++) {
        tableTime.push_back(people(8, 0, 0, 0, 0));
    }
    people curTime(8, 0, 0, 0, 0);
    vector<int> cnt;
    cnt.assign(k, 0);
    while (true) {
        int waitTime = 0;
        int index = 0;
        int pIndex = -1;
        people min = tableTime[0];
        for (int j = 1; j < tableTime.size(); j++) {
            if (tableTime[j] < min || (tableTime[j] == min && isVIPTable[j])) {
                min = tableTime[j];
                index = j;
            }
        }
        if (isVIPTable[index]) {
            int j;
            for (j = 0; j < p.size() && !(p[j] > tableTime[index]); j++) {
                if (p[j].isVIP) {
                    pIndex = j;
                    break;
                }
            }
            if (pIndex == -1) {
                pIndex = 0;
            }
        }
        else {
            pIndex = 0;
        }
        if (!p[pIndex].isVIP) {
            min = tableTime[0];
            index = 0;
            for (int j = 1; j < tableTime.size(); j++) {
                if (tableTime[j] < min) {
                    min = tableTime[j];
                    index = j;
                }
            }
        }
        if (!(tableTime[index] < people(21, 0, 0, 0, 0))) {
            break;
        }
        if (tableTime[index] < p[pIndex]) {
            tableTime[index] = p[pIndex];
            if (!(tableTime[index] < people(21, 0, 0, 0, 0))) {
                break;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d 0\n", p[pIndex].hh, p[pIndex].mm, p[pIndex].ss, p[pIndex].hh, p[pIndex].mm, p[pIndex].ss);
        }
        else {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", p[pIndex].hh, p[pIndex].mm, p[pIndex].ss, tableTime[index].hh, tableTime[index].mm, tableTime[index].ss, tableTime[index] - p[pIndex]);
        }
        tableTime[index] += p[pIndex].time;
        cnt[index]++;
        vector<people>::iterator it = p.begin();
        while (pIndex--) {
            it++;
        }
        p.erase(it);
    }
    bool FU = false;
    for (int i = 0; i < cnt.size(); i++) {
        if (FU) {
            printf(" ");
        }
        FU = true;
        printf("%d", cnt[i]);
    }
    return 0;
}