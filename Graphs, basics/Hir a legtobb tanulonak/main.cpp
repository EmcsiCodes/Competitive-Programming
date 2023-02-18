#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[251];

int BFS(int node,int n){
    int peopleVisited = 0;
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        node = q.front();
        //cout<<node<<" ";
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                peopleVisited++;
            }
        }
    }
    //cout<<endl<<peopleVisited<<endl;
    return peopleVisited;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        while(cin>>x&&x!=0){
            adj[i].push_back(x);
        }
    }
    pair<int,int> res = {0,0};
    for(int i=1; i<=n; i++){
        int c = BFS(i,n);
        if(res.second < c){
            res.first = i;
            res.second = c;
        }
    }
    cout<<res.first;
    return 0;
}
/*
5
3 5 0
3 4 0
0
2 3 0
2 0
*/