#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
/*
The goal of the task is to organize the towns of Bergengócia into districts. Each town will be assigned to the district whose center is closest to that town. The distance between two towns is defined as the length of the shortest path between them.

The input consists of the number of settlements (N), the number of towns (M), and the number of roads (K) between them. The second line contains the indices of the M towns, sorted in increasing order. The following K lines describe the roads: from which town to which town the road leads.

The output should be M lines indicating the number of settlements in each district. The lines should be in ascending order based on the district centers. If a village is equidistant from multiple district centers, it should be assigned to the one with the smallest index.

Example:
Input:
8 3 10
2 3 7
1 2
1 5
5 4
4 2
2 3
2 6
3 6
3 7
7 8
Output:
5
1
2
Constraints:

Time limit: 0.1 seconds
Memory limit: 32 MiB
Scoring: In 40% of the tests, N < 100.
*/
vector<int> city;
vector<int> adj[1001];

void BFS(int n){
    vector<bool> visited(n+1,false);
    int parentNode[1001];
    queue<int> q;
    for(int i=0; i<city.size(); i++){
        q.push(city[i]);
        visited[city[i]] = true;
        parentNode[city[i]] = city[i];
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                parentNode[i] = parentNode[node];
            }
        }
    }
    map<int,int> res;
    for(int i=1; i<=n; i++){
        res[parentNode[i]] += 1;
    }
    for(auto i:res){
        cout<<i.second<<'\n';
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        city.push_back(x);
    }
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(n);
    return 0;
}
/*
This C++ program aims to organize towns into districts, where each town is assigned to the district whose center is closest to it. It uses a breadth-first search (BFS) based approach to achieve this. Let's go through the code and understand it step by step.

Function Definitions:

BFS performs breadth-first search to assign each town to its closest district center.
It uses a map to store the count of settlements in each district.
The parentNode array keeps track of the closest district center for each town.
BFS Algorithm:

It starts BFS from each town and assigns the town to its closest district center.
Uses a queue to traverse the graph and calculate the district centers for each town.
Main Function:

Reads input values: number of settlements (N), number of towns (M), and number of roads (K).
Reads the indices of the M towns and constructs a list of towns (city).
Constructs the adjacency list based on the given roads.
Calls the BFS function to assign towns to districts and print the count of settlements in each district.
Output:

Prints the number of settlements in each district, in ascending order based on the district centers.
In summary, this program organizes towns into districts, assigning each town to the closest district center using breadth-first search (BFS). It calculates the number of settlements in each district and prints them in the required format.
*/
