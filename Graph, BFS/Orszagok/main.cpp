#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int aggressiveParent[30001];
vector<int> adj[30001];
queue<int> q;
vector< pair<bool,int> > visited;

bool valid(int i,int node,int currLayer){
    if(!visited[i].first) {    
        for(auto j:adj[i]){
            if(visited[j].second!=currLayer && j!=node) return false;
        }
        return true;
    }
    return false;
}

void BFS(int n,int r,int k){
    int layer = 1;
    int last = r;
    while(!q.empty() && layer<=k){
        int node = q.front();
        q.pop();
        //cout<<node<<endl;
        for(auto i:adj[node]){
            //cout<<i<<": visited="<<visited[i].first<<", layer="<<visited[i].second<<" valid="<<valid(i,node,layer)<<endl;
            if(valid(i,node,layer)){
                visited[i].first = true;
                q.push(i);
                aggressiveParent[i] = aggressiveParent[node];
            }
        }
        //cout<<endl;
        if(node == last){
            layer++;
            last = q.back();
        }
    }
    vector<int> res[30001];
    for(int i=1; i<=n; i++){
        if(aggressiveParent[i] != i){
            res[aggressiveParent[i]].push_back(i);
        }
    }
    for(int i=1; i<=r; i++){
        cout<<res[i].size()<<" ";
        for(auto j:res[i]) cout<<j<<" ";
        cout<<'\b'<<'\n';
    }
}

int main()
{
    int n,r,k;
    cin>>n>>r>>k;
    visited.push_back({false,0});
    for(int i=1; i<=n; i++){
        int x;
        visited.push_back({false,1});
        if(i<=r) {
            q.push(i);
            visited[i].first = true;
            visited[i].second = 0;
            aggressiveParent[i] = i;
        }
        while(cin>>x && x!=0){
            adj[i].push_back(x);
        }
    }
    BFS(n,r,k);
    return 0;
}
/*
11 3 2
4 7 0
4 5 8 9 0
10 0
1 2 5 7 8 0
2 4 6 9 10 0
5 10 0
1 4 8 11 0
2 4 7 0
2 5 10 0
3 5 6 9 0
7 0
*/