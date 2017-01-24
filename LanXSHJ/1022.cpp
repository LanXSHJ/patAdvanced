#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
class book {
public:
    string ID, title, author, publisher, year;
    vector<string> keywords;
    book(string ID, string title, string author, vector<string> keywords, string publisher, string year)
        : ID(ID), title(title), author(author), keywords(keywords), publisher(publisher), year(year) {};
};
vector<book> Books;
int main() {
    int n, m;
    cin >> n;
    getchar();
    char ID[100], title[100], author[100], publisher[100], year[100];
    char keywordLine[500];
    for (int i = 0; i < n; i++) {
        vector<string> keywords;
        cin.getline(ID, 100);
        cin.getline(title, 100);
        cin.getline(author, 100);
        cin.getline(keywordLine, 500);
        cin.getline(publisher, 100);
        cin.getline(year, 100);
        stringstream tss(keywordLine);
        string ts;
        while (!tss.eof()) {
            tss >> ts;
            keywords.push_back(ts);
        }
        book tbook(ID, title, author, keywords, publisher, year);
        Books.push_back(tbook);
    }
    cin >> m;
    vector<string> res;
    for (int i = 0; i < m; i++) {
        res.clear();
        int cmd;
        cin >> cmd;
        getchar();
        getchar();
        cin.getline(keywordLine, 500);
        string condition(keywordLine);
        switch (cmd) {
        case 1: {
            for (int j = 0; j < n; j++) {
                if (Books[j].title == condition) {
                    res.push_back(Books[j].ID);
                }
            }
            break;
        }
        case 2: {
            for (int j = 0; j < n; j++) {
                if (Books[j].author == condition) {
                    res.push_back(Books[j].ID);
                }
            }
            break;
        }
        case 3: {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < Books[j].keywords.size(); k++) {
                    if (Books[j].keywords[k] == condition) {
                        res.push_back(Books[j].ID);
                        break;
                    }
                }
            }
            break;
        }
        case 4: {
            for (int j = 0; j < n; j++) {
                if (Books[j].publisher == condition) {
                    res.push_back(Books[j].ID);
                }
            }
            break;
        }
        case 5: {
            for (int j = 0; j < n; j++) {
                if (Books[j].year == condition) {
                    res.push_back(Books[j].ID);
                }
            }
            break;
        }
        default:
            break;
        }
        sort(res.begin(), res.end());
        cout << cmd << ": " << condition << endl;
        for (int j = 0; j < res.size(); j++) {
            cout << res[j] << endl;
        }
        if (res.size() == 0) {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}