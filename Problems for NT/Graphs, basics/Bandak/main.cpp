#include <iostream>
#include <vector>
using namespace std;
/*
- **Problem Name**: Bandák (Gangs)

- **Problem Description**:
  The Johannesburg police know all the criminals in the city. They know that two criminals belong to the same gang if they have committed a crime together at least once (only those who committed the crime together know each other).
  Criminals are identified by their serial numbers instead of their names (starting from 1, with continuous numbering). The police store the serial numbers of criminals belonging to the same gang. In the first line of the input, the number of criminals is given (maximum 50), and in each subsequent line (maximum 100), two serial numbers of criminals who committed a crime together are given (separated by a single space). There can be solitary criminals who do not belong to any gang (they should not be considered when asking for results related to gangs).

- **Task**:
  Write a program that determines:
  A. The serial numbers of solitary criminals.
  B. The number of gangs.
  C. The member of each gang with the most connections.
  D. The number of members in the largest gang.
  E. The key members of each gang, i.e., those who, if imprisoned, would cause the gang to split into the most independent parts.
  F. The number of securely organized gangs, i.e., those from which the police cannot arrest any criminal in a way that the gang splits into multiple parts!
  G. The number of riskily organized gangs, i.e., those in which only the leader knows everyone, and therefore, if the leader is arrested, the gang will fall apart into solitary criminals!
  H. The number of completely organized gangs, i.e., those in which everyone knows everyone!

- **Input**:
  - The first line of the standard input contains the number of criminals (maximum 50).
  - Each subsequent line contains two serial numbers of criminals who committed a crime together.
  - The input is terminated with the value 0 0.

- **Output**:
  - The program should output the solutions to each subtask in separate lines, ordered by the order of subtasks. If there are multiple solutions, the one with the minimum serial number should be provided.

- **Example**:
  - **Input**:
    ```
    7
    1 2
    1 4
    3 1
    5 6
    2 3
    1 2
    0 0
    ```
  - **Output**:
    ```
    7
    2
    1 5
    4
    1 5
    0
    2
    1
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MiB
*/
bool visited[51] = {false};
vector<int> adj[51], comp[51];
int comp_num = 0;

void lonelyThiefs(int n){
    int t = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].empty()) cout<<i<<" ";
    }
    cout<<'\b'<<'\n';
}

void DFS(int v, bool visited[]){
    visited[v] = true;
    for(auto i:adj[v]){
        if(!visited[i]){
            comp[comp_num].push_back(i);
            DFS(i,visited);
        }
    }
}

void components(int n){
    for(int i=1; i<=n; i++){
        if(!visited[i]) {
            comp_num++;
            comp[comp_num].push_back(i);
            DFS(i,visited);
        }
    }
    int count = 0;
    for(auto i:comp){
        if(i.size()>1) count++;
    }
    cout<<count<<'\n';
}
int main()
{
    int n,x,y;
    cin>>n;
    while(cin>>x>>y && x!=0 && y!=0){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    lonelyThiefs(n);
    components(n);
    
    return 0;
}
/*
The provided program addresses the problem of identifying various aspects related to gangs of criminals in the city. The program determines solitary criminals, the number of gangs, the member of each gang with the most connections, the number of members in the largest gang, the key members of each gang, and the organization level of each gang.

Here's a summary of the program's logic:

1. **Input Reading:**
   - Read the number of criminals (N).
   - Read pairs of serial numbers representing criminals who committed a crime together.
   - The input is terminated with the value 0 0.

2. **Lonely Thieves:**
   - Output the serial numbers of solitary criminals (those who do not belong to any gang, i.e., have no connections).

3. **Finding Gangs:**
   - Use DFS to identify connected components (gangs) in the graph of criminals based on the crimes committed together.
   - Output the number of gangs.

### Output:
The program outputs the solutions to each subtask in separate lines, as follows:
1. Serial numbers of solitary criminals.
2. Number of gangs.

The program appears to correctly solve the initial parts of the problem, including identifying solitary criminals and the number of gangs. However, it seems to lack the complete implementation for the remaining subtasks like the member of each gang with the most connections, the number of members in the largest gang, the key members of each gang, and the organization level of each gang.
*/