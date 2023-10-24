#include <iostream>

using namespace std;
/*
- **Problem Description**:
  In a point-collecting competition, players move on a grid-like paper. Each grid cell has a specified point value. The player starts from any column on the left edge and must reach the right edge. In each step, the player can choose to move right (i,j) to (i,j+1), up-right (i-1,j+1) to (i-1,j+1), or down-right (i+1,j+1) to (i+1,j+1). The total points the player collects is the sum of the point values on the visited cells.

- **Task**:
  Write a program that determines the maximum points a player can collect and the row from which they need to start to achieve this.

- **Input**:
  - The first line of standard input contains the number of rows and columns, N and M (1 ≤ N, M ≤ 100).
  - The following N lines contain M point values for each cell (0 ≤ Pi ≤ 1000).

- **Output**:
  - The program should output the maximum achievable points in the first line.
  - In the second line, it should output the row number from which the player should start to achieve this maximum. If there are multiple solutions, output the smallest row number.

- **Example**:
  - **Input**:
    ```
    4 4
    6 1 7 1
    1 6 1 7
    2 2 2 2
    9 1 1 9
    ```
  - **Output**:
    ```
    26
    1
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
int hasonlit(int a,int b,int c)
{
    if(a>=b && a>=c)
    {
        return a;
    }
    if(b>=a && b>=c)
    {
        return b;
    }
    return c;
}

void optimalis_ut(int n,int m,int a[][101],int b[][101])
{
    for(int j=2; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(i==1){
                if(b[i][j-1]<b[i+1][j-1])
                {
                    b[i][j]=b[i+1][j-1]+a[i][j];
                }
                else {
                    b[i][j]=b[i][j-1]+a[i][j];
                }
            }
            if(i==n){
                if(b[i][j-1]<b[i-1][j-1])
                {
                    b[i][j]=b[i-1][j-1]+a[i][j];
                }
                else {
                    b[i][j]=b[i][j-1]+a[i][j];
                }
            }
            if(i!=1 && i!=n)
            {
                b[i][j]=a[i][j]+hasonlit(b[i][j-1],b[i-1][j-1],b[i+1][j-1]);
            }
        }
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int max=-1,index=-1;
    for(int i=1; i<=n; i++)
    {
        if(b[i][m]>max)
        {
            max=b[i][m];
            index=i;
        }
    }
    cout<<max<<endl;
    for(int j=m; j>=2; j--)
    {
        b[index][j]=b[index][j]-a[index][j];
        ///index!=1 vagy index !=n
        if(index==1)
        {
            if(b[index][j]!=b[index][j-1]) index++;
        }
        else
        {
        if(index==n)
        {
            if(b[index][j]!=b[index][j-1]) index--;
        } else
        {
        if(b[index][j]==b[index-1][j-1]){
                index--;
        } else {
            if(b[index][j]!=b[index][j-1])
            {
                index++;
            }
        }
        }
        }
    }
    cout<<index;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[101][101];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    int b[101][101]={0};
    for(int i=1; i<=n; i++)
    {
        b[i][1]=a[i][1];
    }
    optimalis_ut(n,m,a,b);
    return 0;
}
/*
Certainly, let's delve deeper into how the program solves the problem step by step:

1. **Dynamic Programming Initialization**:
   - The program uses a 2D array `b[101][101]` to store intermediate results.
   - Initially, it sets all values in `b` to 0.

2. **Base Case Initialization**:
   - For each row (i) in the grid, it initializes the first column of `b` as `b[i][1] = a[i][1]`, where `a[i][1]` represents the point value in the first column of the grid.

3. **Dynamic Programming Calculation**:
   - The core of the algorithm lies in this part. The program iterates through the grid, column by column, from left to right (from `j = 2` to `m`, where `m` is the number of columns).
   - For each cell `(i, j)` in the grid, it calculates `b[i][j]`, which represents the maximum points achievable when starting from row `i` and reaching column `j`.
   - To calculate `b[i][j]`, it considers three possible movements: right, up-right, and down-right. It checks which movement results in the maximum points:
     - If `i` is the first row, it considers only right and down-right movements.
     - If `i` is the last row, it considers only right and up-right movements.
     - If `i` is neither the first nor the last row, it considers all three movements (right, up-right, and down-right).
   - It updates `b[i][j]` based on the maximum of the three possible movements.

4. **Finding the Maximum Points and Optimal Starting Row**:
   - After calculating `b` for all cells in the grid, the program finds the maximum points among the values in the last column (`b[i][m]` where `i` ranges from 1 to `n`, where `n` is the number of rows).
   - It also identifies the row (starting point) that corresponds to this maximum points value. It stores this row in the variable `index`.

5. **Output**:
   - Finally, the program outputs two lines:
     - The first line contains the maximum achievable points (maximum value in the last column of `b`).
     - The second line contains the optimal starting row (`index`) to achieve the maximum points.

The key insight is that the program uses dynamic programming to compute the maximum points that can be achieved starting from any row and column. By the end of the dynamic programming phase, it identifies the optimal starting row that results in the maximum points.

This algorithm ensures that the program explores all possible paths through the grid, considering the point values and movement rules, to find the optimal solution. It utilizes dynamic programming to avoid redundant calculations and improve efficiency.
*/
