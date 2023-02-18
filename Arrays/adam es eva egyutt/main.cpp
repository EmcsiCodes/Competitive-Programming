#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int p,n,m;
    cin>>p>>n;
    vector< pair<int,char> > v;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,'x'});
        v.push_back({y,'y'});
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,'x'});
        v.push_back({y,'y'});
    }
    sort(v.begin(),v.end());
    int count = 0;
    vector< pair<int,int> > res;
    for(int i=0; i<v.size()-1; i++){
        if(v[i].second == 'x') count ++ ;
        else count --;
        if(count == 2 && v[i].first!=v[i+1].first) res.push_back({v[i].first, v[i+1].first});
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i.first<<" "<<i.second<<endl;
    return 0;
}