#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> adj[30001];

vector<int> BFS(int start,int n){
    vector<int> dis(n+1,0);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node =q.front();
        q.pop();
        for(auto i:adj[node]){
            q.push(i);
            dis[i] = dis[node] + 1;
        }
    }
    return dis;
}

int main()
{
    int n;
    cin>>n;
    set< pair<int,int> > sorr[30001];
    vector<int> indexes(n+1,0);
    int j = 1;
    for(int i=1; i<=n; i++){
        int x;
        while(cin>>x&& x!=0){
            adj[i].push_back(x);
            indexes[x] = j;
            j++;
        }
    }
    vector<int> dis = BFS(1,n);
    int maxx = 0;
    for(int i=1; i<=n; i++){
        sorr[dis[i]].insert({indexes[i],i});
        maxx = max(maxx,dis[i]);
    }
    set<int> res;
    for(int i=0; i<=maxx; i++){
        auto first = sorr[i].begin();
        auto last = sorr[i].rbegin();
        res.insert(first->second);
        res.insert(last->second);
    }
    cout<<res.size()<<'\n';
    for(auto i:res)cout<<i<<" ";
    return 0;
}
