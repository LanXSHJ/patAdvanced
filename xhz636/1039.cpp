#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

set<int> stu[26 * 26 * 26 * 10];

int main(void)
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int index, Ni;
        scanf("%d %d", &index, &Ni);
        for (int j = 0; j < Ni; j++)
        {
            char name[5];
            int num;
            scanf("%s", name);
            num = (name[0] - 'A') * 26 * 26 * 10
                + (name[1] - 'A') * 26 * 10
                + (name[2] - 'A') * 10
                + (name[3] - '0');
            stu[num].insert(index);
        }
    }
    for (int i = 0; i < N; i++)
    {
        char name[5];
        int num;
        scanf("%s", name);
        num = (name[0] - 'A') * 26 * 26 * 10
            + (name[1] - 'A') * 26 * 10
            + (name[2] - 'A') * 10
            + (name[3] - '0');
        printf("%s %d", name, stu[num].size());
        set<int>::iterator it;
        for (it = stu[num].begin(); it != stu[num].end(); it++)
            printf(" %d", *it);
        putchar('\n');
    }
    return 0;
}
