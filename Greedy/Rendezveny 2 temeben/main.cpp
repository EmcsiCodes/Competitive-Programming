#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<bool> visited(1000,false);
    vector<in> v;
    vector<int> res1,res2;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    auto start = v.begin();
    visited[start->i] = true;
    while(start!=v.end()){
        res1.push_back(start->i);
        auto it = start;
        while(it!=v.end() && (it->start <= start->end || visited[it->i])) it++;
        start = it;
        if(it!=v.end()) visited[start->i] = true;
    }
    start = v.begin();
    while(start!=v.end() && visited[start->i]) start++;
    while(start!=v.end()){
        res2.push_back(start->i);
        auto it = start;
        while(it!=v.end() && (it->start <= start->end || visited[it->i])) it++;
        start = it;
        if(it!=v.end()) visited[start->i] = true;
    }
    cout<<res1.size()<<" "<<res2.size()<<endl;
    for(auto i:res1) cout<<i<<" ";
    cout<<'\n';
    for(auto i:res2) cout<<i<<" ";
    return 0;
}
/*
10
3 8
9 20
13 25
2 5
2 4
13 22
22 30
6 10
7 9
10 20
*/