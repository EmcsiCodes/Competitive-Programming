#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct nodes{
    int node1;
    int node2;
    int d;
    int i;
};
struct Compare{
    bool operator()(nodes const& p1,nodes const& p2){
        return p1.d > p2.d;
    }
};
priority_queue<nodes,vector<nodes>,Compare> pq;
vector<int> parent(10001,0), s(10001,1);
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
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        pq.push({x,y,z,i});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    int num = 0, minCost = 0;
    set<int> res;
    while(!pq.empty()){
        nodes curr = pq.top();
        pq.pop();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        if(root1!=root2){
            minCost += curr.d;
            num++;
        }
        Unite(curr.node1,curr.node2);
        res.insert(curr.i);
        if(num == n-1){
            while(!pq.empty() && pq.top().d == curr.d){
                res.insert(pq.top().i);
                pq.pop();
            }
            break;
        }
    }
    cout<<minCost<<'\n'<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
7 9
1 2 1
1 3 2
2 5 2
3 4 2
5 4 2
5 7 4
7 4 3
6 7 2
3 6 4
*/