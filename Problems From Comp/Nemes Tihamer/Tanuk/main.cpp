#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    //ifstream in("p.in");
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    vector<int> t;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        t.push_back(x);
    }
    sort(v.begin(),v.end());
    int i = 0;
    int j = 0;
    int tNum = 0;
    vector<int> res;
    while(j<m && i<n){
        int maxx = 0;
        int index = 0;
        while(i<n && v[i].first<=t[j]){
            if(maxx <= v[i].second){
                maxx = v[i].second;
                index = i;
            }
            i++;
        }
        if(maxx != 0){
            res.push_back(index + 1);
            while(j<m && t[j]<=maxx) {
                j++;
                tNum++;
            }
        } else j++;
    }
    cout<<tNum<<'\n'<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}