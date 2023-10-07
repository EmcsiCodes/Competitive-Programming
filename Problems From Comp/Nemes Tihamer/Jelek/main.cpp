#include <iostream>
#include <set>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  In the vastness of space, various radio signal sequences can be detected. These sequences are represented by a series of integers. Researchers searching for extraterrestrial messages look for repeating segments in these sequences, as this may indicate artificial origin. The repeating segments can overlap.

- **Task**:
  Write a program that determines the longest repeating continuous segment in a given signal sequence.

- **Input**:
  - The first line of standard input contains the length of the signal sequence, N (1 ≤ N ≤ 4000).
  - The next line contains N integers, each representing a signal value (1 ≤ Pi ≤ 1000).

- **Output**:
  - The program should output the longest repeating continuous segment of the signal sequence. If there are multiple solutions, output the earliest one. If there is no repeating continuous segment, output -1.

- **Example**:
  - **Input**:
    ```
    10
    2 8 3 1 7 6 8 3 1 7
    ```
  - **Output**:
    ```
    8 3 1 7
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
  - Scoring:
    - 40% of the points can be obtained for tests where N ≤ 700.
    - Additional 40% of the points can be obtained for tests where N ≤ 1500.
*/
int main()
{
    int n;
    cin>>n;
    set< vector<int> > s;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    while(!v.empty()){
        s.insert(v);
        auto it = v.begin();
        v.erase(it);
    }
    auto start = s.begin();
    auto end = s.end();
    end--;
    int maxDis = 0;
    auto index = s.begin();
    vector<int> res;
    for(auto curr = start; curr!=end; curr++){
        auto next = curr;
        next++;
        int length = min((*curr).size(), (*next).size());
        int currDis = 0;
        for(int i=0; i<length; i++){
            if((*curr)[i] == (*next)[i]) currDis++;
            else break;
        }
        if(currDis>maxDis){
            maxDis = currDis;
            index = curr;
        }
    }
    if((*index).size() == 0) cout<<-1;
    else {
        for(int i=0; i<maxDis; i++){
            cout<<(*index)[i]<<" ";
        }
    }
    return 0;
}
/*
Certainly! Let's delve into the program's approach in more detail:

1. **Reading Input**:
   - The program starts by reading the length of the signal sequence, `n`, from the user.
   - It then reads `n` integers, representing the signal values, into a vector `v`. These values are stored in the order they appear.

2. **Finding Repeating Segments**:
   - The program uses a set of vectors, `s`, to store all possible segments of the signal sequence. Initially, this set is empty.
   - To generate these segments, the program iterates through the input vector `v`. In each iteration, it performs the following steps:
     - It adds the current subsequence of `v` to the set `s`. This subsequence represents a possible segment.
     - The program then removes the first element from `v`. This removal ensures that all possible subsequences (segments) of the original signal sequence are eventually added to the set `s`.

3. **Finding the Longest Repeating Segment**:
   - After generating all possible segments in the set `s`, the program proceeds to find the longest repeating continuous segment among these segments.
   - It iterates through the set of vectors `s` and compares each pair of adjacent vectors.
   - For each pair of adjacent vectors, it calculates the length of the common prefix. The common prefix represents the portion of the signal sequence shared by both segments.
   - The program keeps track of the pair with the maximum common prefix length, as this represents the longest repeating continuous segment.

4. **Outputting Results**:
   - Once the program identifies the pair of vectors with the longest common prefix, it considers this as the longest repeating continuous segment.
   - It prints the elements of this segment, separated by spaces, to the standard output.

5. **Handling No Repeating Segment**:
   - If, after analyzing all possible segments, the program doesn't find any repeating continuous segment (i.e., `s` is empty), it prints -1 to indicate that there is no such segment in the signal sequence.

In essence, the program systematically explores all possible segments of the signal sequence by iteratively
removing elements from the original sequence and adding these segments to a set. It then identifies the longest
repeating continuous segment by comparing the common prefixes of adjacent segments in the set and prints this
segment as the final result. If no repeating segment is found, it outputs -1 as specified.
*/