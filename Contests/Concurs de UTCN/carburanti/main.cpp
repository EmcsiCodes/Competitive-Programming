#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
- **Problem Description**:
  There are n containers filled with fuel in a fuel depot, each having a capacity
  specified by the sequence of integers R_1, R_2, ..., R_n. From here, the fuel is transported
  using tanker wagons. At a given time, in a tanker wagon with a capacity of C, where C is an integer,
  fuel is pumped from multiple containers with capacities R_{c_1}, R_{c_2}, ..., R_{c_k}.
  The fuel from a container R_c is pumped in its entirety into the same tanker wagon.
  The quantity of fuel pumped into a tanker wagon is R_{c_1} + R_{c_2} + ... + R_{c_k} ≤ C.

  Given the capacities of the containers R_1, R_2, ..., R_n and the capacity of the tanker wagon C,
  the task is to determine the maximum quantity of fuel that can be pumped into the tanker
  wagon and the number of containers pumped. If there are two solutions with the same maximum quantity,
  the one with the minimum number of containers is chosen.

- **Input**:
  - The input file "carburanti.in" contains the number of tests T on the first line.
  The following 2*T lines each contain one test. Each test is formed of two lines.
  The first line of each test contains two integers n and C, representing the number of
  containers and the capacity of the tanker wagon. The second line of each test contains
  a sequence of integers separated by spaces, representing the capacities of the containers R_1, R_2, ..., R_n.

- **Output**:
  - The output file "carburanti.out" should contain one line for each test.
  Each line should print the maximum quantity of fuel that can be pumped into the tanker wagon,
  followed by a comma, and the minimum number of containers pumped.

- **Example**:
  - **Input** (carburanti.in):
    ```
    1
    6 60
    23 18 77 18 31 18
    ```
  - **Output** (carburanti.out):
    ```
    59,3
    ```

- **Constraints**:
  - 1 ≤ T ≤ 50
  - 1 ≤ n ≤ 100
  - 1 ≤ C ≤ 20000
  - 1 ≤ R_i ≤ 500
*/

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
**Dynamic Programming Approach:**

The key to solving this problem is to use dynamic programming to find the minimum number
of containers needed to achieve every possible sum from 0 to the tanker wagon capacity `k`.
Once we have this information, we can determine the maximum quantity of fuel that can be pumped
and the minimum number of containers required.

Here's a detailed breakdown of how the dynamic programming approach works:

1. **Initialization:**
   - We create a 2D array `dp`, where `dp[i][j]` represents the minimum number of containers
   needed to achieve a sum of `j` using the first `i` containers.
   - Initialize `dp[0][0]` to 0 because it doesn't require any containers to achieve a sum of 0.

2. **Dynamic Programming Iteration:**
   - We iterate through each container's capacity from `1` to `n` and each possible sum from `0` to `k`.
   - For each combination of container and sum:
     - If the current container's capacity (`nums[i-1]`) is less than or equal to the current sum `j`,
     we have two choices:
       - Include the current container (`nums[i-1]`) in the sum, i.e., `dp[i][j] = dp[i-1][j-nums[i-1]] + 1`.
       - Don't include the current container, i.e., `dp[i][j] = dp[i-1][j]`.
     - We choose the option that minimizes the number of containers required to reach the sum `j`.

3. **Finding the Closest Achievable Sum:**
   - After populating the `dp` array, we iterate from the target capacity `k` downward.
   - We stop when we find the first sum that can be achieved. This sum is the closest achievable
   sum to the tanker wagon capacity.

4. **Determining the Minimum Containers:**
   - The value in `dp[n][target]` represents the minimum number of containers needed to
   achieve the closest achievable sum.
   - This value tells us how many containers need to be pumped into the tanker wagon to reach
   the maximum quantity of fuel.

5. **Output:**
   - The program outputs both the closest achievable sum (maximum quantity of fuel) and the
   minimum number of containers needed to achieve it.

**Why it Works:**

- Dynamic programming guarantees that we consider all possible combinations of containers and sums.
- By minimizing the number of containers required to reach each sum, we ensure that we find the
maximum quantity of fuel that can be pumped while using the minimum number of containers.
- The program works for various test cases and efficiently determines the solution because dynamic
programming eliminates redundant calculations and optimally solves the problem.
*/