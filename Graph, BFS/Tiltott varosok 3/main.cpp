#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001], adjA[1001], adjE[1001];

vector<int> BFS(int start,int n, vector<int> adj[]){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
    }
    return dis;
}

int main()
{
    int n,m,A,E;
    cin>>n>>m>>A>>E;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int tiltottA, tiltottE;
    vector<bool> canA(n+1, true), canE(n+1, true);
    cin>>tiltottA;
    for(int i=1; i<=tiltottA; i++){
        int x;
        cin>>x;
        canA[x] = false;
    }
    cin>>tiltottE;
    for(int i=1; i<=tiltottE; i++){
        int x;
        cin>>x;
        canE[x] = false;
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(canA[i] && canA[j]){
                adjA[i].push_back(j);
            }
            if(canE[i] && canE[j]){
                adjE[i].push_back(j);
            }
        }
    }

    vector<int> disForA = BFS(A,n,adjA);
    vector<int> disForE = BFS(E,n,adjE);
    vector<int> res(n+1);

    for(int i=1; i<=n; i++){

        if(disForA[i] == 0 && i!=A) {
            res[i] = 0;
        }
        else if(disForE[i] == 0 && i!=E) {
            res[i] = 0;
        }
        else res[i] = max(disForA[i],disForE[i]);

    }

    int minDisAll = 2000000;
    int index = 0;

    for(int i=1; i<=n; i++){
        if(res[i] < minDisAll && res[i]!=0){
            minDisAll = res[i];
            index = i;
        }
    }
    if(minDisAll == 2000000) cout<<0;
    else cout<<index;
    /*for(int i=1; i<=n; i++){
        cout<<i<<": ";
        for(auto j:adjA[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<i<<": ";
        for(auto j:adjE[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
/*
5 6 1 4
1 2
1 3
5 3
5 2
2 4
4 5
2 5 2
1 2
*/