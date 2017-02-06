#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct
{
    double P;
    double D;
} S;

bool cmp(S a, S b)
{
    return a.D < b.D;
}

int main(void)
{
    double Cmax, D, Davg;
    int N;
    cin >> Cmax >> D >> Davg >> N;
    double Dmax = Cmax * Davg;
    S station[N];
    for (int i = 0; i < N; i++)
        cin >> station[i].P >> station[i].D;
    sort(station, station + N, cmp);
    double C = 0;
    double X = 0;
    double cost = 0;
    int index = 0;
    if (station[index].D == 0)
    {
        while (X < D)
        {
            int next = -1;
            if (index < N - 1)
            {
                if (station[index + 1].D <= X + Dmax)
                    next = index + 1;
                for (int i = index + 2; i < N && station[i].D <= X + Dmax; i++)
                {
                    if (station[next].P < station[index].P)
                        break;
                    if (station[i].P < station[next].P)
                    {
                        next = i;
                    }
                }
            }
            if (next != -1)
            {
                if (station[index].P < station[next].P)
                {
                    if (X + Dmax < D)
                    {
                        double Cfill = Cmax - C;
                        cost += Cfill * station[index].P;
                        C = Cmax - (station[next].D - X) / Davg;
                        X = station[next].D;
                        index = next;
                    }
                    else
                    {
                        double Cfill = (D - X) / Davg - C;
                        cost += Cfill * station[index].P;
                        C = 0;
                        X = D;
                    }
                }
                else
                {
                    double Cfill = (station[next].D - X) / Davg - C;
                    cost += Cfill * station[index].P;
                    C = 0;
                    X = station[next].D;
                    index = next;
                }
            }
            else
            {
                if (X + Dmax < D)
                {
                    double Cfill = Cmax - C;
                    cost += Cfill * station[index].P;
                    C = 0;
                    X += Dmax;
                    break;
                }
                else
                {
                    double Cfill = (D - X) / Davg - C;
                    cost += Cfill * station[index].P;
                    C = 0;
                    X = D;
                }
            }
        }
    }
    if (X < D)
        printf("The maximum travel distance = %.2f\n", X);
    else
        printf("%.2f\n", cost);
    return 0;
}
