#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> adj[200001];

pair<int,int> BFS(int node,int n){
    vector<int> dis(n+1,0);
    vector<bool> visited(n+1,false);
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                dis[i] = dis[node] + 1;
                q.push(i);
            }
        }
    }
    int maxDisIndex = 0, maxDis = 0;
    for(int i=1; i<=n; i++){
        if(dis[i]>maxDis){
            maxDis = dis[i];
            maxDisIndex = i;
        }
    }
    return {maxDis, maxDisIndex};
}

int main()
{
    int n,m;
    cin>>m>>n;
    int nodeNum = 1;
    int nextNodeNum = 1;
    vector<char> v[1001];

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin>>x;
            if(i==1 && x=='.') nextNodeNum++;
            v[i].push_back(x);
        }
        if(i>=2){
            for(int j=0; j<m; j++){
                if(v[i-1][j] == '.'){
                    if(j<m-1 && v[i-1][j+1]=='.') {
                        adj[nodeNum].push_back(nodeNum+1);
                        adj[nodeNum+1].push_back(nodeNum);
                    }
                    if(v[i][j] == '.'){
                        adj[nodeNum].push_back(nextNodeNum);
                        adj[nextNodeNum].push_back(nodeNum);
                        nextNodeNum++;
                    }
                    nodeNum++;
                } else if(v[i][j]=='.'){
                    if(j<m-1 && v[i][j+1]=='.'){
                        adj[nextNodeNum].push_back(nextNodeNum+1);
                        adj[nextNodeNum+1].push_back(nextNodeNum);
                    }
                    nextNodeNum++;  
                }
            }
        }
    }
    nodeNum = nextNodeNum - 1;
    /*for(int i=1; i<=nodeNum; i++){
        cout<<i<<": ";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    pair<int,int> res = BFS(1,nodeNum);
    cout<<BFS(res.second,nodeNum).first;
    return 0;
}
/*
6 5
..#.#.
#.....
..##.#
.#....
.#.#.#
*/