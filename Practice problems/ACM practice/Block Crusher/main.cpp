#include <iostream>
#include <vector>

using namespace std;

void fractureLine(vector<vector<int>> &grid){
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    for(int i=0; i<grid[0].size(); i++){
        dp[0][i] = grid[0][i];
    }
    for(int i=1; i<grid.size(); i++){
        dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + grid[i][0];
        for(int j=1; j<dp[0].size() - 1; j++){
            int currMin = min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
            dp[i][j] = currMin + grid[i][j];
        }
        dp[i][dp[0].size() - 1] = min(dp[i-1][dp[0].size() - 1],dp[i-1][dp[0].size() - 2]) + grid[i][dp[0].size() - 1];
    }
    // int start=INT_MAX, starti = 0;
    // for(int i=0; i<grid[0].size(); i++){
    //     if(dp[dp.size() - 1][i] < start){
    //         start = dp[dp.size() - 1][i];
    //         starti = i;
    //     }
    // }

    cout<<endl;
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[0].size(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<int>> grid(h, vector<int>(w));
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            cin>>grid[i][j];
        }
    }
    fractureLine(grid);
}
/*
7 6
5 1 7 1 3 5
9 3 5  5 1 9
7 3 1 3 5 3
3 7 5 9 5 1
5 7 5 1 9 5
5 7 9 5 7 3
3 5 9 7 3 9
*/