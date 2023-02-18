#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];

void BFS(int n,queue<int> q){
    int layer = 1;
    int lastNode = q.back();
    vector<int> res;
    res.push_back(q.size());
    while(layer!=200000 || !q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            q.push(i);
        }
        if(lastNode != q.back()){
            lastNode = q.back();
            res.push_back(q.size());
            layer++;
            if(q.size() == n) break;
        }
    }
    int maxPletyka = 0;
    int maxPletykaIndex = 0;
    for(int i=0; i<res.size(); i++){
        if(res[i] > maxPletyka){
            maxPletyka = res[i];
            maxPletykaIndex = i;
        }
    }
    cout<<maxPletyka<<'\n'<<maxPletykaIndex + 1<<'\n';
    for(int i=0; i<=maxPletykaIndex; i++){
        cout<<res[i]<<" ";
    }
    cout<<'\b';
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    queue<int> q;
    for(int i=1; i<=k; i++) {
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(n,q);
    return 0;
}