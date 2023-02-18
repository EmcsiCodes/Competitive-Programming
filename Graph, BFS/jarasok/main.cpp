#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> city;
vector<int> adj[1001];

void BFS(int n){
    vector<bool> visited(n+1,false);
    int parentNode[1001];
    queue<int> q;
    for(int i=0; i<city.size(); i++){
        q.push(city[i]);
        visited[city[i]] = true;
        parentNode[city[i]] = city[i];
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                parentNode[i] = parentNode[node];
            }
        }
    }
    map<int,int> res;
    for(int i=1; i<=n; i++){
        res[parentNode[i]] += 1;
    }
    for(auto i:res){
        cout<<i.second<<'\n';
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        city.push_back(x);
    }
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(n);
    return 0;
}
/*
8 3 9
2 3 7
1 2
1 5
5 4
4 2
2 3
2 6
3 6
3 7
7 8
*/
