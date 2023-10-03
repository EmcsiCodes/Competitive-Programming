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
    bool operator()(in const& p1, in const& p2){
        return p1.end<p2.end;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<in> v;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    set<int> s;
    for(int i=1; i<=n; i++){
        s.insert(i);
    }
    vector< pair<int,int> > res;
    for(int i=0; i<v.size(); i++){
        auto it = s.lower_bound(v[i].start);
        if(it==s.end() || *it>v[i].end) continue;
        res.push_back({v[i].i,*it});
        s.erase(it);
        if(s.empty()) break;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i.first<<" " <<i.second<<'\n';
    return 0;
}
/*
10 7
2 3
2 5
3 3
1 2
6 7
2 2
6 10
*/