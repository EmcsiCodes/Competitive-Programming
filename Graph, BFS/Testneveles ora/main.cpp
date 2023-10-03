#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
/*
To summarize the problem "Testnevelés óra" (Physical Education Class):

The task involves arranging students in a gymnastics row based on their height, following the given pairs of students where one is shorter than the other. The goal is to find if it's possible to arrange the students in such a way and, if yes, if there's more than one valid arrangement.

- **Input**:
  - Number of students (`N`) and the number of given student pairs (`K`).
  - Pairs of students based on height.

- **Output**:
  - Whether the students can be arranged according to the given pairs and the number of valid arrangements.
  - If valid arrangements exist, the order of students in each valid arrangement.

- **Example**:
  - **Input**:
    ```
    5 9
    3 1
    3 5
    4 2
    3 2
    1 4
    1 2
    1 5
    5 4
    ```
  - **Output**:
    ```
    1
    3 1 5 4 2
    ```
  - **Explanation**: The students can be arranged in a single valid way according to the given height information.

  - **Input**:
    ```
    5 3
    1
    2
    1 5
    4 2
    3 2 1 5
    2 3 1 5
    2
    ```
  - **Output**:
    ```
    2
    ```

  - **Explanation**: There are multiple valid arrangements possible in this case.

The goal is to determine if it's possible to arrange students in a gymnastics row according to the given height information, and if so, how many different valid arrangements exist.
*/

vector<int> adj[200000];

void topSort(int n){
    vector<int> res,res2;
    vector<int> inDegree(n+1,0);
    queue<int> q;
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            inDegree[j]++;
        }
    }
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0){
            q.push(i);
            res.push_back(i);
            res2.push_back(i);
        }
    }
    bool multipleAns = false;
    if(q.size()>1) {
        multipleAns = true;
        int i = res2.size() - 1;
        swap(res2[i],res2[i-1]);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
                res.push_back(i);
                res2.push_back(i);
            }
        }
        if(q.size() > 1 && !multipleAns){
            multipleAns = true;
            int i = res2.size() - 1;
            swap(res2[i],res2[i-1]);
        }
    }
    if(res.size()!=n){
        cout<<0;
        return;
    }
    if(!multipleAns){
        cout<<1<<'\n';
        for(auto i:res) cout<<i<<" ";
        return;
    }
    cout<<2<<'\n';
    for(auto i:res) cout<<i<<" ";
    cout<<'\n';
    for(auto i:res2) cout<<i<<" ";
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    topSort(n);
    return 0;
}
/*
Problem Summary:
The problem involves arranging students in a gymnastics row based on their height, following the given pairs of students where one is shorter than the other. The goal is to determine if it's possible to arrange the students according to the given pairs and find the number of valid arrangements.

Approach:
The approach used in the provided code involves topological sorting of a directed graph. Here's a step-by-step breakdown:

Input Reading:

Read the number of students (N) and the number of given student pairs (K).
Read the pairs of students based on height.
Graph Representation:

Create an adjacency list to represent the directed graph, where each node represents a student, and the directed edge (u, v) signifies that student u is shorter than student v.
Topological Sorting:

Perform topological sorting on the directed graph using the Kahn's algorithm.
Initialize an in-degree array to keep track of the in-degrees of all nodes.
Iterate through the adjacency list and calculate the in-degrees for each node.
Start with nodes having in-degree zero and process them in a BFS-like manner, reducing the in-degree of connected nodes.
During this process, maintain two result vectors (res and res2) to store the order of students based on topological sorting.
Multiple Valid Arrangements:

Check if multiple valid arrangements are possible by checking if more than one node has an in-degree of zero.
If multiple valid arrangements are possible, swap the last two elements of res2.
Output:

If the topological sorting results in a valid ordering, print the number of valid arrangements and the order of students for each arrangement.
Example:

Given the input pairs of students based on height, the code performs topological sorting to determine if a valid arrangement is possible. If multiple valid arrangements exist, it prints them accordingly.
The approach efficiently handles the problem of arranging students in a gymnastics row based on the given height pairs, considering the directed graph structure and performing topological sorting to determine valid arrangements if they exist.
*/