#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct guest
{
    int kezd;
    int veg;
    int index;
};

bool comp(guest &p1, guest &p2)
{
    return p1.kezd < p2.kezd;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<guest> a(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].kezd = x;
        a[i].veg = y;
        a[i].index = i + 1;
    }
    vector<int> e(n);
    for (int j = 0; j < n; j++)
    {
        cin >> e[j];
    }
    sort(a.begin(), a.end(), comp);
    vector<int> solve;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        int maxx = -1;
        int ind;
        while (a[i].kezd <= e[j] && i < m)
        {
            if (a[i].veg > maxx)
            {
                maxx = a[i].veg;
                ind = i;
            }
            i++;
        }

        if (maxx == -1)
        {
            cout << 0 << endl;
            return 0;
        }

        solve.push_back(a[ind].index);

        while (maxx >= e[j] && j < n)
        {
            j++;
        }
    }

    if(j<n)
    {
        cout<<0<<endl;
        return 0;
    }

    cout << solve.size() << endl;
    for (int i:solve)
        cout << i << " ";
    return 0;
}
/*
5 4
1 3
2 5
2 8
3 10
4 9
2 5 7 10

1 4
11 12
2 5 7 10

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct in{
    int start,end,i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.start < p2.start;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<in> v;
    vector<int> points;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }

    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        points.push_back(x);
    }
    sort(v.begin(),v.end(),Compare());
    vector<int> res;
    int maxDis = 0;
    int index = 0;
    int curr = points[0];
    int nextPoint;
    for(int i=0; i<v.size(); i++){
        if(v[i].start <= curr && v[i].end > maxDis){
            maxDis = v[i].end;
            index = v[i].i;
        }
        else {
            res.push_back(index);
            auto next = upper_bound(points.begin(),points.end(),maxDis);
            maxDis = 0;
            if(next == points.end()) break;
            curr = *next;
        }
    }
    if(maxDis!=0){
        res.push_back(index);
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i<<" ";
    return 0;
}

5 4
1 3
2 5
2 8
3 10
4 9
2 5 7 10
*/