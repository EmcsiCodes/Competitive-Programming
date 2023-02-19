#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct nodes{
    int node1;
    int node2;
    int d;
    int i;
};
struct Compare{
    bool operator()(nodes const& p1, nodes const& p2){
        return p1.d > p2.d;
    }
};
vector<nodes> in;
vector<int> parent(20001,0), s(20001,1);
priority_queue<nodes,vector<nodes>,Compare> pq;

int find(int a){
    int root = a;
    while(root!=parent[root]) root = parent[root];
    while(a!=root){
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
        s[root2] += s[root1];
        parent[root1] = root2;
    } else {
        s[root1] += s[root2];
        parent[root2] = root1;
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        in.push_back({x,y,z,i});
        pq.push({x,y,z,i});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        nodes curr = in[x-1];
        Unite(curr.node1,curr.node2);
    }
    int minCost = 0;
    vector<int> res;
    while(!pq.empty()){
        nodes curr = pq.top();
        pq.pop();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        if(root1!=root2){
            Unite(curr.node1,curr.node2);
            minCost += curr.d;
            res.push_back(curr.i);
        }
    }
    cout<<minCost<<'\n'<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
6 9 2
1 2 3
5 6 3
1 4 2
1 6 1
2 3 2
2 5 8
2 6 6
3 4 7
4 5 5
1 2
*/