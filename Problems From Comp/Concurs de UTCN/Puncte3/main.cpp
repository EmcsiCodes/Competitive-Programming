#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

/*
- **Problem Description**:
  Given N points on a horizontal line, the goal is to draw M segments on this line in such a way
  that each point is contained in at least one segment. Determine the minimum possible length for the maximum segment.

- **Input**:
  - The input file "puncte3.in" contains T, the number of test cases on the first line.
  - Each test case is on a single line, containing the natural numbers N, M, A, B, and C.
  N and M have the meanings from the problem statement. The coordinates of the N points will be generated
  using the following relations (Xi being the coordinate of the i-th point for i = 1..N):

    ```
    X1 = 1, Xi = (Xi-1 * A + B * i) mod C for i = 2..N
    ```

- **Output**:
  - The output file "puncte3.out" will display, on separate lines, the requested result for each of the T tests.

- **Example**:
  - **Input** (puncte3.in):
    ```
    1
    5 2 2 1 9
    ```
  - **Output** (puncte3.out):
    ```
    3
    ```
  - **Explanation**:
    The coordinates of the points are: 1, 4, 2, 8, 3. A possible solution is to use the
    segments [1, 4] and [8, 8]. The length of the maximum segment is 3.

- **Constraints**:
  - T = 5
  - 1 ≤ M < N ≤ 105
  - 1 ≤ A ≤ 1000
  - 1 ≤ B ≤ 1010
  - 1 ≤ C ≤ 1015
*/

ifstream in("puncte3.in");
ofstream out("puncte3.out");

#define LL unsigned long long

int T;
LL N,M;
LL A,B,C;
vector <long long> points;

void GenPoints()
{
    points.resize(N+1);
    points.at(1) = 1;
    for(int i = 2; i <= N; i++)
    {
        points.at(i)=(points.at(i-1)*A + i*B)%C;
    }
    sort ( points.begin()+1, points.end());
    points.erase( unique ( points.begin()+1, points.end() ), points.end() );
}

bool checkLength(LL MidPoint)
{
    LL numSeg = 1;
    LL LastPoint=points.at(1);
    for(LL i = 2; i < points.size(); i++)
    {
        if(MidPoint < points.at(i)-LastPoint)
        {
            LastPoint = points.at(i);
            numSeg++;
        }
    }
    if(numSeg <= M)
    {
        return true;
    }
    return false;
}

void MaxSegmentLength()
{
    LL index1 = 1;
    LL index2 = points.back();
    LL MidPoint = (index1 + index2)/2;
    LL max_length = points.back()-points.at(1);
    LL last_MP=MidPoint;
    while(index1 <= index2)
    {
        if( checkLength(MidPoint) )
        {
            index2 = MidPoint;
            max_length = MidPoint;
        }
        else
        {
            index1 = MidPoint;
        }
        MidPoint = (index1 + index2)/2;
        if(last_MP==MidPoint) index1=index2+1;
        last_MP=MidPoint;

    }
    out<< max_length<<"\n";
}
int main()
{
    in>>T;
    for(int i=1; i<=T; i++)
    {
        in>>N>>M>>A>>B>>C;
        GenPoints();
        if(M==1) out<<points.back()-points.at(1)<<"\n";
        size_t m=M;
        if(m>=points.size()-1) out<<0<<"\n";
        else MaxSegmentLength();
    }
    return 0;
}
/*
Certainly! Let's delve deeper into the approach of the program.

### Problem Overview
The problem requires us to find the minimum possible length for the maximum segment on a horizontal line,
given certain constraints. We have a series of test cases,
and for each case, we generate points using specific equations and aim to draw M segments on this
line such that each point is contained in at least one segment.

### Approach Overview
1. **Generate Points:**
   - We start by generating the points based on the given equations.
   The equations determine the coordinates of the points.
   - These points represent the positions where the car can refuel or where segments could
   potentially start or end.

2. **Binary Search for Maximum Segment Length:**
   - To find the minimum possible length for the maximum segment, we perform a binary search on possible lengths.
   - For each mid-length (midpoint), we check if it's possible to draw M or fewer segments such that
   each point is contained in at least one segment.

3. **Check Function:**
   - We need a function to check if it's possible to draw M or fewer segments given a certain length.
   - To check this, we iterate through the points and see if we can place segments such that no
   two points are further apart than the given length.

4. **Binary Search Details:**
   - Initially, we set a range for possible lengths (between 1 and the maximum possible length, i.e.,
   the range of the points).
   - In each iteration of the binary search, we calculate a midpoint within the range and use the
   check function to determine if this length is feasible.
   - Based on the result, we adjust the range accordingly to converge towards the minimum
   possible length for the maximum segment.

### Detailed Steps

1. **Reading Input:**
   - Read the number of test cases (T).
   - For each test case:
     - Read parameters N, M, A, B, and C.
     - Call `GenPoints` to generate the points based on the given equations.

2. **Generating Points (`GenPoints`):**
   - Generate points using the given equations and store them in a vector.
   - Sort the vector in ascending order.

3. **Check Function (`checkLength`):**
   - Given a midpoint length, iterate through the points and check if it's possible
   to draw M or fewer segments such that each point is contained in at least one segment.
   - Return true if feasible, false otherwise.

4. **Finding Maximum Segment Length (`MaxSegmentLength`):**
   - Use binary search to find the minimum possible length for the maximum segment.
   - Adjust the midpoint and the range based on the result of the check function.
   - Return the maximum segment length.

5. **Writing Output:**
   - Write the requested result for each test case to the output file "puncte3.out".

### Time Complexity Analysis

- Generating points and sorting them takes O(N log N) time.
- The binary search takes O(log R), where R is the range of possible lengths (maximum possible length of a segment).
- Inside the binary search, we have a check function that iterates through the points, taking O(N) time.
- Overall, the time complexity is dominated by the binary search, making it O(T * (N log N + log R * N)),
where T is the number of test cases.
*/