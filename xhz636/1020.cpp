#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

struct p
{
    int v;
    struct p* l;
    struct p* r;
};

struct p* maketree(int* po, int pn, int* io, int in)
{
    int lpo[pn], rpo[pn], lio[in], rio[in];
    int lpn = 0, rpn = 0, lin = 0, rin = 0;
    struct p* node;
    if (pn != in)
        cout << "err" << endl;
    if (pn == 0)
        return NULL;
    else
    {
        node = (struct p*)malloc(sizeof(struct p));
        node->v = po[pn - 1];
        int i = 0;
        while (io[i] != po[pn - 1])
            lio[lin++] = io[i++];
        i++;
        while (i < in)
            rio[rin++] = io[i++];
        for (i = 0; i < pn - 1; i++)
        {
            int inleft = 0;
            for (int j = 0; j < lin; j++)
                if (po[i] == lio[j])
                {
                    inleft = 1;
                    break;
                }
            if (inleft)
                lpo[lpn++] = po[i];
            else
                rpo[rpn++] = po[i];
        }
        node->l = maketree(lpo, lpn, lio, lin);
        node->r = maketree(rpo, rpn, rio, rin);
        return node;
    }
}

int main(void)
{
    int N, post[30], in[30];
    struct p* tree;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> post[i];
    for (int i = 0; i < N; i++)
        cin >> in[i];
    tree = maketree(post, N, in, N);
    list<struct p*> level;
    level.push_back(tree);
    while (level.size())
    {
        struct p* node = level.front();
        level.pop_front();
        if (node == tree)
            cout << node->v;
        else
            cout << " " << node->v;
        if (node->l != NULL)
            level.push_back(node->l);
        if (node->r != NULL)
            level.push_back(node->r);
    }
    cout << endl;
    return 0;
}
