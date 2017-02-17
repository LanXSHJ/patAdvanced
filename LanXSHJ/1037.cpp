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
vector<int> C, P;
int main(void) {
    int CN, PN;
    int t;
    long long sum = 0;
    scanf("%d", &CN);
    for (int i = 0; i < CN; i++) {
        scanf("%d", &t);
        C.push_back(t);
    }
    scanf("%d", &PN);
    for (int i = 0; i < PN; i++) {
        scanf("%d", &t);
        P.push_back(t);
    }
    sort(C.begin(), C.end());
    sort(P.begin(), P.end());
    int Cindex1 = 0;
    int Pindex1 = 0;
    while (C[Cindex1] < 0 && P[Pindex1] < 0) {
        sum += C[Cindex1] * P[Pindex1];
        Cindex1++;
        Pindex1++;
    }
    while (C[Cindex1] <= 0) {
        Cindex1++;
    }
    while (P[Pindex1] <= 0) {
        Pindex1++;
    }
    int Cindex2 = C.size() - 1;
    int Pindex2 = P.size() - 1;
    while (Cindex1 <= Cindex2 && Pindex1 <= Pindex2) {
        sum += C[Cindex2] * P[Pindex2];
        Cindex2--;
        Pindex2--;
    }
    cout << sum;
    return 0;
}