#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[300000];


pair<int,int> BFS(int node,int n){

    pair<int,int> furthestNode;
    vector<int> distance(n+1,0);
    vector<bool> visited(n+1,false);

    visited[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
                distance[it] = distance[node] + 1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        //cout<<i<<": "<<distance[i]<<endl;
        if(distance[i] > furthestNode.first){
            furthestNode.first = distance[i];
            furthestNode.second = i;
        }
    }
    return furthestNode;
}

void longestPath(int node,int n){
    pair<int,int> firstCycle = BFS(node,n);
    cout<<firstCycle.first<<" "<<firstCycle.second<<endl;
    pair<int,int> secondCycle = BFS(firstCycle.second,n);
    cout<<secondCycle.first<<endl; //" "<<secondCycle.second;
}

int main()
{
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    longestPath(1,n);
}
/*
7
1
2
2
4
4
6
*/