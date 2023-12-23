#include <iostream>
#include <vector>

using namespace std;

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,INT_MIN);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            cout<<i<<" "<<dp[i]<<" es:";
            int currMax = INT_MIN;
            for(int j=i; j>=i-k+1 && j>=1; j--){
                currMax = max(currMax,arr[j-1]);
                dp[i] = max(dp[i],currMax*(i-j+1) + dp[j-1]);
            }
            cout<<"->"<<dp[i]<<endl;
        }
        return dp[n];
    }

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    cout<<maxSumAfterPartitioning(arr,k);
    return 0;
}