#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[401], canVisit[401];

void BFS(int node,int n){   ///nem hatekony, meg lehet oldani memoizationnal
    vector<bool> visited(n+1,false);
    visited[node] = true;
    queue<int> q;
    q.push(node);
    int originalNode = node;

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                if(i!=originalNode) canVisit[originalNode].push_back(i);
                q.push(i);
            }
        }
    }
}

/*void DFS(int node, vector<bool> visited){
    visited[node] = true;
    for(auto i:adj[node]){
        canVisit[node].push_back(i);
        if(!visited[i]){
            DFS(i,visited); 
            for(auto j:canVisit[i]) {
                canVisit[node].push_back(j);
            }
        }
    }
    
}feladom!!!!!!!!!!!!!!!*/

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char x;
            cin>>x;
            if(x == 'i' && i!=j){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=1; i<=n; i++){
        BFS(i,n);
    }
    int hirek[401][401]={0};
    int db=0;
    for(int i=1; i<=n; i++){
        if(canVisit[i].size() == n - 1) db++;
        for(auto j:canVisit[i]){
            hirek[i][j]=1;
        }
    }
    int count = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            //cout<<hirek[i][j]<<" ";
            if(hirek[i][j] && hirek[j][i]) {
                //cout<<i<<" "<<j<<endl;
                count++;
            }
        }
        //cout<<endl;
    }
    cout<<count<<endl<<db;
    /*for(int i=1; i<=n; i++){
        cout<<i<<": ";
        for(auto j:adj[i]) cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<i<<": ";
        for(auto j:canVisit[i]) cout<<j<<" ";
        cout<<endl;
    }*/
    return 0;
}
/*
5
i i i i i
n i n n n
i n i n i
n n n i i
n n n i i
*/