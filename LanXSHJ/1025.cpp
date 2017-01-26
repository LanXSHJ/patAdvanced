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
class testee {
public:
    string rNumber;
    int score;
    int localRank;
    int localNum;
    int finalRank;
    testee(string rNumber, int score, int localNum) :rNumber(rNumber), score(score), localNum(localNum) {};
    bool operator<(const testee& a) {
        if (score == a.score) {
            return rNumber < a.rNumber;
        }
        return score > a.score;
    }
};
vector<vector<testee>> allTestees;
vector<testee> allofAll;
int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        vector<testee> testees;
        for (int j = 0; j < k; j++) {
            string rNumber;
            int score;
            cin >> rNumber;
            cin >> score;
            testees.push_back(testee(rNumber, score, i + 1));
        }
        sort(testees.begin(), testees.end());
        int lastScore = -1, lastRank = 0;
        for (int j = 0; j < k; j++) {
            if (testees[j].score == lastScore) {
                testees[j].localRank = lastRank;
                allofAll.push_back(testees[j]);
                continue;
            }
            else {
                testees[j].localRank = lastRank = j + 1;
                lastScore = testees[j].score;
            }
            allofAll.push_back(testees[j]);
        }
    }
    sort(allofAll.begin(), allofAll.end());
    int lastScore = -1, lastRank = 0;
    cout << allofAll.size() << endl;
    for (int j = 0; j < allofAll.size(); j++) {
        if (allofAll[j].score == lastScore) {
            allofAll[j].finalRank = lastRank;
            cout << allofAll[j].rNumber << ' ' << allofAll[j].finalRank << ' ' << allofAll[j].localNum << ' ' << allofAll[j].localRank << endl;
            continue;
        }
        else {
            allofAll[j].finalRank = lastRank = j + 1;
            lastScore = allofAll[j].score;
        }
        cout << allofAll[j].rNumber << ' ' << allofAll[j].finalRank << ' ' << allofAll[j].localNum << ' ' << allofAll[j].localRank << endl;
    }
    return 0;
}