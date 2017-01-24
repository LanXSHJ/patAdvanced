#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
    int M[24], D = 0;
    int N;
    for (int i = 0; i < 24; i++)
    {
        cin >> M[i];
        D += M[i];
    }
    cin >> N;
    vector<string> namevector(N, "");
    list<string> orderlist;
    map<string, int> ordermap;
    map<int, string> namemap;
    int T[N][5];
    int nameindex = 0;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        namevector[i] = str;
        int notin = 1;
        list<string>::iterator it;
        for (it = orderlist.begin(); it != orderlist.end(); it++)
            if (*it == str)
            {
                notin = 0;
                break;
            }
        if (notin)
            orderlist.push_back(str);
        scanf("%d:%d:%d:%d", &T[i][0], &T[i][1], &T[i][2], &T[i][3]);
        cin >> str;
        if (str == "on-line")
            T[i][4] = 0;
        else
            T[i][4] = 1;
    }
    orderlist.sort();
    int index = 0;
    list<string>::iterator it;
    for (it = orderlist.begin(); it != orderlist.end(); it++)
    {
        namemap[index] = *it;
        ordermap[*it] = index;
        index++;
    }
    int L[N];
    for (int i = 0; i < N; i++)
        L[i] = T[i][4] | (T[i][3] << 1) | (T[i][2] << 7) | (T[i][1] << 12) | (T[i][0] << 17) | (ordermap[namevector[i]] << 21);
    sort(L, L + N);
    int next = -1;
    int sum = 0;
    for (int i = 0; i < N - 1; i++)
        if ((L[i] >> 21) == (L[i + 1] >> 21)
                && L[i] % 2 == 0 && L[i + 1] % 2 == 1)
        {
            next = (L[i] >> 21);
            break;
        }
    for (int i = 0; i < N - 1; i++)
    {
        if ((L[i] >> 21) == next)
        {
            if (sum != 0)
                printf("Total amount: $%.2f\n", sum / 100.0);
            sum = 0;
            cout << namemap[L[i] >> 21];
            printf(" %02d\n", (L[i] >> 17) & 0xF);
            next = -1;
            for (int j = i; j < N - 1; j++)
                if ((L[j] >> 21) != (L[i] >> 21)
                        && (L[j] >> 21) == (L[j + 1] >> 21)
                        && L[j] % 2 == 0 && L[j + 1] % 2 == 1
                        && ((L[j] >> 1) & 0xFFFFF) != ((L[j + 1] >> 1) & 0xFFFFF))
                {
                    next = (L[j] >> 21);
                    break;
                }
        }
        if ((L[i] >> 21) == (L[i + 1] >> 21)
                && L[i] % 2 == 0 && L[i + 1] % 2 == 1
                && ((L[i] >> 1) & 0xFFFFF) != ((L[i + 1] >> 1) & 0xFFFFF))
        {
            int begin = (L[i] >> 1) & 0xFFFFF;
            int end = (L[i + 1] >> 1) & 0xFFFFF;
            int bd, bh, bm, ed, eh, em;
            bd = (begin >> 11) & 0x1F;
            bh = (begin >> 6) & 0x1F;
            bm = begin & 0x3F;
            ed = (end >> 11) & 0x1F;
            eh = (end >> 6) & 0x1F;
            em = end & 0x3F;
            printf("%02d:%02d:%02d %02d:%02d:%02d", bd, bh, bm, ed, eh, em);
            int charge = (ed + 1 - bd) * D * 60;
            int minute = (ed + 1 - bd) * 24 * 60;
            for (int j = 0; j < bh; j++)
            {
                charge -= M[j] * 60;
                minute -= 60;
            }
            charge -= M[bh] * bm;
            minute -= bm;
            charge -= M[eh] * (60 - em);
            minute -= 60 - em;
            for (int j = eh + 1; j < 24; j++)
            {
                charge -= M[j] * 60;
                minute -= 60;
            }
            sum += charge;
            printf(" %d $%.2f\n", minute, charge / 100.0);
        }
    }
    printf("Total amount: $%.2f\n", sum / 100.0);
    return 0;
}
