#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    string name, gender, ID;
    int grade;
    string lbname, lbID, hgname, hgID;
    int lbgrade = 101, hggrade = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> name >> gender >> ID >> grade;
        if (gender == "M" && grade < lbgrade)
        {
            lbgrade = grade;
            lbname = name;
            lbID = ID;
        }
        else if (gender == "F" && grade > hggrade)
        {
            hggrade = grade;
            hgname = name;
            hgID = ID;
        }
    }
    if (hggrade < 0)
        cout << "Absent" << endl;
    else
        cout << hgname << " " << hgID << endl;
    if (lbgrade > 100)
        cout << "Absent" << endl;
    else
        cout << lbname << " " << lbID << endl;
    if (hggrade >= 0 && lbgrade <= 100)
        cout << hggrade - lbgrade << endl;
    else
        cout << "NA" << endl;
    return 0;
}
