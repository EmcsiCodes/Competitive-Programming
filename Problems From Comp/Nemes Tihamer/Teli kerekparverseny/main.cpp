#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int v[201][201];
int dp[201][201];

struct res{
    int dis;
    int i;
    int j;
};

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>v[i][j];
            dp[i][j] = 0;
        }
    }

    for(int j=2; j<=m; j++){
        if(abs(v[1][j] - v[1][j-1])<=k && dp[1][j] < dp[1][j-1] + 1) dp[1][j] = dp[1][j-1] + 1;
    }
    for(int i=2; i<=n; i++){
        if(abs(v[i][1] - v[i-1][1])<=k && dp[i][1] < dp[i-1][1] + 1) dp[i][1] = dp[i-1][1] + 1;
    }
    res res = {0,0,0};
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            int x = 0,y = 0;
            if(abs(v[i][j] - v[i-1][j])<=k) x = dp[i-1][j] + 1;
            if(abs(v[i][j] - v[i][j-1])<=k) y = dp[i][j-1] + 1;
            dp[i][j] = max(dp[i][j], max(x, y));
            if(dp[i][j]>res.dis){
                res.dis = dp[i][j];
                res.i = i;
                res.j = j;
            }
        }
    }
    cout<<res.dis<<'\n';
    stack<char> path;
    while(res.dis!=0){
        if(res.j-1>=1 && dp[res.i][res.j-1] == res.dis - 1
        && abs(v[res.i][res.j] - v[res.i][res.j-1])<=k){
            res.j--;
            path.push('J');
        } else if(res.i-1>=1) {
            res.i--;
            path.push('L');
        }
        res.dis--;
    }
    cout<<res.i<<" "<<res.j<<'\n';
    while(!path.empty()){
        cout<<path.top();
        path.pop();
    }
    return 0;
}
/*
5 4 1
7 7 9 7
4 5 3 4
6 6 5 2
4 7 8 2
1 2 3 4
*/