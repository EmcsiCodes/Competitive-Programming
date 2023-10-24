#include <iostream>

using namespace std;
/*
**Problem Summary:**

Given a DNA sequence represented by a string composed of characters 'A', 'C', 'G', and 'T', the task is to determine the smallest value of K such that every contiguous subsequence of length K in the DNA sequence contains all four characters 'A', 'C', 'G', and 'T' at least once.

**Input:**

- A single line containing the DNA sequence represented by a string.

**Output:**

- The smallest value of K such that each K-length subsequence contains all four DNA bases ('A', 'C', 'G', 'T').

**Example:**

- **Input:**
  ```
  ACCGTTAA
  ```
  
- **Output:**
  ```
  6
  ```

This means that for the given DNA sequence, the smallest subsequence length (K) required to ensure all four DNA bases appear in every subsequence is 6.
*/
void dns(string s)
{
    int p[250]={0};
    int e=0;
    int v=0;
    int a,c,g,t;
    a=int('A');
    c=int('C');
    g=int('G');
    t=int('T');
    while(v<s.length())
    {
        p[int(s[v])]++;
        if(p[a]!=0 && p[c]!=0 && p[g]!=0 && p[t]!=0 && p[int(s[e])]-1!=0)
        {
            p[int(s[e])]--;
            e++;
        }
        v++;
    }
    while((p[a]==0 or p[c]==0 or p[g]==0 or p[t]==0) && e>=1)
    {
        e--;
        p[int(s[e])]++;
    }
    cout<<v-e;
}

int main()
{
    string s;
    cin>>s;
    dns(s);
    return 0;
}
/*
This program calculates the smallest value of K such that every contiguous subsequence of length K in a given DNA sequence contains all four DNA bases ('A', 'C', 'G', 'T') at least once.

Here's a detailed explanation of the approach:

1. **Input Processing**:
   - The input DNA sequence is read as a string.

2. **Algorithm** (`dns` function):
   - The `dns` function calculates the smallest value of K using a sliding window approach.
   - It uses an array `p` to keep track of the occurrences of each DNA base ('A', 'C', 'G', 'T') in the current subsequence.
   - It maintains two pointers `e` and `v` to represent the start and end of the current subsequence.
   - While traversing the DNA sequence from left to right (`v`), it updates the occurrences of each base and checks if all four bases have occurred at least once in the current subsequence.
   - When all bases are present, it adjusts the window by incrementing the start pointer `e` and removing the contribution of the leftmost character from the subsequence.
   - It continues this process to find the smallest subsequence length `K` where every subsequence contains all four DNA bases.

3. **Output**:
   - Prints the calculated value of `K`, which is the difference between the end pointer `v` and the start pointer `e`.

4. **Main Function**:
   - Calls the `dns` function with the input DNA sequence.

### Example Walkthrough:

Let's take the provided example DNA sequence "ACCGTTAA".

- **Input**:
  ```
  ACCGTTAA
  ```

- **Algorithm Execution** (`dns` function):
  - The function iterates through the DNA sequence using a sliding window approach.
  - It updates the occurrences of each base and checks if all four bases are present in the current subsequence.
  - When it finds a valid subsequence, it updates the minimum subsequence length.

- **Output**:
  ```
  6
  ```

This means that for the given DNA sequence, the smallest subsequence length (K) required to ensure all four DNA bases appear in every subsequence is 6.
*/
