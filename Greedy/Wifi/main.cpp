#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,h;
    cin>>n>>h;
    vector< pair<int,int> > v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,i-1});
    }
    vector<int> res;
    auto prev = v.begin();
    while(prev!=v.end()){
        pair<int,int> p = {prev->first + h,1000000};
        auto curr = upper_bound(v.begin(),v.end(),p);        
        curr--;
        res.push_back(curr->second);
        p = {curr->first + h,1000000};
        prev = upper_bound(v.begin(),v.end(),p);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i+1<<" ";
    return 0;
}
/*
7 20
0 10 30 40 60 85 100 
*/