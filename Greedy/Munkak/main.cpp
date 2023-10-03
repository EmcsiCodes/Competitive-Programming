#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct in{
    int start;
    int end;
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
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Compare());
    int time = 0;
    int res = 0;
    for(int i=0; i<v.size(); i++){
        time += v[i].start;
        if(time > v[i].end){
            res = max(res, time - v[i].end);
        }
    }
    cout<<res;
    return 0;
}
/*
3
3 8
7 7
1 10
*/