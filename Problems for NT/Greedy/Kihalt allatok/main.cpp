#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct in{
    int node;
    char c;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        if(p1.node == p2.node) return p1.c < p2.c;
        return p1.node < p2.node;
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
        v.push_back({x,'y'});
        v.push_back({y,'x'});
    }
    sort(v.begin(),v.end(), Compare());
    int maxLive = 0, index = 0;
    int count = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].c == 'x') count++;
        else {
            if(count == maxLive) index = max(index,v[i].node);
            count--;
        }
        maxLive = max(maxLive,count);
    }
    cout<<maxLive<<'\n'<<index;
    return 0;
}
/*
10 5
8 3
2 1
9 6
10 10
7 5
*/