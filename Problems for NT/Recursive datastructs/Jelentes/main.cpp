#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
**Problem Summary:**

A company has a hierarchical structure where, except for the director (who has no boss), each employee has exactly one immediate supervisor. If an employee wants to send a report to the director, they must follow the chain of command, passing the report to their immediate supervisor, who in turn passes it to their supervisor, and so on, until the report reaches the director.

The task is to calculate the maximum number of days it could take for a report to reach the director, and to identify an employee from whom it would take the maximum number of days.

**Input:**

- Number of employees (N).
- N lines, each containing a list of employees who report to the corresponding employee (separated by spaces), with each list ending with a 0. If there are no direct reports for an employee, the line contains only a 0.

**Output:**

- The maximum number of days it takes for a report to reach the director (M).
- The identification number of an employee from whom it would take M days for a report to reach the director. If there are multiple such employees, output the one with the smallest identification number.

**Example:**

- **Input:**
  ```
  9
  3 2 0
  8 0
  4 5 7 0
  0
  0
  0
  6 0
  9 0
  0
  ```

- **Output:**
  ```
  3
  6
  ```

In this example, it takes a maximum of 3 days for a report to reach the director, and employee 6 is the one from whom it would take the maximum number of days.
*/
vector<int> adj[10001];

void BFS(int start,int n){
    vector<int> dis(n+1,0);
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
    }
    int maxDis = 0;
    int maxDisI = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] > maxDis){
            maxDis = dis[i];
            maxDisI = i;
        }
    }
    cout<<maxDis<<'\n'<<maxDisI;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        while(cin>>x && x!=0){
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    BFS(1,n);
    return 0;
}
/*
The provided C++ program tackles the task of calculating the maximum number of days it could take for a report to reach the director within a company's hierarchical structure. It also identifies an employee from whom it would take the maximum number of days. Let's break down the approach and understand how the program achieves this.

### 1. **Understanding the Problem:**

The program deals with a company's hierarchical structure, where each employee has one immediate supervisor, except the director. The task is to find the maximum number of days it would take for a report to reach the director and identify an employee from whom it would take the maximum number of days.

### 2. **Input:**

- Read the number of employees (N).
- Read N lines, each containing a list of employees who report to the corresponding employee (separated by spaces), with each list ending with a 0.

### 3. **Approach:**

- Implement a breadth-first search (BFS) algorithm to traverse the hierarchical structure starting from the director.
- For each employee, calculate the number of days it would take for a report to reach the director (which is the distance from the employee to the director in the hierarchical structure).
- Identify an employee from whom it would take the maximum number of days to reach the director.

### 4. **Implementation:**

- Implement a BFS algorithm to traverse the hierarchical structure and calculate the distances.
- Identify the employee from whom it would take the maximum number of days.
- Print the results accordingly.

### 5. **Output:**

- Print the maximum number of days it takes for a report to reach the director.
- Print the identification number of an employee from whom it would take the maximum number of days.

### Example Walkthrough:

Let's walk through an example using the given input and see how the program calculates the maximum number of days and identifies the employee.

### Input:
```
9
3 2 0
8 0
4 5 7 0
0
0
0
6 0
9 0
0
```

### Output:
```
3
6
```

In this example, the program successfully calculates that it would take a maximum of 3 days for a report to reach the director, and employee 6 is the one from whom it would take the maximum number of days.

### Note:

The program efficiently calculates the relevant information based on the input and prints the results accordingly. If you have any specific questions or need further assistance, feel free to ask!
*/