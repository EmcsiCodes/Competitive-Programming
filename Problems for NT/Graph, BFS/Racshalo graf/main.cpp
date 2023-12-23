#include <iostream>

using namespace std;
/*
The problem involves a grid graph where points are arranged in a grid-like pattern, and edges connect neighboring points (up, down, right, left). The task is to determine the minimum number of steps to reach any point from any other point on the grid graph after adding a specified set of new edges.

The input includes the number of rows (N), number of columns (M) forming the grid, and the number of new edges added (K). Each of the following K lines contains the indices of the endpoints of a new edge.

The program should output, for each new edge added, the minimum number of steps required to traverse from any point to any other point after adding that edge.

Example:
Input:
3 4 4
1 6
7 10
2 12
4 9
Output:
5
4
4
3
Explanation:

Before adding any edges, the distance between points 1 and 12, and between points 4 and 9, is 5, which is the maximum distance between any two points. Any other point pair has a smaller distance.
After adding the first edge, the distance between points 4 and 9 decreases to 4.
After adding the second edge, the distance between points 4 and 9 remains 4.
After adding the third edge, the distance between points 4 and 9 remains 4.
After adding the fourth edge, the distance between points 4 and 9 decreases to 3.
Constraints:

1 ≤ N * M ≤ 200 (total number of points in the grid)
1 ≤ K ≤ 100 (number of new edges added)
*/
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int dp[201][201];
    for(int i=1; i<=n*m; i++){
        for(int j=1; j<=n*m; j++){
            int x1 = i%m == 0 ? i/m : i/m+1;
            int x2 = j%m == 0 ? j/m : j/m+1;
            int y1 = i%m == 0 ? m : i%m;
            int y2 = j%m == 0 ? m : j%m;
            dp[i][j] = abs(x1-x2) + abs(y1-y2);
        }
    }
    for(int t = 1; t<=k; t++){
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        int currMax = 0;
        for(int i=1; i<=n*m; i++){
            for(int j=1; j<=n*m; j++){
                dp[i][j] = min(dp[i][j],min(dp[i][x]+dp[y][j]+1,dp[i][y]+dp[x][j]+1));
                currMax = max(currMax,dp[i][j]);
            }
        }
        cout<<currMax<<'\n';
    }
    return 0;
}
/*
This program addresses the problem of determining the minimum number of steps to reach any point from any other point on a grid graph after adding a specified set of new edges.

Approach:
The program starts by reading the input, including the number of rows (N), number of columns (M), and the number of new edges added (K).
It initializes a 2D array dp to store the minimum steps to traverse from any point to any other point.
For each pair of points (i, j), it calculates the Manhattan distance between them on the grid and stores it in the dp array.
Then, for each new edge, it updates the dp array based on the effect of the new edge on the distances between points.
After updating the distances, it finds the maximum distance (maximum number of steps) between any two points and outputs it.
Explanation:
The program utilizes a grid representation and the Manhattan distance concept to determine the minimum steps between any two points in the original grid.
It then iteratively considers the effect of adding each new edge and updates the distances accordingly.
After each update, it calculates the maximum distance between any two points and outputs it.
This program efficiently calculates the minimum steps between any two points on the grid after adding specific edges. It correctly considers the Manhattan distance and updates the distances based on the effect of the new edges, providing the expected output for each edge added.
*/