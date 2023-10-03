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
    vector<in> v;
    for(int i=1; i<=n; i++){
        int a,ko,kp,vo,vp,x,y;
        cin>>a>>ko>>kp>>vo>>vp;
        x = kp + 60 * ko;
        y = vp + 60 * vo;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    vector<int> res;
    int time = 0;
    auto start = v.begin();
    while(start!=v.end()){
        time += start->end - start->start;
        res.push_back(start->i);
        auto it = start;
        while(it!=v.end() && it->start < start->end) it++;
        start = it;
    }
    cout<<res.size()<<" "<<time<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
5
1 18 0 22 0
1 6 0 10 0
3 8 0 10 0
3 14 0 18 0
2 12 0 20 0
*/