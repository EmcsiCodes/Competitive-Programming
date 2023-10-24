#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
- **Problem Description**:
  In a neighborhood, the streets are laid out in a grid-like pattern, and each street is one-way, either from left to right or from top to bottom. In winter, they want to organize a bicycle race in the city, but on icy road sections, it is dangerous to cycle on very steep roads. Therefore, from one intersection, you can only go to another intersection along one-way streets if the difference in elevation is at most K meters.

- **Task**:
  Write a program that determines the maximum length of the winter bicycle race.

- **Input**:
  - The first line of standard input contains the number of rows and columns of the grid, N and M (1 ≤ N, M ≤ 200), and the value of K (1 ≤ K ≤ 10).
  - The next N lines each contain M integers, representing the elevation of each intersection (0 ≤ Magi,j ≤ 1000).

- **Output**:
  - The program should output the maximum possible length of the bicycle race (the number of road segments between adjacent intersections it contains) on the first line.
  - The second line should contain the row and column indices of a possible starting point.
  - The third line should contain a string consisting of 'J' (move right) and 'L' (move down) characters, representing the route.

- **Example**:
  - **Input**:
    ```
    5 4 1
    7 7 9 7
    4 5 3 4
    6 6 5 2
    4 7 8 2
    1 2 3 4
    ```
  - **Output**:
    ```
    4
    2 1
    JLLJ
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
*/

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
Of course! Let's delve into a more detailed explanation of the program's approach to solving the problem.

### Understanding the Problem:

The problem revolves around organizing a bicycle race in a city, considering icy road sections where steep roads are dangerous to cycle. The goal is to find the maximum length of the bicycle race, given a grid-like pattern of roads, where cyclists can only move between intersections if the difference in elevation is at most `K` meters.

### Approach Overview:

1. **Input Reading:**
   - The program starts by reading the grid's dimensions (`N` rows and `M` columns) and the maximum allowed elevation difference `K`. It also reads the elevation values for each intersection.

2. **Dynamic Programming (DP):**
   - The program utilizes a dynamic programming approach to compute the maximum length of the bicycle race considering the elevation differences and the one-way nature of streets (either left to right or top to bottom).

3. **DP Array Setup:**
   - A 2D DP array `dp` is used to store the maximum length of the bicycle race that can be achieved up to a specific intersection.

4. **DP State Transition:**
   - The transition for computing the maximum length of the race at each intersection is based on the elevation difference and the lengths obtained from neighboring intersections.

5. **Finding the Maximum Length and Starting Point:**
   - After computing the DP array, the program identifies the maximum length of the bicycle race and the starting point (intersection) that achieves this length.

6. **Backtracking for Path:**
   - Starting from the identified starting point with the maximum length, the program backtracks to reconstruct the path that leads to this maximum length.

7. **Output:**
   - Finally, the program prints the maximum possible length of the bicycle race, the starting point, and the path that achieves this maximum length.

### Detailed Explanation:

1. **Dynamic Programming (DP) Approach:**
   - The problem can be effectively solved using a DP approach where we calculate the maximum race length achievable from each intersection.

2. **DP State:**
   - Let's denote `dp[i][j]` as the maximum length of the bicycle race that can be achieved starting from intersection `(i, j)`.

3. **Base Cases:**
   - The base cases are initialized: `dp[1][1] = 1` (starting point), and `dp[i][j] = 0` for other intersections.

4. **State Transition:**
   - For each intersection `(i, j)`, `dp[i][j]` is calculated based on its neighboring intersections where the elevation difference is within the allowed limit.

5. **Finding Maximum Length:**
   - We iterate through all intersections and keep track of the maximum length and its starting point.

6. **Backtracking for Path:**
   - We start from the intersection with the maximum length and backtrack based on the transition rules to reconstruct the path.

7. **Output:**
   - We print the maximum length, the starting point, and the path.

### Conclusion:

The program uses a DP approach to efficiently compute the maximum length of the bicycle race by considering elevation differences and one-way road conditions. It then reconstructs the path that leads to this maximum length and presents the results accordingly.
*/