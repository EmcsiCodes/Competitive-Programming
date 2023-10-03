#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
The problem is about finding the minimum number of transfers for Adam and Eve to meet at a given meeting point, given a train schedule.

The input consists of the number of cities (N), the location of Eve (E) and Adam (A), the meeting point (R), and the number of train schedules (M). Each of the following M lines contains two integers, indicating the departure and arrival cities for a train.

The program should output the minimum number of transfers for Eve and Adam, as well as the respective paths.

Example:
Input:
10 2 3 7 12
2 1
1 6
7 6
6 8
8 7
7 9
9 4
5 7
10 5
3 5
3 4
4 5
Output:
5 3
2 1 6 8 7
3 5 7
Explanation:
Eve can take the route: 2 -> 1 -> 6 -> 8 -> 7 -> 3. Adam can take the route: 3 -> 5 -> 7.

Constraints:

1 ≤ N ≤ 20,000
1 ≤ E ≠ A ≤ N
1 ≤ R ≤ N
1 ≤ M ≤ 200,000

*/
vector<int> adj[20001];

vector<int> BFS(int node,int endNode,int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,1);
    vector<int> pathIndex(n+1,0);
    queue<int> q;
    int index = 0;
    q.push(node);

    while(!q.empty() && index!=endNode){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
                pathIndex[i] = node;
                if(i == endNode) {
                    index = i;
                }
            }
        }
    }
    stack<int> path;
    vector<int> res;
    if(index == endNode){
        path.push(endNode);
        int i = dis[index];
        while(i>1){
            path.push(pathIndex[index]);
            index = pathIndex[index];
            i--;
        }
        while(!path.empty()){
            res.push_back(path.top());
            path.pop();
        }
    }
    return res;
}

int main()
{
    int n,E,A,t,m;
    cin>>n>>E>>A>>t>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> res1,res2;
    res1 = BFS(E,t,n);
    res2 = BFS(A,t,n);
    if(res1.empty() || res2.empty()) cout<<0<<" "<<0;
    else {
        cout<<res1.size()<<" "<<res2.size()<<'\n';
        for(auto i:res1) cout<<i<<" ";
        cout<<'\b'<<'\n';
        for(auto i:res2) cout<<i<<" ";
        cout<<'\b';
    }
    return 0;
}
/*
This program addresses the problem of finding the minimum number of transfers required for Eve and Adam to meet at a given meeting point, given a train schedule.

Approach:
The program starts by reading the input, which includes the number of cities (N), the locations of Eve (E) and Adam (A), the meeting point (R), and the number of train schedules (M).
It constructs a graph representation of the train schedules, where each city is a node, and the train schedules are edges between the cities.
The program utilizes Breadth-First Search (BFS) to find the shortest path from Eve (E) to the meeting point (R) and from Adam (A) to the meeting point (R).
It records the paths taken by both Eve and Adam during BFS.
Finally, it outputs the minimum number of transfers required for both Eve and Adam to meet at the meeting point (R), as well as the respective paths taken by each.
Explanation:
The program constructs a graph representing the train schedules and uses BFS to find the shortest paths for both Eve and Adam to reach the meeting point.
It then outputs the minimum number of transfers required and the paths taken by both Eve and Adam.
This program successfully determines the minimum number of transfers required for Eve and Adam to meet at the specified meeting point and provides the corresponding paths for both.
*/
