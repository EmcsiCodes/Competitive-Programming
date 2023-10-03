#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct in{
    int start;
    int end;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        return p1.start<p2.start;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Compare());
    int i = 0;
    vector<int> res;
    while(i<v.size()){
        int last = v[i].end;
        while(i<v.size() && v[i].start <= last){
            last = min(last, v[i].end);
            i++;
        }
        res.push_back(last);
        while(i<v.size() && v[i].start < last + k) i++;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
6 2
1 4
7 12
2 6
4 9
3 13
8 10
*/