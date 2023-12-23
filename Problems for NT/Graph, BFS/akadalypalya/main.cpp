#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v[1001][1001];
int dis[1001][1001];

int change(pair<int,int> f,pair<int,int> s){
    if(v[s.first][s.second] == 1 && v[s.first][s.second] == 1) {
        return 1;
    }
    if(v[s.first][s.second] == 1 && v[s.first][s.second] == 2 || v[s.first][s.second] == 2 && v[s.first][s.second] == 2){
        return 2;
    }

}

void dijkstraAlgo(pair<int,int> startNode, pair<int,int> endNode,int n,int m){
    priority_queue< pair<int,pair<int,int> >, vector< pair<int,pair<int,int> > >, greater< pair<int,pair<int,int> > > > pq;
    dis[1][1] = 0;
    pq.push({0,startNode});
    while(!pq.empty()){
        pair<int,int> node = pq.top().second;
        pair<int,int> right = {node.first,node.second+1}, down = {node.first + 1,node.second},
        left = {node.first, node.second - 1}, up = {node.first-1,node.second};
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        pq.pop();
        if(node.second < m && v[right.first][right.second]!=0){
            int p = change(node,right);
            if(dis[right.first][right.second] > dis[node.first][node.second] + p){
                dis[right.first][right.second] = dis[node.first][node.second] + p;
                pq.push({dis[right.first][right.second],right});
            }
        }
        if(node.first < n && v[down.first][down.second]!=0){
            int p = abs(v[node.first][node.second] - v[down.first][down.second]) + 1;
            if(dis[down.first][down.second] > dis[node.first][node.second] + p){
                dis[down.first][down.second] = dis[node.first][node.second] + p;
                pq.push({dis[down.first][down.second],down});
            }
        }
        if(node.second > 1 && v[left.first][left.second]!=0){
            int p = abs(v[node.first][node.second] - v[left.first][left.second]) + 1;
            if(dis[left.first][left.second] > dis[node.first][node.second] + p){
                dis[left.first][left.second] = dis[node.first][node.second] + p;
                pq.push({dis[left.first][left.second],left});
            }
        }
        if(node.first > 1 && v[up.first][up.second]!=0){
            int p = abs(v[node.first][node.second] - v[up.first][up.second]) + 1;
            if(dis[up.first][up.second] > dis[node.first][node.second] + p){
                dis[up.first][up.second] = dis[node.first][node.second] + p;
                pq.push({dis[up.first][up.second],up});
            }
        }
    }
    cout<<dis[endNode.first][endNode.second];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>v[i][j];
            dis[i][j] = 1000001;
        }
    }
    dijkstraAlgo({1,1},{n,m},n,m);
    return 0;
}
/*
6 7
1 1 1 1 2 2 1
0 1 2 2 0 1 1
1 0 0 2 0 1 1
1 1 1 2 0 1 1
1 1 2 0 1 1 1
1 1 2 1 1 1 1
*/