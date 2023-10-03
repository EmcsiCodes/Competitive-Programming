#include <iostream>

using namespace std;
#define INF 1000000;
int spath[101][101];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            spath[i][j] = 0;
        }
    }
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        spath[x][y] = z;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) continue;
                spath[i][j] = max(spath[i][j], min(spath[i][k], spath[k][j]));
            }
        }
    }
    pair<int,int> res = {0,0};
    for(int i=1; i<=n; i++){
        int curr = INF;
        for(int j=1; j<=n; j++){
            if( i == j ) continue;
            curr = min(spath[i][j],curr);
        }
        if(curr>res.first){
            res.first = curr;
            res.second = i;
        }
    }
    cout<<res.second;
    return 0;
}
/*
5 11
1 3 5
3 1 8
1 2 1
2 1 1
3 2 1
3 5 3
5 3 8
2 5 5
5 2 8
2 4 6
4 2 8
*/