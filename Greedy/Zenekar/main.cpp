#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct in{
    int start;
    int end;
    int i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.end < p2.end;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    set<int> freeDays;
    for(int i=1; i<=365; i++) freeDays.insert(i);
    vector< pair<int,int> > res;
    for(int i=0; i<v.size(); i++){
        auto it = freeDays.lower_bound(v[i].start);
        if(*it>v[i].end) continue;
        freeDays.erase(it);
        res.push_back({v[i].i,*it});
        if(freeDays.empty()) break;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i.first<<" "<<i.second<<'\n';
    return 0;
}
/*
6
2 4
1 4 
3 5
1 3
3 5
2 5
*/