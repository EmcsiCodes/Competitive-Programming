#include <iostream>
#include <vector>

using namespace std;

    int twoEggDrop(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i/2 + i%2] * i/2;
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[n];
    }

int main()
{
    int n;
    cin>>n;
    cout<<twoEggDrop(n);
    return 0;
}