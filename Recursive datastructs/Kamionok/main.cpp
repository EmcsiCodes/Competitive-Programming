#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];


int main()
{
    int n;
    cin>>n;
    vector<int> degree(n+1,0);
    vector<int> w(n+1,0);
    vector<int> trucks(n+1,0);
    if(n == 1){
        cout<<0;
        return 0;
    }
    for(int i=2; i<=n; i++){
        int x,y;
        cin>>x>>y;
        adj[i].push_back(x);
        w[i] = y;
        degree[x]++;
    }
    int ucap = 0;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0) {
            q.push(i);
            ucap = max(ucap,w[i]);
            trucks[i]++;
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int i = adj[node][0];
        degree[i]--;
        trucks[i] += trucks[node];
        w[i] += w[node];
        if(degree[i] == 0){
            int capAt = w[i]%trucks[i]==0 ? w[i]/trucks[i] : w[i]/trucks[i] + 1;
            ucap = max(ucap,capAt);
            if(adj[i][0]!=1) q.push(i);
        }
    }
    cout<<ucap;
    return 0;
}
/*
8
1 3
1 3
1 4
2 5
3 6
3 6
4 9
*/