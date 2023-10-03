#include <iostream>

using namespace std;
#define INF 10000000;
int spath[101][101];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            spath[i][j] = INF;
            if(i==j) spath[i][j] = 0;
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
                if(spath[i][j] > spath[i][k] + spath[k][j]){
                    spath[i][j] = spath[i][k] + spath[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<spath[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}