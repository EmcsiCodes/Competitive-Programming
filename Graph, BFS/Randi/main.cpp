#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> adj[20001];

vector<int> BFS(int node,int endNode,int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,1);
    vector<int> pathIndex(n+1,0);
    queue<int> q;
    int index = 0;
    q.push(node);

    while(!q.empty() && index!=endNode){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
                pathIndex[i] = node;
                if(i == endNode) {
                    index = i;
                }
            }
        }
    }
    stack<int> path;
    vector<int> res;
    if(index == endNode){
        path.push(endNode);
        int i = dis[index];
        while(i>1){
            path.push(pathIndex[index]);
            index = pathIndex[index];
            i--;
        }
        while(!path.empty()){
            res.push_back(path.top());
            path.pop();
        }
    }
    return res;
}

int main()
{
    int n,E,A,t,m;
    cin>>n>>E>>A>>t>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> res1,res2;
    res1 = BFS(E,t,n);
    res2 = BFS(A,t,n);
    if(res1.empty() || res2.empty()) cout<<0<<" "<<0;
    else {
        cout<<res1.size()<<" "<<res2.size()<<'\n';
        for(auto i:res1) cout<<i<<" ";
        cout<<'\b'<<'\n';
        for(auto i:res2) cout<<i<<" ";
        cout<<'\b';
    }
    return 0;
}
/*
10 2 3 7 12
2 1
1 6
7 6
6 8
8 7
7 9
9 4
5 7
10 5
3 5
3 4
4 5
*/
