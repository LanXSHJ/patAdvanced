#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;

typedef struct
{
    char name[12];
    char password[12];
    int modified;
} ACCOUNT;

int main(void)
{
    list<ACCOUNT> M;
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        ACCOUNT temp;
        scanf("%s %s", temp.name, temp.password);
        temp.modified = 0;
        for (int j = 0; j < strlen(temp.password); j++)
        {
            switch (temp.password[j])
            {
                case '1': temp.password[j] = '@';
                          temp.modified = 1;
                          break;
                case '0': temp.password[j] = '%';
                          temp.modified = 1;
                          break;
                case 'l': temp.password[j] = 'L';
                          temp.modified = 1;
                          break;
                case 'O': temp.password[j] = 'o';
                          temp.modified = 1;
                          break;
            }
        }
        M.push_back(temp);
        if (temp.modified)
            count++;
    }
    if (count)
    {
        cout << count << endl;
        list<ACCOUNT>::iterator it;
        for (it = M.begin(); it != M.end(); it++)
        {
            if (it->modified)
            {
                printf("%s %s\n", it->name, it->password);
            }
        }
    }
    else
    {
        if (M.size() == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << M.size() << " accounts and no account is modified" << endl;
    }
    return 0;
}
