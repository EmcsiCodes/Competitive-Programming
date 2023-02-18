#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    vector< pair<int,int> > v1,v2,sol;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v1.push_back(make_pair(x,y));
    }
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v2.push_back(make_pair(x,y));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        int l = max(v1[i].first,v2[j].first);
        int r = min(v1[i].second,v2[j].second);
        if(l<=r){
            if(sol.size()>0 && sol.back().second==l-1) sol.back().second=r;
            else sol.push_back(make_pair(l,r));
        }
        if(v1[i].second < v2[j].second){
            i++;
        } else j++;
    }
    cout<<sol.size()<<endl;
    for(auto i:sol){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
