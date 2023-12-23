#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
A company employs couriers to deliver confidential letters in various cities. There are multiple couriers, and if a letter needs to be delivered to a specific destination city, the courier who arrives there the fastest is chosen. Each courier can travel through at most K cities in a day.

Write a program to determine the cities that a courier cannot reach within one day and calculate the minimum number of days required for a courier to reach all cities.

Input: The first line contains the number of cities (1≤N≤200,000), the maximum number of cities a courier can visit in one day (1≤K≤N), and the number of roads between cities (1≤M≤1,000,000). The following M lines describe the roads between cities, each containing two integers denoting the source city (1≤X≤N) and the destination city (1≤Y≤N). The last line contains the starting cities for couriers, separated by spaces (1≤Fi≤N).

Output: Print the cities that a courier cannot reach within one day, separated by spaces, on the first line. On the second line, print the minimum number of days needed for a courier to reach the furthest city.

Example:

Input:
8 2 9 6
1 2 2
1 3
2 4
3 4
2 5
4 6
5 6
2 7
7 8
1 7
Output:
1 3 5 8
2
Explanation:

The courier starting from city 1 can reach cities 2, 3, and 4 on the first day. On the second day, it can reach cities 5 and 7. On the third day, it can reach city 8. Therefore, all cities can be reached within 3 days.

Cities that cannot be reached within a day: 1, 3, 5, 8.
*/
vector<int> adj[200001];
vector<int> futarok;

void BFS(int n,int k){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    queue<int> q;
    for(auto i:futarok){
        q.push(i);
        visited[i] = true;
    }
    int node;
    while(!q.empty()){
        queue<int> p = q;
        node =  q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                dis[i] = dis[node] + 1;
                q.push(i);
            }
        }
    }
    vector<int> canNotReach;
    int longestPath = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] > k) canNotReach.push_back(i);
        longestPath = max(longestPath,dis[i]);
    }
    if(longestPath % k != 0) longestPath = longestPath / k + 1;
    else longestPath = longestPath / k;

    for(auto i:canNotReach){
        cout<<i<<" ";
    }
    cout<<'\b'<<'\n';
    cout<<longestPath;
}

int main()
{
    int n,k,m,a;
    cin>>n>>k>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>a;
    for(int i=1; i<=a; i++){
        int x;
        cin>>x;
        futarok.push_back(x);
    }
    BFS(n,k);
    return 0;
}
/*
Input Reading:

Read the number of cities n, the maximum number of cities a courier can visit in one day k, the number of roads between cities m.
Read the details of the roads between cities.
Read the starting cities for couriers.
Graph Construction:

Construct an adjacency list representation of the graph where cities are nodes and roads are edges.
BFS to Calculate Reach:

Perform a breadth-first search (BFS) starting from the given starting cities for couriers.
In each BFS level, calculate the cities that can be reached within one day based on the given k (maximum cities a courier can visit in a day).
Determining Unreachable Cities:

Identify cities that cannot be reached within one day based on the BFS traversal and k.
Store these cities in the canNotReach vector.
Calculating Minimum Days:

Calculate the longest path (number of days needed) to reach the furthest city.
If the longest path is not a multiple of k, round up to the nearest whole number.
This gives the minimum number of days needed for a courier to reach all cities.
Output:

Print the cities that a courier cannot reach within one day, separated by spaces.
Print the minimum number of days needed for a courier to reach the furthest city.
The program uses BFS to simulate the traversal of couriers and calculates the minimum number of days required for a courier to reach all cities while considering the maximum number of cities a courier can visit in one day (k). Additionally, it identifies cities that a courier cannot reach within a day based on this traversal.
*/