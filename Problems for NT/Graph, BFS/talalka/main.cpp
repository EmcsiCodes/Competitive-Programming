#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
To summarize the problem "Találka" (Meeting):

In this problem, Romeo and Juliet want to meet each other in the shortest possible time. They are currently in different cities and plan to travel by plane to a city where they can both arrive in the shortest time. They have information about all available flight routes.

Input:

Number of cities (N) and number of flights (M).
Romeo and Juliet's current city indices (A and B).
Descriptions of flights between cities.
Output:

The time of the nearest meeting and the city index where they will meet.
The flight routes for Romeo and Juliet to reach the meeting city.
Example:

Input:
10 15
1 8
1 2
2 1
1 4
3 2
4 3
2 5
3 6
3 7
4 7
5 10
6 9
7 6
8 7
8 9
Output:
2 7
1 4 7
8 7
In this example, there are 10 cities and 15 flights. Romeo is in city 1 and Juliet is in city 8. The program should determine the nearest meeting time and city, along with the flight routes for Romeo and Juliet to reach that city.
*/
vector<int> adj[20001];

void BFS(int node,int n, vector<int> &path, vector<int> &dis){
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
                path[i] = node;
            }
        }
    }
}

void solve(int n,int a,int b){
    vector<int> path1(n+1,0),path2(n+1,0),dis1(n+1,0),dis2(n+1,0);
    BFS(a,n,path1,dis1);
    BFS(b,n,path2,dis2);
    int endNode = 0;
    int minPath = 100000;
    for(int i=1; i<=n; i++){
        if(dis1[i]!=0 && dis2[i]!=0){
            int p = max(dis1[i],dis2[i]);
            if(p < minPath){
                minPath = p;
                endNode = i;
            }
        }
    }
    if(endNode == 0){
        cout<<-1;
        return;
    }
    cout<<minPath<<" "<<endNode<<'\n';
    stack<int> s;
    s.push(endNode);
    int i = endNode;
    while(dis1[i] > 1){
        s.push(path1[i]);
        i = path1[i];
    }
    s.push(a);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    s.push(endNode);
    i = endNode;
    while(dis2[i] > 1){
        s.push(path2[i]);
        i = path2[i];
    }
    s.push(b);
    cout<<'\b'<<'\n';
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<'\b';
}

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    solve(n,a,b);
    return 0;
}
/*
Problem Summary:
Given a network of cities and flights between them, the task is to determine the shortest time for Romeo and Juliet to meet. They start from different cities and need to travel to a city where they can both meet in the shortest time. The cities are connected by flights, and the goal is to minimize the time it takes for both of them to reach the same city.

Approach:

Input Reading:

Read the number of cities (N), the number of flights (M), and the current cities of Romeo (A) and Juliet (B).
Read the flight connections between cities.
Graph Representation:

Create an adjacency list to represent the graph, where each city is a node, and flights are edges.
Initialize the adjacency list with information about flight connections.
BFS for Romeo and Juliet:

Run BFS (Breadth-First Search) twice, once for Romeo and once for Juliet.
For both BFS traversals, start from the respective cities of Romeo and Juliet.
During BFS traversal, keep track of the distance from the starting city to each other city and the path taken to reach each city.
Find Meeting Point:

After BFS traversals, calculate the minimum meeting time by comparing the distances from Romeo's and Juliet's cities to each city.
Find the city index where they will meet based on the minimum path length.
Output:

Print the minimum meeting time and the city index where Romeo and Juliet will meet.
Print the flight routes for Romeo and Juliet to reach the meeting city.
The flight routes are obtained by tracing back the paths from both Romeo and Juliet cities to the meeting city.
Explanation:

The BFS traversals help in finding the shortest paths from Romeo's and Juliet's cities to all other cities.
By comparing the distances from both cities to each city, we determine the shortest time to reach each city.
The minimum meeting time is the shortest time to a city where both Romeo and Juliet can meet.
The code traces the paths taken to find the meeting city and prints them as flight routes for Romeo and Juliet.
This approach efficiently finds the shortest meeting time and the meeting city for Romeo and Juliet, considering the available flight connections between cities. It utilizes BFS to calculate the shortest paths and assists in determining the meeting point.
*/
