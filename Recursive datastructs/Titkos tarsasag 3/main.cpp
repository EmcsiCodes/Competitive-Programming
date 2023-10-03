#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,a,b;
vector<int> adj[10001];

struct triple{
    int a;
    int b;
    int c;
    int d;
};

vector<int> BFS(int start,vector<int>&parent){
    queue<int> q;
    vector<int> dis(n+1,-1);
    dis[start] = 0;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            dis[i] = dis[node] + 1;
            parent[i] = node;
            if(i!=a && i!=b) q.push(i);
        }
    }
    return dis;
}

int DFS(int node){
    int curr = 1;
    for(auto i:adj[node]){
        curr += DFS(i);
    }
    return curr;
}

int main()
{
    cin>>n>>a>>b;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int> parent(n+1,0);
    vector<int> dis = BFS(1,parent);
    int root1 = a;
    int root2 = b;
    int d = 0;
    triple res;
    while(root1!=root2 && root1!=0 && root2!=0){
        if(dis[root1] > dis[root2]) root1 = parent[root1];
        else root2 = parent[root2];
        d++;
    }
    res.a = 3;
    if(root1 == a) res.a = 1;
    if(root2 == b) res.a = 2;
    res.b = d;
    res.c = DFS(a) - 1;
    res.d = DFS(b) - 1;
    cout<<res.a<<'\n'<<res.b<<'\n'<<res.c<<" "<<res.d;
    return 0;
}
/*
7 2 3
1
1
3
2
3
3
*/