#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct in{
    int start,end,i;
    bool visited;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.start < p2.start;
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
        v.push_back({x,y,i,false});
    }
    sort(v.begin(),v.end(), Compare());
    int start = 0;
    vector<int> res;
    int i = 0;
    while(i<v.size() && start<n){
        int maxx = 0;
        int index = 0;
        int p = 0;
        while(i<v.size() && v[i].start <= start + 1){
            if(maxx <= v[i].end){
                maxx = v[i].end;
                index = v[i].i;
                p = i;
            } 
            i++;
        }
        if(maxx == 0) {
            cout<<0;
            return 0;
        }
        start = maxx;
        res.push_back(index);
        v[p].visited = true;
    }
    if(start!=n) {
        cout<<0;
        return 0;
    }
    i = 0;
    start = 0;
    while(i<v.size() && start<n){
        int maxx = 0;
        int index = 0;
        while(i<v.size() && v[i].start <= start + 1){
            if(!v[i].visited && maxx <= v[i].end){
                maxx = v[i].end;
                index = v[i].i;
            } 
            i++;
        }
        if(maxx == 0) {
            cout<<0;
            return 0;
        }
        start = maxx;
        res.push_back(index);
    }
    if(start!=n) {
        cout<<0;
        return 0;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
6 7
2 3
3 4
4 6
3 6
1 4
1 2
3 5
*/