#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];

void findBridges(int node,int &time,vector<int> &disc,
vector<int> &low, vector<int> &parent,vector<bool> &valid){
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == -1){ //if not visited
            parent[i] = node;
            findBridges(i,time,disc,low,parent,valid);
            //if we found a backedge for the next node, update current node
            low[node] = min(low[node],low[i]);
            //else we found a bridge
            if(low[i]>disc[node]){
                //a bridge masodik pontja false lesz, bejaraskor nem fog atmenni a bridgen
                valid[i] = false;
            }
        } else if(parent[node]!=i){ //if child to parent edge ignore
        //updates node reach time if backedge
            low[node] = min(disc[i],low[node]);
        }
    }
}

void DFS(int node,vector<bool> valid,vector<bool> &visited,vector<int> &res){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i] && valid[i]){
            res.push_back(i);
            DFS(i,valid,visited,res);
        }
    }
}

int main()
{
    int n,m,startNode;
    cin>>n>>m>>startNode;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> res, disc(n+1,-1), low(n+1,-1), parent(n+1,-1);
    vector<bool> valid(n+1,true), visited(n+1,false);
    int time = 0;
    findBridges(startNode,time,disc,low,parent,valid);
    
    res.push_back(startNode);
    DFS(startNode,valid,visited,res);

    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
5 5 1
1 2
1 3
2 3
1 4
4 5
*/
/*
11 12 3
3 2
2 4
4 3
1 3
2 6
6 10
6 11
2 11
5 7
5 8
5 4
7 8
*/