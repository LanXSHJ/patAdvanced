#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    int D[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &D[i]);
    int i = 0, j = 0;
    int sum = 0;
    int min = 0x7FFFFFFF;
    do
    {
        sum += D[j];
        if (sum == M)
        {
            min = M;
            printf("%d-%d\n", i + 1, j + 1);
        }
        else if (sum > M)
        {
            while (sum > M)
            {
                if (sum < min)
                    min = sum;
                sum -= D[i++];
            }
            if (sum == M)
            {
                min = M;
                printf("%d-%d\n", i + 1, j + 1);
            }
        }
        j++;
    } while (j < N);
    if (min != M)
    {
        i = j = sum = 0;
        do
        {
            sum += D[j];
            if (sum == min)
                printf("%d-%d\n", i + 1, j + 1);
            else if (sum > min)
            {
                while (sum > min)
                    sum -= D[i++];
                if (sum == min)
                    printf("%d-%d\n", i + 1, j + 1);
            }
            j++;
        } while (j < N);
    }
    return 0;
}
