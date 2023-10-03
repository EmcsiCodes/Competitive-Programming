#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define INF 1000000

pair<int,int> ClosestSum(vector<int> nums, int target){
    vector<vector<int>> dp(nums.size()+1, vector<int>(target+1,INF));
    dp[0][0] = 0;
    for(int i = 1; i <= nums.size(); i++){
        for(int j = 0; j <= target; j++){
            if(j>=nums[i-1]) {
                dp[i][j] =  min(dp[i-1][j], dp[i-1][j-nums[i-1]] + 1);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    while(target > 0 && dp[nums.size()][target] == INF) target--;

    return {target, dp[nums.size()][target] == INF ? 0 : dp[nums.size()][target]};
}

int main()
{
    ifstream in("carburanti.in");
    ofstream out("carburanti.out");
    int testCases;
    in>>testCases;
    for(int testNum = 1; testNum <= testCases; testNum++){
        int n,k;
        in>>n>>k;
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            int x;
            in>>x;
            nums.push_back(x);
        }
        pair<int,int> res;
        res = ClosestSum(nums,k);
        out<<res.first<<','<<res.second<<'\n';
    }
    return 0;
}
/*
1
5 10
4 7 12 13 9
*/