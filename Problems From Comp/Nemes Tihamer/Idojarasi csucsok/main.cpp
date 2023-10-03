#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct pont
{
    int type, index;
};

int main()
{
    int n, hk, mk;
    cin >> n >> mk >> hk;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pont> r;
    r.push_back({0, 0});
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            r.push_back({1, i + 1});
        }
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
        {
            r.push_back({-1, i + 1});
        }
    }
    r.push_back({0, n + 1});

    int k = hk + mk;

    int mcs = 0, hcs = 0;
    int ans = 0;

    for (int i = 1; i < r.size() - 1; i++)
    {
        if (i > k)
        {
            if (r[i - k].type == 1)
                mcs--;
            else
                hcs--;
        }

        if (r[i].type == 1)
            mcs++;
        else
            hcs++;

        if (mcs == mk && hcs == hk)
        {
            int alsoI = i - k + 1;
            int felsoI = i;
            int also = abs(r[alsoI].index - r[alsoI-1].index);
            int felso = abs(r[felsoI].index - r[felsoI+1].index);
            ans += also*felso;
        }
    }

    cout << ans << endl;
    return 0;
}
/*
13 2 1
1 1 2 1 0 0 2 0 1 2 1 0 1
*/
/*
3 7 8 10 12
*/