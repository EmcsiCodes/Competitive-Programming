#include <iostream>
#include <vector>

using namespace std;

    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 0;
        int n = coins.size()+1;
        int m = amount+1;
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0; i<m; i++) dp[0][i] = 0;
        for(int i=0; i<n; i++) dp[i][0] = 1;
        for(int i=0; i<dp.size(); i++){
            for(int j=0; j<dp[0].size(); j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(j-coins[i-1]<0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }
        }
        cout<<endl;
                for(int i=0; i<dp.size(); i++){
            for(int j=0; j<dp[0].size(); j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n-1][m-1];
    }

int main()
{
    int amount,m;
    cin>>amount>>m;
    vector<int> coins;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        coins.push_back(x);
    }
    cout<<change(amount,coins);
    return 0;
}