#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
- **Problem Description**:
  Given a sequence of n positive integers A_1, A_2, ..., A_n, which is divided into k ≤ n disjoint subsequences L_1, L_2, ..., L_k that concatenated give the initial sequence.

  L_1 = A_1, A_2, ..., A_{i_1 - 1}  
  L_2 = A_{i_1}, A_{i_1+1}, ..., A_{i_2 - 1}  
  ...  
  L_k = A_{i_{k-1}}, A_{i_{k-1}+1}, ..., A_n  

  We consider the sums of the subsequences L_1, L_2, ..., L_k:

  S_1 = A_1 + A_2 + ... + A_{i_1 - 1}  
  S_2 = A_{i_1} + A_{i_1+1} + ... + A_{i_2 - 1}  
  ...  
  S_k = A_{i_{k-1}} + A_{i_{k-1}+1} + ... + A_n  

  Write a program that divides the sequence of n numbers into k subsequences such that the maximum value of a sum S_j (1 ≤ j ≤ k) is minimized (i.e., Result = min max_{j=1..k} S_j among all possible partitions).

- **Input**:
  - The input file "sume3.in" contains multiple test examples. Each example has the first line with two integers n, k separated by a space, determining the number n of integers in the sequence and the number k of subsequences. The next line contains n integers A_i separated by spaces. The file ends with a line containing a 0.

- **Output**:
  - The output file "sume3.out" contains one line for each test example. Each line displays the test example number followed by ':' and the smallest maximum value of a possible subsequence sum obtained by partitioning the given sequence.

- **Example**:
  - **Input** (sume3.in):
    ```
    5 3
    1 2 3 4 5
    3 2
    4 78 9
    0
    ```
  - **Output** (sume3.out):
    ```
    1:6
    2:82
    ```

- **Constraints**:
  - 1 ≤ k ≤ n ≤ 500
  - 1 ≤ A_i ≤ 10^6, for all i in {1, ..., n}
*/

bool valid(int mid,int k,vector<int> v){
    int subSecNum = 1;
    int curr = 0;
    for(int i=0; i<v.size(); i++){
        curr += v[i];
        if(curr > mid){
            curr = v[i];
            subSecNum++;
            if(curr > mid) return false;
        }
    }
    if(subSecNum <= k) return true;
    return false;
}

int main()
{
    ifstream in("sume3.in");
    ofstream out("sume3.out");
    int n;
    int testNum = 1;
    while(in>>n && n!=0){
        int k;
        in>>k;
        vector<int> v;
        int sum = 0;
        for(int i=1; i<=n; i++){
            int x;
            in>>x;
            sum += x;
            v.push_back(x);
        }
        int r = sum;
        int l = 0;
        int res = sum;
        while(l<=r){
            int mid = (l + r) / 2;
            if(valid(mid,k,v)){
                res = min(res, mid);
                r = mid - 1;
            } else l = mid + 1;
        }
        out<<testNum<<":"<<res<<'\n';
        testNum++;
    }
    return 0;
}
/*
This program solves the problem of dividing a sequence of positive integers into k subsequences,
aiming to minimize the maximum sum of these subsequences.

Here's a detailed explanation of the approach and how the program works:

### Approach Explanation:

1. **Binary Search for Answer (Maximum Subsequence Sum)**:
   - The main idea is to use binary search to find the minimum maximum subsequence sum (let's call it 'mid').
   - This 'mid' will be our target value for each subsequence sum.

2. **Validity Check Function (valid)**:
   - The `valid` function checks if it's possible to create 'k' subsequences such that each subsequence
   has a sum less than or equal to 'mid'.
   - It iterates through the sequence, accumulating the sum of elements until it exceeds 'mid',
   at which point it starts a new subsequence.
   - If the number of subsequences created is less than or equal to 'k', it returns true
   (indicating a valid configuration).

3. **Binary Search to Find Minimum Maximum Sum**:
   - Perform binary search on the range [0, sum] where 'sum' is the sum of all elements in the given sequence.
   - In each binary search iteration, we check if the current 'mid' is a valid maximum subsequence sum.
   - If it is valid, we update our result to 'mid' and move towards lower values to potentially find a smaller 'mid'.
   - If it is not valid, we move towards higher values to increase 'mid'.

4. **Output the Result**:
   - Output the minimum maximum subsequence sum found, corresponding to the smallest 'mid'
   that works for dividing the sequence into 'k' subsequences.

### Why this Works:

- The binary search helps in finding the minimum maximum subsequence sum, which is the critical
point to minimize the maximum sum for a valid partition.
- The validity check function ensures that we can divide the sequence into 'k' subsequences,
each with a sum less than or equal to the current 'mid'.

Overall, this program cleverly leverages binary search and a validity check function to
efficiently solve the problem, minimizing the maximum subsequence sum for a valid partition.
*/