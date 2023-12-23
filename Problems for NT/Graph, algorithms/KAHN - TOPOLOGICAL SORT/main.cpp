#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];

void topSort(int n){
    queue<int> q;
    vector<int> res;
    vector<int> inDegree(n+1,0);
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            inDegree[j]++;
        }
    }
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0) {
            res.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
    }
    if(res.size()!=n) cout<<"Cycle detected";
    else for(auto i:res) cout<<i<<" ";
}

int main()
{
    //DAG vagy csak siman DG
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    topSort(n);
    return 0;
}
/*
14 18
10 3
10 11
3 7
11 7
1 4
1 3
1 7
7 8
7 12
4 2
4 5
12 13
8 13
8 5
2 5
13 9
5 6
5 9
*/