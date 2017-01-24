#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

typedef struct
{
    int ID;
    char title[81];
    char author[81];
    list<string> keywords;
    char publisher[81];
    int year;
} BOOK;

bool cmp(BOOK a, BOOK b)
{
    return a.ID < b.ID;
}

int main(void)
{
    int N;
    cin >> N;
    BOOK book[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &book[i].ID);
        getchar();
        gets(book[i].title);
        gets(book[i].author);
        char c;
        do {
            char key[11];
            scanf("%s", key);
            book[i].keywords.push_back(string(key));
            c = getchar();
        } while (c != '\n');
        gets(book[i].publisher);
        scanf("%d", &book[i].year);
    }
    sort(book, book + N, cmp);
    int M;
    cin >> M;
    getchar();
    for (int i = 0; i < M; i++)
    {
        char line[100];
        gets(line);
        puts(line);
        int count = 0;
        if (line[0] == '1')
        {
            for (int j = 0; j < N; j++)
            {
                if (strcmp(book[j].title, line + 3) == 0)
                {
                    printf("%07d\n", book[j].ID);
                    count++;
                }
            }
        }
        else if (line[0] == '2')
        {
            for (int j = 0; j < N; j++)
            {
                if (strcmp(book[j].author, line + 3) == 0)
                {
                    printf("%07d\n", book[j].ID);
                    count++;
                }
            }
        }
        else if (line[0] == '3')
        {
            for (int j = 0; j < N; j++)
            {
                string word(line + 3);
                list<string>::iterator it;
                for (it = book[j].keywords.begin();
                        it != book[j].keywords.end();
                        it++)
                {
                    if (*it == word)
                    {
                        printf("%07d\n", book[j].ID);
                        count++;
                    }
                }
            }
        }
        else if (line[0] == '4')
        {
            for (int j = 0; j < N; j++)
            {
                if (strcmp(book[j].publisher, line + 3) == 0)
                {
                    printf("%07d\n", book[j].ID);
                    count++;
                }
            }
        }
        else if (line[0] == '5')
        {
            for (int j = 0; j < N; j++)
            {
                int year;
                sscanf(line + 3, "%d", &year);
                if (book[j].year == year)
                {
                    printf("%07d\n", book[j].ID);
                    count++;
                }
            }
        }
        if (!count)
            printf("Not Found\n");
    }
    return 0;
}
