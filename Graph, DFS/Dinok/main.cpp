#include <iostream>
#include <vector>

using namespace std;

vector< pair<int,int> > adj[10001];



int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int z,x,y;
        cin>>z>>x>>y;
        adj[x].push_back({y,z});
        if(z == 1){
            adj[y].push_back({x,z});
        }
    }
    return 0;
}