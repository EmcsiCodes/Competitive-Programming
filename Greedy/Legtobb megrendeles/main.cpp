#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct intervals{
    int i;
    int start;
    int end;
};

struct Compare{
    bool operator()(intervals const& p1,intervals const& p2){
        return p1.end < p2.end;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<intervals> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({i,x,y});
    }
    sort(v.begin(),v.end(), Compare());
    auto it = v.begin(), last = v.begin();
    vector<int> res;
    while(it!=v.end()){
        res.push_back(it->i);
        while(it!=v.end() && it->start <= last->end) it++;
        last = it;
     }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
6
2 3
2 4
5 7
3 4
2 2
1 2
*/