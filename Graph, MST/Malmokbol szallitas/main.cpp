#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct nodes{
    int node1;
    int node2;
    long long d;
};
struct Compare{
    bool operator()(nodes const& p1,nodes const& p2){
        return p1.d > p2.d;
    }
};
vector<int> s(10001,1), parent(10001,0);
vector<int> adj[10001], startNodes;
vector<bool> visited(10001,false);
priority_queue<nodes,vector<nodes>, Compare> pq;
int find(int a){
    int root = a;
    while(root!=parent[root]) root = parent[root];
    while(a!=root) {
        int next = parent[a];
        parent[a] = root;
        a = next;
    }
    return root;
}

void Union(int a,int b){
    int root1 = find(a);
    int root2 = find(b);
    if(s[root1]<s[root2]){
        parent[root1] = parent[root2];
        s[root2] += s[root1];
    } else {
        parent[root2] = parent[root1];
        s[root1] += s[root2];
    }
}

void BFS(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = node;
            }
        }
    }
    parent[start] = 0;
}

int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        s[x] = 25000;
        startNodes.push_back(x);
    }
    for(int i=1; i<=m; i++){
        int x,y;
        long long z;
        cin>>x>>y>>z;
        pq.push({x,y,z});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    long long minDis = 0;
    while(!pq.empty()){
        nodes curr = pq.top();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        pq.pop();
        if(root1!=root2 && !(s[root1]>=25000 && s[root2]>=25000)){
            Union(curr.node1,curr.node2);
            adj[curr.node1].push_back(curr.node2);
            adj[curr.node2].push_back(curr.node1);
            minDis += curr.d;
        }
    }
    cout<<minDis<<'\n';
    for(auto i:startNodes){
        BFS(i);
    }
    for(int i=1; i<=n; i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}
/*
7 2 9
3 6
1 4 10
1 3 10
2 3 10
3 4 10
3 5 30
4 5 15
5 6 10
5 7 5
6 7 30
*/