#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
/*
**Problem Summary:**

Given a DNA sequence and an integer K, find a subsequence of length K that appears the most times in the DNA sequence. Return the count of occurrences of this subsequence and the position where it first appears.

**Input:**

- Length of the DNA sequence (N) and the desired subsequence length (K).
- The DNA sequence.

**Output:**

- Count of the most frequently occurring K-length subsequence.
- The position where this subsequence first appears.

**Example:**

- **Input:**
  ```
  11 3
  TACACAGTACA
  ```

- **Output:**
  ```
  3 2
  ```

The subsequence "ACA" of length 3 appears three times in the DNA sequence, starting at position 2.

---

If you have any specific questions or need further assistance with the implementation, feel free to ask!
*/
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string curr = s.substr(0,k);
    map<string, pair<int,int> > m;
    m[curr].first++;
    m[curr].second = 1;
    int l = 0;
    int r = k;
    while(r<s.size()){
        curr = curr + s[r];
        curr.erase(0,1);
        m[curr].first++;
        if(m[curr].first == 1) m[curr].second = l+2;
        l++;
        r++;
    }
    int maxNum = 0;
    int maxNumI = 0;
    for(auto i:m){
        if(i.second.first > maxNum){
            maxNum = i.second.first;
            maxNumI = i.second.second;
        }
    }
    cout<<maxNum<<" "<<maxNumI;
    return 0;
}
/*
The provided C++ program aims to find the subsequence of a given length (K) that appears the most times in a given DNA sequence. Let's break down the approach and understand how the program achieves this.

### 1. **Understanding the Problem:**

The goal is to find a subsequence of a given length (K) that appears the most times in the DNA sequence. We need to return the count of occurrences of this subsequence and the position where it first appears.

### 2. **Input:**

- Read the length of the DNA sequence (`n`), the desired subsequence length (`k`), and the DNA sequence.

### 3. **Approach:**

- Initialize a sliding window of length `K` to extract the initial subsequence.
- Use a map to store the subsequence as a key and a pair containing the count of its occurrences and the position of the first occurrence.
- Slide the window through the DNA sequence, updating the subsequence and the map accordingly.
- Find the subsequence with the maximum occurrences and output its count and the position where it first appears.

### 4. **Implementation:**

- Read the input DNA sequence and desired subsequence length (`k`).
- Initialize a map to store subsequences and their occurrences.
- Slide a window of length `k` through the sequence and update the map.
- Find the subsequence with the maximum occurrences and its first position.

### 5. **Output:**

- Print the count of the most frequently occurring subsequence of length `k`.
- Print the position where this subsequence first appears.

### Example Walkthrough:

Let's walk through an example using the provided input and see how the program finds the most frequently occurring subsequence.

### Input:
```
11 3
TACACAGTACA
```

### Output:
```
3 2
```

The subsequence "ACA" of length 3 appears three times in the DNA sequence, starting at position 2.

### Note:

The program efficiently finds the subsequence that appears the most times and provides the required output. If you have any specific questions or need further assistance, feel free to ask!
*/