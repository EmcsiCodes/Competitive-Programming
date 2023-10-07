#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
**Problem Summary:**

Given a set of DNA sequences, find the most frequently occurring initial subsequence of length K in these sequences.

**Input:**

- Number of DNA sequences (N) and the desired subsequence length (K).
- N DNA sequences.

**Output:**

- Count of the most frequently occurring K-length initial subsequence.
- The most frequently occurring K-length initial subsequence.

**Example:**

- **Input:**
  ```
  8 3
  AGG
  AGGTCGA
  AG
  GAGA
  GAGGCG
  AGGTGC
  GATACT
  ATAGCC
  ```

- **Output:**
  ```
  3
  AGG
  ```

The subsequence "AGG" of length 3 appears three times in the given DNA sequences.

---

*/
int main()
{
    int n,k;
    cin>>n>>k;
    unordered_map<string,int> m;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        if(s.length()>k) s.erase(k);
        m[s]++;
    }
    int maxFreq = 0;
    string maxFreqs;
    for(auto i:m){
        if(i.second > maxFreq){
            maxFreq = i.second;
            maxFreqs = i.first;
        }
    }
    cout<<maxFreq<<'\n'<<maxFreqs;
    return 0;
}
/*
The provided C++ program aims to find the most frequently occurring initial subsequence of a given length (K) in a set of DNA sequences. Let's break down the approach and understand how the program achieves this.

### 1. **Understanding the Problem:**

The goal is to find the most frequently occurring initial subsequence of length K in a set of DNA sequences. We need to return the count of occurrences of this subsequence and the subsequence itself.

### 2. **Input:**

- Read the number of DNA sequences (`N`) and the desired subsequence length (`K`).
- Read the DNA sequences.

### 3. **Approach:**

- Initialize a map to store subsequences and their occurrences.
- For each DNA sequence, extract the initial subsequence of length `K`.
- Update the map with the subsequence and its occurrences.
- Find the subsequence with the maximum occurrences.

### 4. **Implementation:**

- Read the input DNA sequences and desired subsequence length (`K`).
- Initialize a map to store subsequences and their occurrences.
- Extract the initial subsequence of length `K` for each sequence and update the map.
- Find the subsequence with the maximum occurrences.

### 5. **Output:**

- Print the count of the most frequently occurring subsequence of length `K`.
- Print the most frequently occurring subsequence.

### Example Walkthrough:

Let's walk through an example using the provided input and see how the program finds the most frequently occurring subsequence.

### Input:
```
8 3
AGG
AGGTCGA
AG
GAGA
GAGGCG
AGGTGC
GATACT
ATAGCC
```

### Output:
```
3
AGG
```

The subsequence "AGG" of length 3 appears three times in the given DNA sequences.

### Note:

The program efficiently finds the subsequence that appears the most times and provides the required output. If you have any specific questions or need further assistance, feel free to ask!
*/