#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v[1001][1001];
int coordx[4] = {1,0,-1,0};
int coordy[4] = {0,1,0,-1};
bool visited[1001][1001] = {false};
struct nodes{
    int h;
    int x;
    int y;
};
priority_queue< nodes, vector<nodes>, greater<nodes> > pq;

bool valid(int x,int y,int n,int m){
    if(x>n || y>m || x<1 || y<1) return false;
    //if(visited[x][y]) return false;
    return true;
}

void DFS(int x,int y,int n,int m,int &nextfill,int &temp){
    visited[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nx = x + coordx[i];
        int ny = y + coordy[i];
        if(valid(nx,ny,n,m)){
            if(!visited[nx][ny] && v[nx][ny] <= v[x][y]) {
                DFS(nx,ny,n,m,nextfill,temp);
            }
            pq.push({v[nx][ny],nx,ny});
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>v[i][j];
        }
    }
    pair<int,int> startNode;
    cin>>startNode.first>>startNode.second;
    int nextfill = 1000000;
    int temp = 0;
    DFS(startNode.first,startNode.second,n,m,nextfill,temp);
    return 0;
}