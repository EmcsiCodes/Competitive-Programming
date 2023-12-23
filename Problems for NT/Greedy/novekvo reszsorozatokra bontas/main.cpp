#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
/*
- **Problem Description**:
  Given a sequence of N numbers, create a program that divides the sequence into a minimal number of non-consecutive, increasing subsequences.

- **Input**:
  - The first line of standard input contains the length of the sequence, N (1 ≤ N ≤ 100,000).
  - The next line contains the individual elements of the sequence, each separated by a space (1 ≤ Ai ≤ 1,000,000).

- **Output**:
  - The program should output the minimal number of increasing subsequences.

- **Example**:
  - **Input**:
    ```
    8
    3 6 2 7 4 8 7 3
    ```
  - **Output**:
    ```
    3
    ```
  - **Explanation**:
    Possible subsequences:
    1. 3, 4, 7
    2. 6, 7, 8
    3. 2, 3

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
int main()
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v[i] = x;
    }
    multiset<int> s;
    for(int i=0; i<v.size(); i++){
        auto it = s.lower_bound(v[i]);
        if(it == s.begin()){
            s.insert(v[i]);
        } else {
            it--;
            s.erase(it);
            s.insert(v[i]);
        }
    }
    cout<<s.size();
    return 0;
}
/*

### Program Explanation:

1. **Understanding the Problem**:
   - The program takes an integer `n` representing the number of elements to be read.
   - It reads a sequence of integers and aims to find the length of the longest increasing subsequence.

2. **Approach**:
   - The program utilizes a dynamic programming approach to solve the Longest Increasing Subsequence (LIS) problem.
   - It maintains a set to keep track of the smallest end element of all increasing subsequences of different lengths.
   - For each element, it finds its position in the set using binary search and replaces the element at that position. If it doesn't exist, it adds the element to the set.
   - Finally, the size of the set after processing all elements represents the length of the longest increasing subsequence.

3. **Algorithm**:
   - Read input value for the number of elements `n`.
   - Create a vector `v` to store the elements.
   - Create a multiset `s` to maintain the smallest end elements of increasing subsequences.
   - Iterate through each element:
     - Perform binary search to find the position of the current element in the set.
     - If the position exists, replace the element at that position with the current element.
     - If the position does not exist, insert the current element into the set.
   - Output the size of the set, which represents the length of the longest increasing subsequence.

4. **Explanation**:
   - The program effectively uses a set to keep track of the smallest end elements of increasing subsequences, allowing it to find the length of the longest increasing subsequence.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(n log n) due to the binary search operations for each element.

This approach efficiently finds the length of the longest increasing subsequence in the given input sequence.
*/