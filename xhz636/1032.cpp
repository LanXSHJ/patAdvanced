#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct
{
    char data;
    int next;
} Node;

int main(void)
{
    int A1, A2, N;
    Node node[100000];
    int flag[100000];
    scanf("%d %d %d", &A1, &A2, &N);
    for (int i = 0; i < N; i++)
    {
        int addr;
        scanf("%d", &addr);
        flag[addr] = 0;
        scanf(" %c %d", &node[addr].data, &node[addr].next);
    }
    int next = A1;
    while (next != -1)
    {
        flag[next] = 1;
        next = node[next].next;
    }
    next = A2;
    while (next != -1)
    {
        if (flag[next])
            break;
        next = node[next].next;
    }
    if (next == -1)
        printf("-1\n");
    else
        printf("%05d\n", next);
    return 0;
}
