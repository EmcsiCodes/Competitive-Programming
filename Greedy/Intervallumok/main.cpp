#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vendeg
{
    int kezd;
    int vegez;
    int index;
};

bool comp(const Vendeg &p1, const Vendeg &p2)
{
    return p1.vegez < p2.vegez;
}
bool comp2(const Vendeg &p1, const Vendeg &p2)
{
    return p1.kezd < p2.kezd;
}

int main()
{
    int n;
    cin >> n;
    vector<Vendeg> a(n);
    vector<Vendeg> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].kezd >> a[i].vegez;

        a[i].index = i + 1;

        b[i].kezd = a[i].kezd;
        b[i].vegez = a[i].vegez;
        b[i].index = i + 1;
    }
    sort(a.begin(), a.end(), comp);
    sort(b.begin(), b.end(), comp2);
    vector<int> solve;
    int end;
    for (int i = 0; i < n; i++)
    {
        end = a[i].vegez;
        int maxx = 0;
        int ind;
        for (int j = 0; j < n; j++)
        {
            if (b[j].kezd <= end)
            {
                if(b[j].vegez > maxx)
                {
                    maxx = b[j].vegez;
                    ind = j;
                }
            }
            else
                break;
        }
        solve.push_back(b[ind].index);
        end = b[ind].vegez;
        while (a[i + 1].kezd <= end && i < n - 1)
        {
            i++;
        }
    }
    cout << solve.size() << endl;
    for (int i : solve)
        cout << i << " ";
    return 0;
}
/*
6
1 3
2 4
1 4
3 5
3 6
4 7
*/