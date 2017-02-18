#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int Mirror;
int BST(int* node, int N)
{
    if (N <= 1)
        return 1;
    else
    {
        int index = -1;
        if (Mirror == 1)
        {
            for (int i = 1; i < N; i++)
            {
                if (index == -1 && node[i] >= node[0])
                    index = i;
                if (index != -1 && node[i] < node[0])
                    return 0;
            }
            if (index == -1)
                index = N;
            return BST(node + 1, index - 1)
                && BST(node + index, N - index);
        }
        else if (Mirror == 2)
        {
            for (int i = 1; i < N; i++)
            {
                if (index == -1 && node[i] < node[0])
                    index = i;
                if (index != -1 && node[i] >= node[0])
                    return 0;
            }
            if (index == -1)
                index = N;
            return BST(node + 1, index - 1)
                && BST(node + index, N - index);
        }
    }
}

int first = 1;
int Post(int* node, int N)
{
    if (N > 1)
    {
        int index = -1;
        if (Mirror == 1)
        {
            for (int i = 1; i < N; i++)
            {
                if (index == -1 && node[i] >= node[0])
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                index = N;
            Post(node + 1, index - 1);
            Post(node + index, N - index);
        }
        else if (Mirror == 2)
        {
            for (int i = 1; i < N; i++)
            {
                if (index == -1 && node[i] < node[0])
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                index = N;
            Post(node + 1, index - 1);
            Post(node + index, N - index);
        }
    }
    if (N >= 1)
    {
        if (first)
        {
            cout << *node;
            first = 0;
        }
        else
            cout << " " << *node;
    }
}

int main(void)
{
    int N;
    cin >> N;
    int node[N];
    for (int i = 0; i < N; i++)
    {
        cin >> node[i];
        if (Mirror == 0)
        {
            if (node[i] < node[0])
                Mirror = 1;
            else if (node[i] > node[0])
                Mirror = 2;
        }
    }
    if (Mirror == 0)
        Mirror = 1;
    if (BST(node, N))
    {
        cout << "YES" << endl;
        Post(node, N);
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
