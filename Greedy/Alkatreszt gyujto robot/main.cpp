#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> adj[101];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x;
            cin>>x;
            if(x == 1) adj[j].push_back(i);
        }
    }
    vector<int> lis;
    for(int i=1; i<=m; i++){
        for(auto j:adj[i]) lis.push_back(j);
    }
    set<int> s;
    int res = 0;
    s.insert(lis[0]);
    for(int i=1; i<lis.size(); i++){
        auto it = s.lower_bound(lis[i]);
        if(it == s.begin()){
            s.insert(lis[i]);
        } else if(*it != lis[i]){
            it--;
            s.erase(it);
            s.insert(lis[i]);
        }
    }
    cout<<s.size();
    return 0;
}
/*
10 12
0 1 1 1 0 0 1 0 1 0 0 0
0 1 0 0 0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0 1 0 0 0
1 0 0 0 0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0 0 0
1 0 0 0 0 1 1 1 1 0 0 0
1 1 1 1 1 1 0 0 0 1 0 0
1 0 0 0 0 0 0 0 0 1 0 0
1 0 0 0 0 0 0 0 0 1 0 0
*/