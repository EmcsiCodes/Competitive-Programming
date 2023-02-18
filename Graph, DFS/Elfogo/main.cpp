#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[2001];

void topSort(int n){
    vector<int> res, inDegree(n+1,0), outDegree(n+1,0);
    queue<int> q;
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            inDegree[j] ++;
            outDegree[i] ++;
        }
    }
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0){
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
    if(res.size()!=n){
        cout<<0;
        return;
    }
    for(int i=res.size()-1; i>=0; i--){
        if(outDegree[res[i]] == 0) cout<<res[i]<<" ";
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
    }
    topSort(n);//nem jo
    //Kosaraju's algorithm
    //megoldas: megtalaljuk az osszes strongly connected comp-ot
    //ha size == 1 akkor csinalunk egy topological sortot a nodera;
    return 0;
}
/*
6
8
1 2
2 3
3 4
4 5
1 6
2 5
6 3
6 4
*/