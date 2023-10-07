#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
**Problem Summary:**
Gigel needs to pay for his purchases in a supermarket where only cash payments are accepted,
and no change is given. He has a stack of N banknotes with specific denominations.
Gigel wants to spend as little money as possible while making the payment,
and he needs to determine the minimum amount S he should pay using a combination of the given banknotes,
such that S is at least the total cost of the purchases C.

- For each test case, you are given the number of banknotes (N) and the total cost of purchases (C).
- You need to find the minimum value S that can be paid using a combination of the given banknotes, and the minimum number K of banknotes used for this.

**Input:**
- The first line of each test case contains two integers: N (number of banknotes) and C (total cost of purchases).
- The next line contains N integers, representing the denominations of the banknotes.

**Output:**
- For each test case, print the minimum value S that can be paid and the minimum number
K of banknotes used, separated by a comma.

**Constraints:**
- 1 ≤ N ≤ 100
- 1 ≤ C ≤ 20000
- 1 ≤ Ri ≤ 500
- The input file contains at most 20 test cases

**Example:**
*Input:*
```
1
6 60
25 21 38 21 31 21
```

*Output:*
```
63,2
```

In this example, Gigel needs to pay 60 units. The optimal way is to use two 31-unit banknotes,
resulting in a total of 62 units. The second optimal option would be to use three 21-unit banknotes,
resulting in a total of 63 units. Hence, Gigel should choose the latter, minimizing the number of banknotes.
*/

#define INF 100000

pair<int,int> minBuyC(vector<int> coins,int target,int maxTarget){
    vector< vector <int> > dp(coins.size()+1,vector<int>(maxTarget+1, INF));
    dp[0][0] = 0;
    for(int i=1; i<=coins.size(); i++){
        for(int j=0; j<=maxTarget; j++){
            if(j < coins[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i-1][j-coins[i-1]] + 1);
        }
    }
    while(target <= maxTarget && dp[coins.size()][target] == INF) target++;
    return {target, dp[coins.size()][target]};
}

int main()
{
    ifstream in("bancnote.in");
    ofstream out("bancnote.out");
    int testNum;
    in>>testNum;
    for(int t=1; t<=testNum; t++){
        int n,c;
        in>>n>>c;
        vector<int> coins;
        int sum = 0;
        for(int i=1; i<=n; i++){
            int x;
            in>>x;
            sum+=x;
            coins.push_back(x);
        }
        pair<int,int> res = minBuyC(coins,c,sum);
        out<<res.first<<','<<res.second<<'\n';
    }
    return 0;
}
/*
### Dynamic Programming Approach

The problem can be effectively solved using dynamic programming, particularly the **Coin Change Problem**
variant. In this case, we're trying to minimize the number of banknotes used to reach a given amount of money.

Let's break down the dynamic programming approach used in the code:

1. **Initialization**:
   - We create a 2D DP array `dp[i][j]`, where `i` represents the number of denominations (coins),
   and `j` represents the amount to be formed.
   - `dp[i][j]` will store the minimum number of coins needed to form amount `j` using the
   first `i` denominations.

2. **Base Case**:
   - `dp[0][0] = 0` since using zero denominations to form zero amount requires zero coins.

3. **Transition**:
   - For each denomination (coin) `coins[i-1]`, we have two options:
     - **Exclude the current coin**: `dp[i][j]` remains the same,
     so we take the value from the previous denomination.
     - **Include the current coin**: We subtract the value of the current coin from the target amount,
     i.e., `j - coins[i-1]`, and add 1 to represent using this coin.
     So, `dp[i][j] = dp[i][j - coins[i-1]] + 1`.

### Code Walkthrough

1. **Input Reading**:
   - The program reads the number of test cases, the number of banknotes (N),
   the total cost of purchases (C), and the denominations of the banknotes.

2. **Dynamic Programming for Coin Change**:
   - The `minBuyC` function uses a dynamic programming approach to calculate the minimum
   value S that can be paid and the minimum number K of banknotes used.
   - It iterates over all possible amounts from `C` to the maximum possible amount that
   can be formed using the given denominations.
   - For each amount, it uses dynamic programming to calculate the minimum number of banknotes
   needed to form that amount.
   - It returns the minimum amount S and the corresponding minimum number K of banknotes.

3. **Output**:
   - For each test case, the program calls `minBuyC` to get the result and prints it in the required format.

### Example Interpretation

For the given example with `C = 60`, the program finds that the optimal way is
to use three 21-unit banknotes, resulting in a total of 63 units
(slightly exceeding the required payment to ensure it's at least the cost of purchases),
with a minimum number of banknotes used (2).

This dynamic programming approach efficiently finds the optimal payment amount and
minimizes the number of banknotes used for each test case.
*/