#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<int> robots[100001];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        robots[y].push_back(x);
    }
    vector<int> v;
    for(int i=1; i<=m; i++){
        for(auto j:robots[i]){
            v.push_back(j);
        }
    }
    set<int> res;
    res.insert(v[0]);
    for(int i=1; i<v.size(); i++){
        auto it = res.lower_bound(v[i]);
        if(it == res.begin()) res.insert(v[i]);
        else if(*it!=v[i]){
            it--;
            res.erase(it);
            res.insert(v[i]);
        }
    }
    cout<<res.size();
    return 0;
}