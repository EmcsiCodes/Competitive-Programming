#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1000000
int v[101][101];
bool access[101][101] = {false};
int coordx[4] = {-1,0,1,0};
int coordy[4] = {0,1,0,-1};

bool isValid(int x,int y,int n,int m){
    if(x>n || y>m || x<1 || y<1) return false;
    return true;
}

int DijkstraAlgo(pair<int,int> startNode,pair<int,int> endNode,int n,int m,bool c){
    priority_queue< pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > > pq;
    pq.push({0,startNode});
    int dis[101][101] = {INF};
    while(!pq.empty()){
        pair<int,int> node = pq.top().second;
        pq.pop();
        for(int i=1; i<=4; i++){
            int x = node.first + coordx[i];
            int y = node.second + coordy[i];
            if(isValid(x,y,n,m)){                    
                if(v[node.first][node.second] == v[x][y] && dis[x][y] > dis[node.first][node.second]
                   || (c && access[v[node.first][node.second]][v[x][y]])) {
                    dis[x][y] = dis[node.first][node.second];
                    pq.push({dis[x][y],{x,y}});
                }
                else if(dis[x][y] > dis[node.first][node.second] + 1){
                    dis[x][y] = dis[node.first][node.second] + 1;
                    pq.push({dis[x][y],{x,y}});
                }
            }
        }
    }
    if(!c) return dis[endNode.first][endNode.second] + 1;
    else return dis[endNode.first][endNode.second];
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>v[i][j];
        }
    }
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        access[x][y] = true;
        access[y][x] = true;
    }
    pair<int,int> startNode,endNode;
    cin>>startNode.first>>startNode.second>>endNode.first>>endNode.second;
    cout<<DijkstraAlgo(startNode,endNode,n,m,false)<<'\n';
    cout<<DijkstraAlgo(startNode,endNode,n,m,true)<<'\n';
    return 0;
}
/*
5 6 1
1 1 1 1 1 1
1 1 2 2 1 1
1 1 2 3 3 1
1 1 2 3 3 1
1 1 2 3 1 1
1 3
1 2 5 4
*/