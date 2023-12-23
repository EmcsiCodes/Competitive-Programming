#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1001];
vector<int> childs[1001];
vector<int> parent(1001,0);
vector<int> s(1001,1);

int find(int a){
    int root = a;
    while(root != parent[root]){
        root = parent[root];
    }
    while(a != root){
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
        s[root2] += s[root1]; 
        parent[root1] = root2;
    } else {
        s[root1] += s[root2];
        parent[root2] = root1;
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
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    Union(1,2);
    Union(5,2);
    Union(4,5);
    Union(3,6);
    for(int i=1; i<=n; i++){
        cout<<i<<":"<<find(i)<<endl;
    }
    return 0;
}