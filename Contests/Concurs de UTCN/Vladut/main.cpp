#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
- **Problem Description**:
  Vladut wants to conquer a rectangular region in the land of elves and orcs.
  He aims to maximize the difference between the number of orcs and the number of elves in the selected region.

  The land is represented by a square grid of size n x n. Each cell in the grid
  contains the number of orcs and elves residing in that zone. Vladut needs to find a rectangular
  region within the land that maximizes the difference between the total number of orcs and the total number of elves.

- **Input**:
  - The input file "vladut.in" contains the number of tests T on the first line.
  Each test starts with a line containing an integer n, the size of the land.
  The following 2*n lines contain the two matrices O and E. The first n lines correspond to the matrix O,
  and the next n lines correspond to the matrix E. Each line contains n integers separated by spaces.

- **Output**:
  - The output file "vladut.out" should contain one line for each test.
  Each line should print the test number (starting from 1), followed by a colon (':'),
  and the maximum difference between the number of orcs and the number of elves that Vladut can obtain.

- **Example**:
  - **Input** (vladut.in):
    ```
    1
    4
    90 88 39 90
    47 118 5 91
    65 65 51 6
    73 27 107 37
    90 90 46 90
    38 116 11 89
    69 64 55 5
    74 19 107 39
    ```
  - **Output** (vladut.out):
    ```
    1:15
    ```

- **Constraints**:
  - 1 ≤ T ≤ 10
  - 1 ≤ n ≤ 100
  - 0 ≤ O[i][j], E[i][j] ≤ 127, ∀ i, j ∈ ℕ, 1 ≤ i, j ≤ n
  - There exists at least one zone where the number of orcs is greater than the number of elves.
*/

int MaxSumSubmatrix(vector<vector<int>>v){
    int maxSum = 0;
    for(int l = 0; l < v.size(); l++){
        vector<int> currArray(v.size(),0);
        for(int r = l; r < v.size(); r++){
            int currSum = -1;
            int nextSum = 0;
            for(int i = 0; i < v.size(); i++){
                currArray[i] += v[r][i];
                nextSum = nextSum + currArray[i] >= 0 ? nextSum + currArray[i] : 0;
                currSum = max(currSum, nextSum);
            }
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

int main()
{
    ifstream in("vladut.in");
    ofstream out("vladut.out");
    int testCases;
    in>>testCases;
    for(int testNum = 1; testNum <= testCases; testNum++){
        int n;
        in>>n;
        vector<vector<int>>v(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                in>>v[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x;
                in>>x;
                v[i][j] -= x;
            }
        }
        out<<testNum<<':'<<MaxSumSubmatrix(v)<<'\n';
    }
    return 0;
}
/*
The provided C++ program aims to solve the problem of finding a rectangular region within a
given land grid that maximizes the difference between the total number of orcs and elves.

**Approach: Maximum Subarray Sum Problem**

The problem is transformed into the Maximum Subarray Sum problem, which is a classic
problem in computer science and algorithms. The Maximum Subarray Sum problem requires
finding the subarray with the largest sum in a given array of integers.

The approach used in the provided code is Kadane's Algorithm, which efficiently finds the maximum subarray sum.

**Explanation of Kadane's Algorithm (Maximum Subarray Sum):**

1. **Initialization:**
   - Initialize two variables, `currSum` and `maxSum`, to the first element of the array.
   - `currSum` keeps track of the current sum, while `maxSum` keeps track of the maximum sum seen so far.

2. **Iterating through the Array:**
   - Iterate through the array from the second element (index 1) onwards.
   - For each element, update `currSum` to be the maximum of the current element or
   the sum of the current element and the previous `currSum`.
   - Update `maxSum` to be the maximum of `currSum` and `maxSum`.

3. **Returning the Maximum Subarray Sum:**
   - The `maxSum` obtained is the maximum subarray sum.

**Adaptation for the Problem:**
- In the given problem, instead of a 1D array, we have a 2D matrix representing the land grid,
with orc and elf populations in each cell.
- The problem is transformed into finding the maximum sum submatrix, considering the difference
between orc and elf populations as the "sum" for each cell.
- The algorithm calculates the maximum submatrix sum, which represents the maximum difference
between orc and elf populations within a rectangular region.

The `MaxSumSubmatrix` function is an adaptation of Kadane's algorithm for a 2D matrix to solve the
problem and find the maximum difference between orc and elf populations in a rectangular region.

The program reads the input, processes each test case, and outputs the test number and the maximum
difference between the number of orcs and elves that Vladut can obtain for each test case.
*/