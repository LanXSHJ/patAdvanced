/*#include <string>
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
map<string, string> goNext;
vector<string> ss1(100000);
vector<string> ss2(100000);

int main() {
    char s1[16], s2[16], s3[16];
    int n;
    string start1, start2;
    cin >> start1;
    cin >> start2;
    cin >> n;
    getchar();
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s%s%s", s1, s2, s3);
        goNext[s1] = s3;
    }
    do {
        ss1[index1] = start1;
        if (goNext.count(start1) == 0) {
            break;
        }
        start1 = goNext[start1];
        index1++;
    } while (start1 != "-1");
    if(start1 == "-1")
        ss1[index1] = "-1";
    do {
        ss2[index2] = start2;
        if (goNext.count(start2) == 0) {
            break;
        }
        index2++;
        start2 = goNext[start2];
    } while (start2 != "-1");
    if (start2 == "-1")
        ss2[index2] = "-1";
    while (index1 >= 0 && index2 >= 0 && ss1[index1] == ss2[index2]) {
        index1--;
        index2--;
    }
    cout << ss1[index1 + 1];
    return 0;
}*/
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

typedef struct {
    char c;
    int next;
    bool visited;
} sbPAT;

int main(void) {
    int start1, start2, n;
    sbPAT nodes[100005];
    int address;
    scanf("%d%d%d", &start1, &start2, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &address);
        nodes[address].visited = false;
        scanf("%c %d", &nodes[address].c, &nodes[address].next);
    }
    int next = start1;
    while (next != -1) {
        nodes[next].visited = true;
        next = nodes[next].next;
    }
    next = start2;
    while (next != -1) {
        if (nodes[next].visited) {
            break;
        }
        next = nodes[next].next;
    }
    if (next == -1) {
        printf("-1\n");
    }
    else {
        printf("%05d\n", next);
    }
    return 0;
}