#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> time;
    vector< pair<int,int> > v;
    time.push_back(0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        time.push_back(x);
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.rbegin(),v.rend());
    int maxTime = 0, prev = 0;
    vector<int> res;
    for(int i=0; i<v.size(); i++){
        maxTime = max(maxTime,prev + v[i].first + time[v[i].second]);
        prev += time[v[i].second];
        res.push_back(v[i].second);
    }
    cout<<maxTime<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
3
1 3 3
4 1 5
*/