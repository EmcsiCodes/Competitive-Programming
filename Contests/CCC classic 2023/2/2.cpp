#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;
#define inf 100000000
char a[300][300];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool BFS(int x1,int y1,int x2, int y2, int n,char a[][300]){
    
    bool visited[250][250];
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({x1,y1});
    visited[x1][x2] = true;
    while(!q.empty()){
        pair<int,int> node = q.front();
        cout<<node.first<<" "<<node.second<<endl;
        if(node.first == x2 && node.second == y2)
        {
            return true;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx,ny;
            nx = node.first + dx[i];
            ny = node.second + dy[i];
            if(!visited[nx][ny] && a[nx][ny] == 'L' && nx >=0 && nx<n && ny >=0 && ny<n)
            {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
    return false;
}

int main()
{
    ifstream f("level2_5.in");
    ofstream g("level2_5.out");
    int n;
    f>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f>>a[i][j];
        }
    }
    int x1,y1,x2,y2;
    int count;
    f>>count;
    while(count--)
    {
        f>>y1;
        char p;
        f>>p;
        f>>x1;
        f>>y2;
        f>>p;
        f>>x2;
        bool ans = BFS(x1,y1,x2,y2,n,a);
        if(ans)
        {
            g<<"SAME"<<endl;
        }
        else g<<"DIFFERENT"<<endl;
    }
    return 0;
}
