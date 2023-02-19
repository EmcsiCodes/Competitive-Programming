#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> parent(20001,0);
vector<int> s(20001,1);
struct edges{
    int node1;
    int node2;
    int d;
    int i;
};
struct Compare {
    bool operator()(edges const& p1, edges const& p2)
    {
        return p1.d < p2.d;
    }
};
priority_queue<edges, vector<edges>, Compare> pq;

int find(int a){
    int root = a;
    while(parent[root]!=root){
        root = parent[root];
    }
    while(a != root){
        int next = parent[a];
        parent[a] = root;
        a = next;
    }
    return root;
}

void Unite(int a,int b){
    int root1 = find(a);
    int root2 = find(b);
    if(s[root1]<s[root2]){
        parent[root1] = root2;
        s[root2] += s[root1];
    } else {
        parent[root2] = root1;
        s[root1] += s[root2];
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        pq.push({x,y,z,i});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    int minMax = 1000000;
    vector<int> res;
    while(!pq.empty()){
        edges curr = pq.top();
        pq.pop();
        if(find(curr.node1)!=find(curr.node2)){
            Unite(curr.node1,curr.node2);
            minMax = min(minMax,curr.d);
            res.push_back(curr.i);
        }
    }
    cout<<minMax<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
7 9
2 1 2
2 5 6
1 3 3
5 3 4
3 4 4
3 6 8
3 7 2
6 5 1
6 7 5
*/
