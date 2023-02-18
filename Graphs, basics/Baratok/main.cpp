#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> adj[10001];
bool visited[10001] = {false};
set<int> comp[10001];
int comp_num = 0;

void DFS(int node, bool visited[]){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            comp[comp_num].insert(i);
            DFS(i,visited);
        }
    }
}

void components(int n){
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            comp_num++;
            comp[comp_num].insert(i);
            DFS(i,visited);
        }
    }
    cout<<comp_num<<endl;
    for(int i=1; i<=comp_num; i++){
        for(auto j:comp[i]){
            cout<<j<<" ";
        }
        cout<<'\b'<<'\n';
    }
    cout<<'\b';
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    components(n);
    return 0; 
}
/*
9 6
1 3
3 5
4 6
7 9
8 9
1 7
*/