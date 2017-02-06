#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef struct
{
    string name;
    int size;
} H;

bool cmp(H a, H b)
{
    return a.name < b.name;
}

int main(void)
{
    int N, K;
    cin >> N >> K;
    int gangcnt = 0;
    set<string> Gang[N];
    int total[N];
    map<string, int> weight;
    for (int i = 0; i < N; i++)
    {
        string n1, n2;
        int time;
        cin >> n1 >> n2 >> time;
        int index1 = -1, index2 = -1;
        for (int j = 0; j < gangcnt; j++)
        {
            if (Gang[j].count(n1) != 0)
                index1 = j;
            if (Gang[j].count(n2) != 0)
                index2 = j;
            if (index1 != -1 && index2 != -1)
                break;
        }
        if (index1 == -1 && index2 == -1)
        {
            Gang[gangcnt].insert(n1);
            Gang[gangcnt].insert(n2);
            weight[n1] = time;
            weight[n2] = time;
            total[gangcnt] = time;
            gangcnt++;
        }
        else if (index1 == -1 && index2 != -1)
        {
            Gang[index2].insert(n1);
            weight[n1] = time;
            weight[n2] += time;
            total[index2] += time;
        }
        else if (index1 != -1 && index2 == -1)
        {
            Gang[index1].insert(n2);
            weight[n1] += time;
            weight[n2] = time;
            total[index1] += time;
        }
        else
        {
            if (index1 == index2)
            {
                weight[n1] += time;
                weight[n2] += time;
                total[index1] += time;
            }
            else
            {
                int min = index1 < index2 ? index1 : index2;
                int max = index1 < index2 ? index2 : index1;
                weight[n1] += time;
                weight[n2] += time;
                Gang[min].insert(Gang[max].begin(), Gang[max].end());
                total[min] = total[min] + total[max] + time;
                for (int j = max; j < gangcnt - 1; j++)
                {
                    Gang[j] = Gang[j + 1];
                    total[j] = total[j + 1];
                }
                gangcnt--;
            }
        }
    }
    int count = 0;
    H head[gangcnt];
    for (int i = 0; i < gangcnt; i++)
    {
        if (total[i] > K && Gang[i].size() > 2)
        {
            set<string>::iterator it;
            head[count].name = *(Gang[i].begin());
            head[count].size = Gang[i].size();
            for (it = Gang[i].begin(); it != Gang[i].end(); it++)
            {
                if (weight[head[count].name] < weight[*it])
                    head[count].name = *it;
            }
            count++;
        }
    }
    if (count == 0)
        printf("0\n");
    else
    {
        cout << count << endl;
        sort(head, head + count, cmp);
        for (int i = 0; i < count; i++)
            cout << head[i].name << " " << head[i].size << endl;
    }
    return 0;
}
