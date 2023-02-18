#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<char> v[1001];
vector<bool> visited[1001];

void BFS(pair<int,int> node,int n,int m){
    queue< pair<int,int> > q;
    visited[node.first][node.second] = true;
    q.push(node);
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node.first >= 2 && v[node.first-1][node.second] == 'Z' && !visited[node.first-1][node.second]){
            visited[node.first - 1][node.second] = true;
            q.push({node.first-1, node.second});
        }
        if(node.first >= 2 && node.second>0 && v[node.first-1][node.second-1] == 'Z' && !visited[node.first-1][node.second - 1]){
            visited[node.first - 1][node.second - 1] = true;
            q.push({node.first - 1, node.second - 1});
        }
        if(node.first >= 2 && node.second<m-1 && v[node.first-1][node.second + 1] == 'Z' && !visited[node.first-1][node.second+ 1]){
            visited[node.first - 1][node.second + 1] = true;
            q.push({node.first - 1, node.second + 1});
        }
        if(node.second>0 && v[node.first][node.second-1] == 'Z' && !visited[node.first][node.second-1]){
            visited[node.first][node.second - 1] = true;
            q.push({node.first, node.second - 1});
        }
        if(node.second<m-1 && v[node.first][node.second+1] == 'Z' && !visited[node.first][node.second+1]){
            visited[node.first][node.second+1] = true;
            q.push({node.first, node.second+1});
        }
        if(node.first<n && node.second>0 && v[node.first + 1][node.second - 1] == 'Z' && !visited[node.first + 1][node.second-1]){
            visited[node.first + 1][node.second - 1] = true;
            q.push({node.first + 1, node.second - 1});
        }
        if(node.first<n && node.second<m-1 && v[node.first + 1][node.second+1] == 'Z' && !visited[node.first + 1][node.second+1]){
            visited[node.first + 1][node.second+1] = true;
            q.push({node.first + 1, node.second+1});
        }
        if(node.first<n && v[node.first + 1][node.second] == 'Z' && !visited[node.first + 1][node.second]){
            visited[node.first + 1][node.second] = true;
            q.push({node.first + 1, node.second});
        }
    }
}

void solve(int n,int m){
    int comp = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && v[i][j] == 'Z'){
                comp++;
                BFS({i,j},n,m);
            }
        }
    }
    cout<<comp;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin>>x;
            v[i].push_back(x);
            visited[i].push_back(false);
        }
    }
    solve(n,m);
    return 0;
}
/*
5 6
KKKKKK
KZKKKK
ZZKZZK
ZKKZZK
KKKKKK
*/