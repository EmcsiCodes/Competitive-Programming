#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
During a trip, a group of students needs to be divided into two teams. The teams must be formed such that if students X and Y are friends, they should be in the same team, but if they don't like each other, they cannot be in the same team.

Input: The first line of input contains the number of students (1≤N≤10,000), the number of friendly pairs, and the number of pairs who do not like each other (1≤M+K≤4,000,000). The next M lines contain the friendly pairs, and the following K lines contain pairs of students who do not like each other.

Output: The first line of the standard output should contain the identifiers of the students in one team, and the second line should contain the identifiers of the students in the other team, each separated by a space. The order of the students does not matter. If there is no solution, output -1 on a single line.

Example:

Input:
11 7 4
1 2
3 4
5 6
9 10
10 11
11 9
7 8
2 3
6 9
8 4
7 11
Output:
1 2 5 6 7 8
3 4 9 10 11
Explanation:

The first team can consist of students {1, 2, 5, 6, 7, 8} and the second team can consist of students {3, 4, 9, 10, 11} following the given conditions.
*/
vector< pair<int,char> > adj[10001];

bool BFS(int startNode,int n,vector<bool> &visited, vector<int> &res){
    queue<int> q;
    q.push(startNode);
    res[startNode] = 0;
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            int check;
            if(i.second == 'F') check = res[node];
            else check = !res[node];            
            if(!visited[i.first]){
                q.push(i.first);
                visited[i.first] = true;
                res[i.first] = check;
            } else if(check != res[i.first]) return false;
        }
    }
    return true;
}

void solve(int n){
    vector<bool> visited(n+1,false);
    vector<int> res(n+1,-1);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(!BFS(i,n,visited,res)){
                cout<<-1;
                return;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(res[i] == 0){
            cout<<i<<" ";
        }
    }
    cout<<'\b'<<'\n';
    for(int i=1; i<=n; i++){
        if(res[i] == 1){
            cout<<i<<" ";
        }
    }
    cout<<'\b';
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,'F'});
        adj[y].push_back({x,'F'});
    }
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,'E'});
        adj[y].push_back({x,'E'});
    }
    solve(n);
    return 0;
}
/*
Approach Overview:
The approach involves using a modified Breadth-First Search (BFS) to assign students to teams based on their friendships and dislikes. We traverse the graph of students and assign them to teams (0 or 1) while ensuring that friends are in the same team and those who dislike each other are in separate teams.

Detailed Explanation:
Input Parsing:

Parse the input, including the number of students (n), the number of friendly pairs (m), and the number of pairs who dislike each other (k).
Build the Adjacency List:

Create an adjacency list representation of the graph based on the provided friendly and dislike pairs.
BFS to Assign Students to Teams:

Use BFS to traverse the graph and assign students to teams (0 or 1) based on their friendships and dislikes.
Initially, assign a team to the starting student (0 or 1) and propagate this assignment based on friendships and dislikes.
If a conflict arises during the assignment (e.g., a friend is assigned a different team), output -1 as there is no valid solution.
Output the Result:

Output the identifiers of the students in one team and then the identifiers of the students in the other team, each separated by a space.
The order of the students does not matter.
Time Complexity Analysis:
The time complexity is determined by the BFS traversal, which takes O(N + M) time, where N is the number of students and M is the total number of friendly and dislike pairs.
Overall, the time complexity of the solution is O(N + M).
Overall Approach:
The program efficiently assigns students to teams based on their friendships and dislikes using BFS traversal, ensuring that friends are in the same team and those who dislike each other are in separate teams. The BFS approach guarantees a valid solution to the problem.
*/