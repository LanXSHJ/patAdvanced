#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

int N;
list<int> edge[10001];

int circle()
{
    int count = 0;
    int visit[10001];
    for (int i = 1; i <= N; i++)
        visit[i] = 0;
    for (int i = 1; i <= N; i++)
    {
        int circle = 0;
        if (visit[i] == 0)
        {
            visit[i] = 1;
            list<int> order;
            order.push_back(i);
            while (order.size())
            {
                int v = order.front();
                order.pop_front();
                list<int>::iterator it;
                if (edge[v].size() == 0)
                {
                    circle = 1;
                    break;
                }
                for (it = edge[v].begin(); it != edge[v].end(); it++)
                {
                    if (*it != v && visit[*it])
                        circle = 1;
                    else
                    {
                        visit[*it] = 1;
                        order.push_back(*it);
                    }
                }
            }
        }
        count += circle;
    }
    return count;
}

int find(int last, int v)
{
    list<int>::iterator it;
    int max = 0;
    for (it = edge[v].begin(); it != edge[v].end(); it++)
    {
        int deep = 0;
        if (*it != last)
            deep = find(v, *it) + 1;
        if (max < deep)
            max = deep;
    }
    return max;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
    int com = circle();
    if (com > 1)
        cout << "Error: " << com << " components" << endl;
    else
    {
        int max = 0, deep;
        list<int> root;
        for (int i = 1; i <= N; i++)
        {
            deep = find(0, i);
            if (max < deep)
            {
                max = deep;
                root.clear();
            }
            if (deep == max)
                root.push_back(i);
        }
        list<int>::iterator it;
        for (it = root.begin(); it != root.end(); it++)
            cout << *it << endl;
    }
    return 0;
}
