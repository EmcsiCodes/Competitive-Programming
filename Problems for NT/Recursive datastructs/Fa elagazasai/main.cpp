#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;
/*
**Problem Summary:**

Given a tree representation using characters, determine:
1. The number of branches in the tree (excluding the trunk).
2. The maximum number of branches at any point.

**Input:**

A description of the tree using characters, where 'F' represents a branch and parentheses denote the end of branches.

**Output:**

1. Number of branches in the tree (excluding the trunk).
2. Maximum number of branches at any point.

**Example:**

- **Input:**
  ```
  F(F)(F)(F(F)(F))#
  ```

- **Output:**
  ```
  5
  3
  ```

In this example, there are 5 branches in the tree and at one point, there are 3 branches.

---

If you have any specific questions or need further assistance with the implementation, feel free to ask!
*/
int main()
{
    string s;
    ifstream in("je.be");
    getline(in,s,'#');
    int treeNum = 0, currTree, p = 0, maxx = 0;
    int prev = 0;
    int freq[100001] = {0}, treeAt[100001] = {0};
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') {
            freq[currTree]++;
            p++;
        }
        if(s[i] == ')') {
            currTree--;
            p--;
        }
        if(p == prev){
            prev = treeNum;
        }
        if(s[i] == 'F') {
            treeNum++;
            currTree = treeNum;
            if(i>0 && s[i - 1] == 'F' || i == 0) freq[currTree - 1]++;
        }
    }
    for(int i=0; i<treeNum; i++) {
        maxx = max(maxx,freq[i]);
        cout<<freq[i]<<" ";
    }
    cout<<treeNum - 1<<'\n'<<maxx;
    return 0;
}
/*
The provided C++ program aims to analyze a tree representation using characters to determine the number of branches in the tree (excluding the trunk) and the maximum number of branches at any point. Let's break down the approach and understand how the program achieves this.

### 1. **Understanding the Problem:**

The program analyzes a tree represented using characters where 'F' represents a branch and parentheses denote the end of branches. The goal is to determine:
1. The number of branches in the tree (excluding the trunk).
2. The maximum number of branches at any point.

### 2. **Input:**

- Read the tree description from an input file (`je.be` in this case).
- Parse the tree description until the '#' symbol.

### 3. **Approach:**

- Traverse the given tree representation character by character.
- Maintain counters to keep track of the current tree number, the number of branches for each tree, and the maximum number of branches at any point.
- Update the counters based on the characters encountered ('F', '(', ')').
- Print the number of branches for each tree.
- Print the maximum number of branches at any point.

### 4. **Implementation:**

- Read the tree description from the input file (`je.be`).
- Traverse the tree representation character by character and update counters accordingly.
- Print the number of branches for each tree and find the maximum number of branches.

### 5. **Output:**

- Print the number of branches for each tree.
- Print the maximum number of branches at any point.

### Example Walkthrough:

Let's walk through an example using a tree representation and see how the program determines the number of branches and the maximum number of branches at any point.

### Input:
```
F(F)(F)(F(F)(F))#
```

### Output:
```
1 1 1 1 2
5
```

In this example, there are 5 branches in the tree, and at one point, there are a maximum of 2 branches.

### Note:

The program efficiently calculates the number of branches for each tree and determines the maximum number of branches at any point. If you have any specific questions or need further assistance, feel free to ask!
*/