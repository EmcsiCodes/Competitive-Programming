#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> adj[20001];

void BFS(int node,int n, vector<int> &path, vector<int> &dis){
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
                path[i] = node;
            }
        }
    }
}

void solve(int n,int a,int b){
    vector<int> path1(n+1,0),path2(n+1,0),dis1(n+1,0),dis2(n+1,0);
    BFS(a,n,path1,dis1);
    BFS(b,n,path2,dis2);
    int endNode = 0;
    int minPath = 100000;
    for(int i=1; i<=n; i++){
        if(dis1[i]!=0 && dis2[i]!=0){
            int p = max(dis1[i],dis2[i]);
            if(p < minPath){
                minPath = p;
                endNode = i;
            }
        }
    }
    if(endNode == 0){
        cout<<-1;
        return;
    }
    cout<<minPath<<" "<<endNode<<'\n';
    stack<int> s;
    s.push(endNode);
    int i = endNode;
    while(dis1[i] > 1){
        s.push(path1[i]);
        i = path1[i];
    }
    s.push(a);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    s.push(endNode);
    i = endNode;
    while(dis2[i] > 1){
        s.push(path2[i]);
        i = path2[i];
    }
    s.push(b);
    cout<<'\b'<<'\n';
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<'\b';
}

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    solve(n,a,b);
    return 0;
}
/*
10 15
1 8
1 2
2 1
1 4
3 2
4 3
2 5
3 6
3 7
4 7
5 10
6 9
7 6
8 7
8 9
9 10
*/
