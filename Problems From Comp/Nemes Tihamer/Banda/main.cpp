#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> adj[100001];

int main()
{
    int n;
    cin>>n;
    vector<bool> canPick(n+1,true);
    vector<int> degree(n+1,0), parent(n+1,0);
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
        parent[i] = x;
        degree[x]++;
    }
    set<int> res;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            q.push(i);
            res.insert(i);
            canPick[parent[i]] = false;
        }
    }
    while(!q.empty()){
        int next = parent[q.front()];
        degree[next]--;
        q.pop();
        if(degree[next] == 0){
            q.push(next);
            if(canPick[next]){
                res.insert(next);
                canPick[parent[next]] = false;
            }
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}