#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
    }
    queue<int> q;
    vector< pair<int,char> > dis(n+1,{0,'a'});
    vector<bool> visited(n+1,false);
    visited[a] = true;
    visited[b] = true;
    q.push(a);
    q.push(b);
    dis[a].second = 'a';
    dis[b].second = 'b';
    bool meet = false;
    pair<int,int> res;
    while(!q.empty() || !meet){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i].first = dis[node].first + 1;
                dis[i].second = dis[node].second;
            } else {
                meet = true;
                if(dis[i].second == 'a') res = {dis[i].first, dis[node].first + 1}; 
                else res = {dis[node].first + 1, dis[i].first};
                break;
            }
        }
    }
    if(!meet) cout<<"NEM";
    else {
        cout<<"IGEN"<<'\n';
        cout<<res.first<<" "<<res.second;
    }
    return 0;
}
/*
6 4 6 5
1 2
3 4
4 5
3 6
*/