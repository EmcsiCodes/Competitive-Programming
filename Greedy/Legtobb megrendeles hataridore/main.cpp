#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > v;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    int currday = 1;
    vector< pair<int,int> > res;
    for(int i=0; i<m; i++){
        if(currday<=v[i].first){
            res.push_back({v[i].second,currday});
            currday++;
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i.first<<" "<<i.second<<'\n';
    return 0;
}
/*
10 6
3
2
7
4
2
1
*/