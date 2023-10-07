#include <iostream>
#include <vector>

using namespace std;
/*
**Problem Summary:**

A contractor is tasked with the construction of a highway bypassing Hungary for a given amount of money. The contractor can either complete the work and keep the money, or if unable to complete, divide the work and money into three equal parts and pass them on to two new contractors. This division continues recursively.

The task is to determine:
1. The number of contractors who did not receive less money than anyone else during this process.
2. The number of contractors who did not receive more money than anyone else.
3. The number of contractors who did not pass on the work to others.

**Input:**

- Number of jobs (work and money divisions) (N).
- N lines, each containing three numbers: the contractor number dividing the work and money (1≤S≤2N+1), and the two new contractor numbers who receive a third each of the work and money (1≤A,B≤2N+1). The contractor with number 1 starts with the initial amount.

**Output:**

- Number of contractors who did not receive less money than anyone else.
- Number of contractors who did not receive more money than anyone else.
- Number of contractors who did not pass on the work to others.

The outputs should be in ascending order.

**Example:**

- **Input:**
  ```
  4
  1 2 3
  2 4 5
  4 6 7
  7 8 9
  ```

- **Output:**
  ```
  3 7 8 9
  2 1 3
  5 3 5 6 8 9
  ```

In this example, contractor 3 is the one who has the same or more money than everyone else, contractor 1 has the least or equal money to everyone else, and contractors 5, 6, 8, and 9 did not pass on the work.

---

*/
int main()
{
    int n;
    cin>>n;
    vector<bool> nonTricut(2*n+2,true);
    vector<int> dis(2*n+2,0);
    int l = 0;
    for(int i=1; i<=n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        nonTricut[x] = false;
        dis[x] = dis[x] + 1;
        dis[y] = dis[x];
        dis[z] = dis[x];
        l = max(l,max(x,max(y,z)));
    }
    int maxCutNum = 0, minCutNum = 100000000;
    vector<int> nonCut, maxCut, minCut;
    for(int i=1; i<=l; i++){
        minCutNum = min(minCutNum, dis[i]);
        maxCutNum = max(maxCutNum, dis[i]);
        if(nonTricut[i]) nonCut.push_back(i);
    }
    for(int i=1; i<=l; i++){
        if(minCutNum == dis[i]) minCut.push_back(i);
        if(maxCutNum == dis[i]) maxCut.push_back(i);
    }
    cout<<maxCut.size()<<" ";
    for(auto i:maxCut) cout<<i<<" ";
    cout<<'\n';
    cout<<minCut.size()<<" ";
    for(auto i:minCut) cout<<i<<" ";
    cout<<'\n';
    cout<<nonCut.size()<<" ";
    for(auto i:nonCut) cout<<i<<" ";
    return 0;
}
/*
The provided C++ program addresses the problem of determining certain aspects of contractors and their work divisions and earnings. Let's break down the approach and understand how the program achieves this.

### 1. **Understanding the Problem:**

The program deals with contractors dividing work and earnings into three equal parts and passing them on to two new contractors recursively. The goal is to determine specific properties of the contractors, such as those who received the least or equal money, the most money, or did not pass on the work.

### 2. **Input:**

- Read the number of jobs (work and money divisions) (N).
- Read N lines, each containing three numbers: the contractor number dividing the work and money (S), and the two new contractor numbers who receive a third each of the work and money (A, B).

### 3. **Approach:**

- Maintain vectors to keep track of contractors who did not pass on the work, those who received the least or equal money, and those who received the most money.
- Iterate through the input and calculate the distribution of work and money, updating the vectors accordingly.
- Print the results based on the determined properties.

### 4. **Implementation:**

- Maintain vectors to keep track of contractors based on the specified properties.
- Iterate through the input and update the vectors based on the contractor information and work/money distribution.
- Print the results accordingly.

### 5. **Output:**

- Print the number of contractors who did not receive less money than anyone else, followed by the contractor numbers.
- Print the number of contractors who did not receive more money than anyone else, followed by the contractor numbers.
- Print the number of contractors who did not pass on the work, followed by the contractor numbers.

### Example Walkthrough:

Let's walk through an example using the given input and see how the program determines the contractors based on the specified properties.

### Input:
```
4
1 2 3
2 4 5
4 6 7
7 8 9
```

### Output:
```
3 7 8 9
2 1 3
5 3 5 6 8 9
```

In this example, the program successfully identifies the contractors who did not receive less money than anyone else, those who did not receive more money than anyone else, and those who did not pass on the work.

### Note:

The program efficiently calculates the relevant contractor properties based on the input and prints the results accordingly. If you have any specific questions or need further assistance, feel free to ask!
*/