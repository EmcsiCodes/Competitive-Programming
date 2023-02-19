#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<int, pair<int,int> > mp;
vector<int> parent(3001,0);
vector<int> s(3001,1);
struct edges{
    int d;
    int node1;
    int node2;
};
struct Compare {
    bool operator()(edges const& p1, edges const& p2)
    {
        return p1.d > p2.d;
    }
};
priority_queue<edges, vector<edges>, Compare> paths;

int find(int a){
    int root = a;
    while(root!=parent[root]){
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
    if(s[root1] < s[root2]){
        s[root2] += s[root1];
        parent[root1] = root2;
    } else {
        s[root1] += s[root2];
        parent[root2] = root1;
    }
}

int main()
{
    int k,n;
    cin>>k>>n;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        mp[i] = {x,y};
        s[i] = 30000;
    }
    for(int i=k+1; i<=k+n; i++){
        int x,y;
        cin>>x>>y;
        mp[i] = {x,y};
    }
    for(auto i:mp){
        for(auto j:mp){
            if(i.first!=j.first){
                int d = abs(j.second.first - i.second.first) + abs(j.second.second - i.second.second);
                edges curr = {d,i.first,j.first};
                paths.push(curr);
            }
        }
    }
    for(int i=1; i<=n+k; i++){
        parent[i] = i;
    }
    int minDis = 0;
    vector< pair<int,int> > res;
    while(!paths.empty()){
        edges curr = paths.top();
        paths.pop();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        if(!(s[root1]>=30000 && s[root2]>=30000) && root1!=root2){
            Union(curr.node1,curr.node2);
            minDis += curr.d;
            res.push_back({curr.node1,curr.node2});
        }
    }
    cout<<minDis<<'\n';
    for(auto i:res) cout<<i.first<<" "<<i.second<<'\n';
    return 0;
}
/*
2 4
100 100
0 100
-100 100
100 0
40 40
150 -50
*/