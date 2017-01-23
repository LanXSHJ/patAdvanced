#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

bool isprime(int N)
{
    if (N < 2)
        return false;
    else if (N == 2 || N == 3)
        return true;
    else
    {
        for (int i = 2; i <= N / 2; i++)
            if (N % i == 0)
                return false;
        return true;
    }
}

bool reverseprime(int N, int D)
{
    int n = N, M = 0;
    while (n)
    {
        M *= D;
        M += n % D;
        n /= D;
    }
    return isprime(N) && isprime(M);
}

int main(void)
{
    int N, D;
    cin >> N;
    while (N > 0)
    {
        cin >> D;
        if (reverseprime(N, D))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cin >> N;
    }
    return 0;
}
