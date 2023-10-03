#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
int bridge[1001][1001] = {false};

void findBridges(int node,vector<int> &disc, vector<int> &low, vector<int> &parent){
    static int time = 0;
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == -1){ 
            //if not visited
            parent[i] = node;
            findBridges(i,disc,low,parent);
            //if we found a backedge for the next node, update current node
            low[node] = min(low[node],low[i]);
            //else we found a bridge
            if(low[i]>disc[node]){
                //a bridge masodik pontja false lesz, bejaraskor nem fog atmenni a bridgen
                bridge[i][node] = true;
                bridge[node][i] = true;
            }
        //if child to parent edge ignore
        } else if(parent[node]!=i){ 
            //updates node reach time if backedge
            low[node] = min(disc[i],low[node]);
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
    vector<int> disc(n+1,-1), low(n+1,-1), parent(n+1,-1);
    for(int i=1; i<=n; i++){
        if(disc[i] == -1) findBridges(startNode,disc,low,parent);
    }
    cout<<"bridges:";
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(bridge[i][j]) cout<<"("<<i<<","<<j<<") ";
        }
    }
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