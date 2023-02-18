#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v[1001][1001] = {0};

bool isValid(int x,int y,int n,vector<bool> visited[]){
    if(x<1 || y<1 || x>n || y>n) return false;
    if(visited[x][y]) return false;
    if(v[x][y] == 1) return false;
    return true;
}

bool border(int x,int y,int n){
    if(x == n || y == n || x == 1 || y == 1) return true;
    return false;
}

bool BFS(pair<int,int> startNode,int n){
    vector<bool> visited[1001];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) visited[i].push_back(false);
    }
    queue< pair<int,int> > q;
    q.push(startNode);
    visited[startNode.first][startNode.second] = true;
    int coordx[4] = {-1,0,1,0};
    int coordy[4] = {0,1,0,-1};
    
    while(!q.empty()){
        pair<int,int> node = q.front();
        //cout<<node.first<<":"<<node.second<<endl;
        q.pop();
        for(int i=1; i<=4; i++){
            int nodex = node.first + coordx[i];
            int nodey = node.second + coordy[i];
            if(isValid(nodex,nodey,n,visited)){
                //cout<<nodex<<" "<<nodey<<": "<<v[nodex][nodey]<<endl;
                if(border(nodex,nodey,n)){
                    return true;
                } 
                q.push({nodex,nodey});
                visited[nodex][nodey] = true;
            }
        }
        //cout<<endl;
    }
    return false;
}

void solve(vector< pair<int,int> > nodes,int n){
    for(auto i:nodes){
        if(v[i.first][i.second] == 1 || !BFS(i,n)) cout<<"NEM"<<endl;
        else cout<<"IGEN"<<endl;
    }
    cout<<'\b';
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x,y,h,sz;
        cin>>x>>y>>h>>sz;
        if(h>=sz){
            int start = n - y + 1;
            int end = x + h - 1;
            for(int j=x; j<=end; j++){
                v[start][j] = 1;
            }
        } else {
            int end = n - y + 1;
            int start = end - sz + 1;
            for(int j = start; j<=end; j++){
                v[j][x] = 1;
            }
        }
    }
    vector< pair<int,int> > nodes;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        nodes.push_back({n - y + 1,x});
    }
    solve(nodes,n);
    return 0;
}
/*
10 5 3
2 2 1 4
4 2 5 1
3 5 6 1
5 3 1 2
8 3 1 2
4 4
6 3
2 5
*/