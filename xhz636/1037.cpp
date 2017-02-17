#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
    int NC, NP;
    cin >> NC;
    int Coupon[NC];
    for (int i = 0; i < NC; i++)
        cin >> Coupon[i];
    cin >> NP;
    int Product[NP];
    for (int i = 0; i < NP; i++)
        cin >> Product[i];
    sort(Coupon, Coupon + NC);
    sort(Product, Product + NP);
    int ci, pi;
    ci = 0;
    pi = 0;
    int sum = 0;
    while (ci < NC && pi < NP && Coupon[ci] < 0 && Product[pi] < 0)
    {
        sum += Coupon[ci] * Product[pi];
        ci++;
        pi++;
    }
    ci = NC - 1;
    pi = NP - 1;
    while (ci >= 0 && pi >= 0 && Coupon[ci] > 0 && Product[pi] > 0)
    {
        sum += Coupon[ci] * Product[pi];
        ci--;
        pi--;
    }
    cout << sum << endl;
    return 0;
}
