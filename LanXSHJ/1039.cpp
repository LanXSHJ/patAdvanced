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
vector<int> coutList[26 * 26 * 26 * 10 + 1];
int main(void) {
    int N, K;
    scanf("%d%d\n", &N, &K);
    for (int i = 0; i < K; i++) {
        int courseID;
        int courseStuNum;
        scanf("%d%d\n", &courseID, &courseStuNum);
        for (int j = 0; j < courseStuNum; j++) {
            char name[16];
            scanf("%s", name);
            int index = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
            coutList[index].push_back(courseID);
        }
    }
    for (int i = 0; i < N; i++) {
        char name[16];
        scanf("%s", name);
        int index = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
        sort(coutList[index].begin(), coutList[index].end());
        printf("%s %d", name, coutList[index].size());
        for (int j = 0; j < coutList[index].size(); j++) {
            printf(" %d", coutList[index][j]);
        }
        putchar('\n');
    }
    return 0;
}