#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[10001];
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    /*for(int i=0; i<=n; i++){
        cout<<i<<": ";
        for(int j=0; j<adj[i].size(); j++) cout<<adj[i][j]<<", ";
        cout<<endl;
    }*/
    int res = 0, index = 0, count = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() > res){
            res = adj[i].size();
            index = i;
        }
        if(adj[i].size() == 1){
            count ++;
        }
    }
    cout<<count<<" "<<index;
    return 0;
}
/*
5 7
0 1
1 4
3 1
3 5
2 0
2 3
1 2
*/