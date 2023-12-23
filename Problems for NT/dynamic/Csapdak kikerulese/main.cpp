#include <iostream>

using namespace std;
int n,m;
int a[1000][1000],t[1000][1000];

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            t[i][j]=0;
            a[i][j]=x;
        }
    }
    t[0][0]=1;
    for(int j=1; j<m; j++){
        if(a[0][j]==1){
            t[0][j]=0;
        } else  t[0][j]+=t[0][j-1];
    }
    for(int i=1; i<n; i++){
        if(a[i][0]==1){
            t[i][0]=0;
        } else  t[i][0]+=t[i-1][0];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(a[i][j]==1){
                t[i][j]=0;
                continue;
            }
            t[i][j] = ( (t[i-1][j]) % 1000000 + (t[i][j-1]) % 1000000 ) % 1000000;
        }
    }
    cout<<t[n-1][m-1];
    return 0;
}
/*
5 6
0 0 0 0 0 0
0 1 0 0 1 0
0 0 1 0 0 0
1 0 1 0 0 0
0 0 0 0 1 0
*/
