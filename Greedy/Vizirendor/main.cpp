#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,dspeed,uspeed,k;
    cin>>n>>dspeed>>uspeed>>k;
    vector< pair<int,int> > v;
    v.push_back({0,0});
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,i-1});
    }
    dspeed *= k;
    uspeed *= k;
    auto prev = v.begin();
    vector<int> res;
    while(prev!=v.end()){
        pair<int,int> p = {v[prev->second].first + uspeed, 1000000};
        auto curr = upper_bound(v.begin(),v.end(),p);
        curr--;
        res.push_back(curr->second);
        p = {v[curr->second].first + dspeed,1000000};
        auto next = upper_bound(v.begin(),v.end(),p);
        prev = next;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i+1<<" ";
    return 0;
}
/*
7 20 10 1
10
20
30
60
90
100
*/