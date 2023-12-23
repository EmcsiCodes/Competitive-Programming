#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
"Vasút" (Railway):

- **Problem Description**:
  There are N railway lines in a country, each with Mi stations. Stations are identified by their serial numbers. If a station has the same serial number on multiple railway lines, passengers can transfer from one to another at that station.
  
- **Task**:
  Create a program that, given two stations, determines the minimum number of transfers required to travel from one to the other and lists the stations where transfers need to be made.

- **Input**:
  - The first line of standard input contains the number of stations K (1 ≤ K ≤ 10,000), the number of railway lines N (1 ≤ N ≤ 200), and the serial numbers of the departure and destination stations A and B (1 ≤ A ≠ B ≤ K).
  - The next N lines describe each railway line. Each line starts with the number of stations Mi (2 ≤ Mi ≤ 200), followed by Mi station numbers (1 ≤ station number ≤ K). It is guaranteed that one can reach station B from station A.

- **Output**:
  - The program should output the minimal number of transfers C required to travel from A to B on the first line.
  - The second line should list the stations where transfers need to be made in the order they need to be made, separated by a single space.

- **Example**:
  - **Input**:
    ```
    15 4 10 13
    6 11 10 9 3 4 5
    5 5 4 6 12 13
    6 1 2 3 6 7 8
    3 14 4 15
    ```
  - **Output**:
    ```
    1
    4
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector< pair<int,int> > rails[201];
vector<int> railNodes[10001];
bool connectedRails[201][201] = {false};

void BFS(int startNode,int endNode,int railNum){
    queue<int> q;
    vector<bool> visited(railNum+1,false);
    vector<int> dis(railNum+1,0);
    vector< pair<int,int> > parent(railNum+1,{0,0});
    for(auto i:railNodes[startNode]){
        q.push(i);
        visited[i] = true;
    }
    vector<int> possibleEnd;
    for(auto i:railNodes[endNode]){
        possibleEnd.push_back(i);
    }
    while(!q.empty()){
        int rail = q.front();
        q.pop();
        for(auto i:rails[rail]){
            if(!visited[i.first]){
                visited[i.first] = true;
                q.push(i.first);
                dis[i.first] = dis[rail] + 1;
                parent[i.first] = {rail,i.second};
            }
        }
    }
    int minDis = 1000000;
    int railIndex = 0;
    for(auto i:possibleEnd){
        if(minDis > dis[i]){
            minDis = dis[i];
            railIndex = i;
        }
    }
    stack<int> res;
    pair<int,int> i = {railIndex,endNode};
    i = parent[i.first];
    while(i.first>0){
        res.push(i.second);
        i = parent[i.first];
    }
    cout<<res.size()<<'\n';
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    cout<<'\b';
}

int main()
{
    int nodeNum,railNum,startNode,endNode;
    cin>>nodeNum>>railNum>>startNode>>endNode;
    for(int i=1; i<=railNum; i++){
        int m;
        cin>>m;
        for(int j=1; j<=m; j++){
            int x;
            cin>>x;
            railNodes[x].push_back(i);
        }
    }
    
    for(int i=1; i<=nodeNum; i++){
        if(railNodes[i].size()>1){
            for(auto j = 0; j < railNodes[i].size(); j++){
                for(auto p = j + 1; p < railNodes[i].size(); p++){
                    int x = railNodes[i][j];
                    int y = railNodes[i][p];                
                    if(!connectedRails[x][y]){
                        rails[x].push_back({y,i});
                        rails[y].push_back({x,i});
                        connectedRails[x][y] = true;
                        connectedRails[y][x] = true;
                    }
                }
            }    
        }
    }
    BFS(startNode,endNode,railNum);
    return 0;
}
/*
Sure, let's delve into a more detailed explanation of the program's approach and its key components.

### 1. **Graph Representation and Input Parsing**:

The program starts by reading the input, which provides information about the railway lines, stations, and their connections. It constructs a graph to represent this information.

- **Graph Representation**:
  - Each railway line is represented as an edge in the graph.
  - Stations that belong to multiple railway lines are connected by edges, forming a network.

- **Input Parsing**:
  - The program parses the input to extract the necessary information: the number of stations (`nodeNum`), the number of railway lines (`railNum`), the start and end stations (`startNode` and `endNode`), and the stations that each railway line passes through.
  - It stores the stations associated with each railway line in `railNodes`.

### 2. **Connecting Railway Lines and Stations**:

The program connects stations that belong to multiple railway lines by creating edges between them. This is essential for determining the possible transfers between lines.

- **Connecting Stations**:
  - For each station that belongs to multiple railway lines, the program creates edges between all combinations of these lines.
  - This ensures that stations where transfers are possible are connected in the graph.

- **Building Edges**:
  - The program uses a 2D boolean array, `connectedRails`, to track which railway lines are connected by certain stations.
  - It iterates through stations and railway lines to create edges and populate `connectedRails`.

### 3. **Finding the Minimum Number of Transfers using BFS**:

The primary goal is to find the minimum number of transfers needed to travel between the start and end stations.

- **BFS Traversal**:
  - The program uses Breadth-First Search (BFS) to traverse the graph and find the shortest path from the start to the end station.
  - During BFS traversal, it keeps track of distances and parent stations.

- **Recording Transfers**:
  - After BFS traversal, the program identifies the railway line of the destination station and backtracks using parent stations to find transfer stations.
  - It records these stations in a stack, ensuring they are in the correct order for output.

### 4. **Outputting the Results**:

Finally, the program outputs the minimal number of transfers and the stations where transfers need to be made.

- **Output Format**:
  - It outputs the minimal number of transfers, which is the size of the transfer stations stack.
  - It then outputs the stations where transfers need to be made, following the order recorded in the stack.

### 5. **Example Input and Output**:

For the given example input, the program calculates that one transfer is required to travel from station 10 to station 13. It then outputs the transfer stations in the order they need to be made:

```
1
4
```

### 6. **Overall Complexity and Efficiency**:

The program achieves its goal with an efficient approach, using BFS to traverse the graph and calculate the minimum number of transfers. The use of data structures like arrays, queues, and stacks helps in maintaining the necessary information and efficiently processing the network of railway lines and stations.
*/