#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];

void BFS(int startNode,int n,vector<bool> &visited){
    queue<int> q;
    q.push(startNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void BFSforAllComponents(int n){
    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            BFS(i,n,visited);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'minOperations' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts UNWEIGHTED_INTEGER_GRAPH comp as parameter.
 */

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i].
 *
 */