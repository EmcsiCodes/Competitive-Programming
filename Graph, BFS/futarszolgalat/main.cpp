#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
In a country, there are N cities, and a courier needs to deliver packages to K specified cities. The courier can choose the starting and ending cities for their route. It's required to find the minimum distance the courier needs to travel and the route they should take to deliver all packages.

Input: The first line contains the number of cities (1≤N≤100,000) and the number of deliveries (1≤K≤N). The following N-1 lines describe road segments between cities, each containing two integers denoting the source city (1≤Ai≠Bi≤N) and the destination city (1≤Bi≤N) along with the length of the road segment (0≤Hi≤1,000). The last line contains K integers representing the cities where the courier needs to deliver packages.

Output: Print the minimum distance T the courier needs to travel in the first line. In the second line, print the shortest route for the courier to deliver all packages. If there are multiple solutions, any valid route can be provided.

Example:

Input:
9 4
1 3 5
3 2 4
3 4 9
4 9 2
5 6 3
6 7 3
8 5 2
5 4 5
1 2 5 7
Output:
33
1 3 2 3 4 5 6 7
Explanation:

The courier can start from any city and deliver packages to cities 1, 2, 5, and 7. The shortest route is: 1 → 3 → 2 → 3 → 4 → 5 → 6 → 7, with a total distance of 33.
*/
vector< pair<int,int> > adj[100001];

void BFS(int startNode,pair<int,int> &endNode,int n,vector<int> v){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first]){
                visited[i.first] = true;
                dis[i.first] = dis[node] + i.second;
                q.push(i.first);
            }
        }
    }
    int maxDis = 0;
    int maxDisIndex = 0;

    for(int i=1; i<v.size(); i++){
        if(maxDis < dis[v[i]]){
            maxDis = dis[v[i]];
            maxDisIndex = v[i];
        }
    }
    endNode = {maxDis, maxDisIndex};
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    vector<int> v(k+1,0);
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        v[i] = x;
    }
    pair<int,int> endNode = {0,0}, longestPath = {0,0};
    BFS(1,endNode,n,v);
    BFS(endNode.second,longestPath,n,v);
    cout<<endNode.second<<" - "<<longestPath.second<<": "<<longestPath.first;
    return 0;
}
/*
Input Reading:

Read the number of cities n and the number of deliveries k.
Read the details of road segments between cities, including the source city, destination city, and length of the road segment.
Read the cities where the courier needs to deliver packages.
Graph Construction:

Construct an adjacency list representation of the graph where cities are nodes and road segments are edges, each with its length.
BFS for Shortest Routes:

Perform breadth-first searches (BFS) starting from various specified delivery cities.
Calculate the shortest route to each specified city using BFS and store the maximum distance and the corresponding city.
Output:

Print the minimum distance (T) the courier needs to travel, which is the distance of the longest route among the specified cities.
Print the shortest route for the courier to deliver all packages, which is the path from the start city to the city with the longest route.
The program uses BFS to find the shortest routes to each specified delivery city and then identifies the city with the longest route. It calculates the minimum distance the courier needs to travel (which is the longest route) and the shortest route to deliver all packages. Finally, it prints this information.
*/