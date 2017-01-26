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
typedef struct {
    int id;
    char name[10];
    int grade;
}record;
int n, c;
vector<record> allR;
bool cmp(const record &a, const record &b) {
    switch (c) {
    case 1:return a.id < b.id; break;
    case 2:if (strcmp(a.name, b.name) == 0)return a.id < b.id; else return strcmp(a.name, b.name) < 0; break;
    case 3:if (a.grade == b.grade)return a.id < b.id; else return a.grade < b.grade; break;
    default:break;
    }
}
int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        record tr;
        scanf("%d %s %d", &tr.id, tr.name, &tr.grade);
        allR.push_back(tr);
    }
    sort(allR.begin(), allR.end(), cmp);
    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", allR[i].id, allR[i].name, allR[i].grade);
    }
}