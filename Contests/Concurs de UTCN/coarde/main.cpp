#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  On a circle, there are 2n distinct points numbered in clockwise order from 1 to 2n (1, 2, 3, ..., 2n-1, 2n).
  The points are connected pairwise by straight line segments, forming chords of the circle.
  Each number is connected to exactly one other number, and it is not allowed for two chords to intersect.

  Write a program to calculate in how many distinct ways the 2n numbers (points) on the circle
  can be connected such that the chords do not intersect.

- **Input**:
  - The input file "coarde.in" contains multiple test cases. Each test case is on a single line,
  containing an integer n for which the number of chords formed by the 2n points on the circle needs to be determined.
  The file ends with a line containing a 0.

- **Output**:
  - The output file "coarde.out" contains one line for each test case.
  It displays the test case number followed by ':' and the number of distinct ways modulo 9999991
  in which the points on the circle can be connected so that the chords do not intersect.

- **Example**:
  - **Input** (coarde.in):
    ```
    2
    3
    0
    ```
  - **Output** (coarde.out):
    ```
    1:2
    2:5
    ```

- **Constraints**:
  - 1 ≤ n ≤ 1000
*/
int main()
{
    ifstream in("coarde.in");
    ofstream out("coarde.out");
    int testNum = 1;
    int n;
    while(in>>n && n!=0){
        vector<long long> v(n+1,0);
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        for(int i=3; i<=n; i++){
            long long curr = 0;
            for(int k=1; k<=i/2; k++){
                curr += (v[i - k] * v[k - 1])%9999991;
            }
            v[i] = ((curr%9999991) * 2)%9999991;
            if(i%2 == 1) v[i] += (v[i/2] * v[i/2])%9999991;
        }
        out<<testNum<<':'<<v[n]%9999991<<'\n';
        testNum++;
    }
    return 0;
}
/*
### Problem Background

We are tasked with finding the number of distinct ways to connect 2n points on a circle with chords,
ensuring that no two chords intersect. This problem is a classic combinatorial problem related to Catalan numbers.

### Catalan Numbers

Catalan numbers are a sequence of natural numbers that occur in various counting problems,
often involving recursively defined structures. The nth Catalan number, denoted as Cn, is given by the formula:

\[ Cn = \frac{1}{n+1} \binom{2n}{n} \]

where \(\binom{2n}{n}\) is the binomial coefficient.

### Approach Explanation

1. **Dynamic Programming (DP) Approach**:
   - We use dynamic programming to calculate the number of ways to connect the points on the
   circle for each value of n.
   - We define a vector `v` where `v[n]` will store the number of ways for n.

2. **Base Cases**:
   - For n = 0, there's only one way (no points to connect), so \(v[0] = 1\).
   - For n = 1, there are two points, and only one way to connect them, so \(v[1] = 1\).
   - For n = 2, there are four points, and the number of ways is given by the second Catalan number, \(v[2] = 2\).

3. **DP Recurrence**:
   - For n > 2, we use a recurrence relation based on Catalan numbers.
   - The recurrence for \(v[n]\) is:
     \[ v[n] = \sum_{k=1}^{n} (v[k-1] \times v[n-k]) \]

4. **Understanding the Recurrence**:
   - For each \(k\), we split the circle into two parts: points \(1\) to \(k\) and points \(k+1\) to \(n\).
   - We consider the number of ways to connect these parts independently: \(v[k-1]\) and \(v[n-k]\).
   - The total number of ways to connect for this \(k\) is the product of these, as there are
   no restrictions on how the parts are connected.
   - We sum this product over all valid \(k\) to get the total number of ways for \(v[n]\).

5. **Modular Arithmetic**:
   - To keep the numbers manageable, we take modulo \(9999991\) as specified in the problem.

### Why this Works

- The recurrence is based on the structure of how points can be connected.
- Catalan numbers naturally appear in the solution due to the structure of non-intersecting chords on a circle.
- The recurrence correctly calculates the number of ways to connect the points without intersections.

This approach elegantly solves the problem by leveraging the properties of Catalan numbers and a
well-defined dynamic programming approach. It ensures that the chords don't intersect while counting
the number of ways to achieve this.
*/