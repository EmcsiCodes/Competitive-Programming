#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair<int,int> > adj[10001];

int main()
{
    int n,start;
    cin>>n>>start;
    vector<int> profits(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        profits[i] = x;
    }
    vector<int> degree(n+1,0);
    vector<bool> canProfit(n+1,true), visited(n+1,false);
    int totalProfit = 0;
    for(int i=1; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
        degree[x]++;
        degree[y]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 1 && i!=start){
            q.push(i);
            visited[i] = true;
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first]){
                degree[i.first]--;        
                if(profits[node] > i.second){
                    profits[i.first] += profits[node] - i.second;
                } else canProfit[node] = false;
                if(degree[i.first] == 1 && i.first!=start) {
                    q.push(i.first);
                    visited[i.first] = true;
                }
            }
        }
    }
    cout<<profits[start]<<'\n';
    for(int i=1; i<=n; i++) visited[i] = false;
    q.push(start);
    vector<int> res;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first] && canProfit[i.first]){
                visited[i.first] = true;
                q.push(i.first);
                res.push_back(i.first);
            }
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
10 2
100 100 50 50 50 100 200 100 50 50
1 2 200
3 4 10
4 5 10
4 2 100
2 6 10
6 7 100
6 8 150
8 9 30
10 8 60
*/