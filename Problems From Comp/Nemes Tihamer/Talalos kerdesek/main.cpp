#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
/*
- **Problem Description**:
  In a guessing game, questions are asked, and the answer to each question determines the next question (out of two possible). Based on these answers, a sequence of questions is followed until reaching a set of questions to guess. Each guessing question is associated with a label, which is determined by subtracting the number of "YES" answers from the number of "NO" answers leading to it.

- **Task**:
  Write a program that determines the label that appears most frequently and the number of times it occurs.

- **Input**:
  - The first line of standard input contains the number of questions, N (1 ≤ N ≤ 10,000).
  - The next N lines contain two question numbers Xi and Yi (2 ≤ Xi ≠ Yi ≤ 2 * N + 1) for each question, representing the question number to follow for "YES" and "NO" answers, respectively. If a question number is greater than N, it is a question to be guessed.

- **Output**:
  - The program should output the most frequently occurring label and the number of times it occurs.

- **Example**:
  - **Input**:
    ```
    5
    2 3
    6 4
    7 5
    8 9
    10 11
    ```
  - **Output**:
    ```
    -1 2
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
*/
int main()
{
    int n;
    cin>>n;
    map<int,int> m;
    vector<int> v(2*n+1,0);
    vector<int> t;
    int last = 0;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v[x] = v[i] + 1;
        v[y] = v[i] - 1;
        if(x>n) m[v[x]]++;
        if(y>n) m[v[y]]++;
    }
    int res = 0;
    int maxOcc = 0;
    int maxOccIndex = 0;
    for(auto i:m){ //map<int,int> m
        if(maxOcc<i.second){ //???
            maxOcc = i.second;
            maxOccIndex = i.first;
        }
    }
    cout<<maxOccIndex<<" "<<maxOcc;
    return 0;
}
/*
Sure, let's break down how the program works step by step:

1. **Reading Input**:
   - The program starts by reading the number of questions, `n`, from the user.

2. **Data Structures Initialization**:
   - It initializes a map `m` to store the frequency of labels and a vector `v` of size `2*n+1` to keep track of the labels' frequencies.

3. **Processing Input**:
   - For each question, the program reads two question numbers, `x` and `y`, representing the question number to follow for "YES" and "NO" answers, respectively.
   - It updates the `v` vector based on the relationship between `x`, `y`, and the current question number `i`. If `x` or `y` is greater than `n`, it means it's a question to be guessed, so it updates the corresponding indices in the `v` vector accordingly.

4. **Counting Frequency of Labels**:
   - The program counts the frequency of labels by iterating over the map `m`, incrementing the frequency count for each label based on the information in the `v` vector.

5. **Finding the Most Frequent Label**:
   - It keeps track of the most frequently occurring label and the number of times it occurs.

6. **Outputting Results**:
   - Finally, it prints the most frequently occurring label and the number of times it occurs.

In summary, the program processes the input, keeps track of label frequencies, finds the most frequent label, and outputs the result in the desired format. The key insight is in how it maps the relationships between questions and calculates label frequencies based on the "YES" and "NO" answers.
*/