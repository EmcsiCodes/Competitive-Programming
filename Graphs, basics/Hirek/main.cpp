#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
- **Problem Description**:
  In a class, each student knows the phone numbers of some of their classmates. We define that student A can send a message to student B if A can call someone who can call someone else, and so on, until the last person can call B.

- **Input**:
  - The first line of standard input contains the number of students N (1 ≤ N ≤ 400).
  - The following N lines each contain either 'i' or 'n', indicating whether a student knows the phone numbers of another student. If the i-th character in the j-th line is 'i', it means the i-th student knows the phone number of the j-th student.

- **Output**:
  - The program should output the number of pairs of students who can send messages to each other (Problem A).
  - The program should output the number of students who can send messages to everyone (Problem B).

- **Example**:
  - **Input**:
    ```
    5
    i i i i i
    n i n n n
    i n i n i
    n n n i i
    n n n i i
    ```
  - **Output**:
    ```
    2
    2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[401], canVisit[401];

void BFS(int node,int n){  
    vector<bool> visited(n+1,false);
    visited[node] = true;
    queue<int> q;
    q.push(node);
    int originalNode = node;

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                if(i!=originalNode) canVisit[originalNode].push_back(i);
                q.push(i);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char x;
            cin>>x;
            if(x == 'i' && i!=j){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=1; i<=n; i++){
        BFS(i,n);
    }
    int hirek[401][401]={0};
    int db=0;
    for(int i=1; i<=n; i++){
        if(canVisit[i].size() == n - 1) db++;
        for(auto j:canVisit[i]){
            hirek[i][j]=1;
        }
    }
    int count = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(hirek[i][j] && hirek[j][i]) {
                count++;
            }
        }
    }
    cout<<count<<endl<<db;
    return 0;
}
/*
### Student Messaging Analysis

#### Approach:
The problem involves finding the number of pairs of students who can send messages to each other (Problem A) and the number of students who can send messages to everyone (Problem B).

1. **Graph Representation**:
   - We model the problem as a directed graph, where each student is a node, and knowledge of phone numbers represents directed edges.

2. **Breadth-First Search (BFS)**:
   - We perform a BFS from each student to find the students they can message directly. We keep track of this information in the `adj` and `canVisit` vectors.
   - The `adj` vector stores the adjacency list for each student, indicating whom they can message directly.
   - The `canVisit` vector stores the students that can be reached by a BFS from each student.

3. **Pair Counting (Problem A)**:
   - We iterate over the `canVisit` vector and count the pairs of students who can send messages to each other. If student A can reach student B and vice versa, we increment the pair count.

4. **Student Counting (Problem B)**:
   - We count the number of students who can send messages to everyone, i.e., whose `canVisit` vector size is `n-1`, where `n` is the total number of students.

#### Pseudocode:
1. Read the input: `n` (number of students) and adjacency information representing who knows whose phone number.
2. Perform BFS for each student to find students they can message directly and store this information in the `canVisit` vector.
3. Iterate over the `canVisit` vector and count the pairs of students who can message each other.
4. Count the students who can send messages to everyone (i.e., whose `canVisit` size is `n-1`).
5. Output the results.

#### Time Complexity:
- Constructing the graph and performing BFS for each student takes O(n^2) time.
- Counting pairs and students takes O(n) time.
- Overall time complexity: O(n^2).
*/