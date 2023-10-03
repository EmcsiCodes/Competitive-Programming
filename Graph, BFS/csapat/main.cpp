#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
During an outing, students need to be divided into two teams. The teams must be created in such a way that if student X and student Y don't like each other, they must be in different teams. Each team should have at least one student.

Input: The input consists of the number of students, N (1≤N≤200,000), and the number of pairs, M (1≤M≤1,000,000), who don't like each other. The following M lines each contain two integers (1≤XY≤N), indicating that student X and student Y don't like each other.

Output: Output two lines, each containing the members of one team. If there is no solution, output -1 on a single line. The numbers can be output in any order. If there are multiple solutions, any one of them is valid.

Example:

Input:
9 8
1 2
5 7
9 1
3 4
6 8
3 9
9 4
5 4
2 6
7 8
Output:
1 3 5 7
2 4 6 8 9
Explanation:

For the given input, one possible division of students into teams is as follows:

Team 1: Students 1, 3, 5, 7
Team 2: Students 2, 4, 6, 8, 9
*/
vector<int> adj[200001];
vector<int> nodes;

// Breadth-First Search (BFS) to assign students to teams
bool BFS(int node, int n, vector<bool> &visited) {
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for (auto i : adj[node]) {
            if (!visited[i]) {
                if (nodes[i] == 0) {
                    if (nodes[node] == 1)
                        nodes[i] = 2;  // Assign to the opposite team
                    else
                        nodes[i] = 1;
                    q.push(i);
                    visited[i] = true;
                } else {
                    return false;  // If already assigned to a different team
                }
            }
        }
    }
    return true;
}

// Function to solve the problem and output the teams
void solve(int n) {
    vector<bool> visited(n + 1, false);

    // Iterate through all students to assign them to teams
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (!BFS(i, n, visited)) {
                cout << -1;
                return;
            }
        }
    }

    // Output the members of each team
    for (int i = 1; i <= n; i++) {
        if (nodes[i] == 0 || nodes[i] == 1) {
            cout << i << " ";  // Output members of team 1
        }
    }
    cout << '\b' << '\n';

    for (int i = 1; i <= n; i++) {
        if (nodes[i] == 2) {
            cout << i << " ";  // Output members of team 2
        }
    }
    cout << '\b';
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build the adjacency list based on the provided pairs
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Initialize the nodes vector
    for (int i = 1; i <= n; i++) {
        nodes.push_back(0);
    }

    // Solve the problem and output the teams
    solve(n);

    return 0;
}
/*
Approach Overview:
The approach is based on graph theory and specifically using BFS to assign students to teams. We create an adjacency list representation of the graph based on the pairs of students who don't like each other. Then, we use BFS to traverse the graph and assign students to teams accordingly.

Detailed Explanation:
Input Parsing:

Parse the input, including the number of students (n) and the number of pairs (m) representing students who don't like each other.
Parse the pairs to create an adjacency list representation of the graph.
Build the Adjacency List:

Create an adjacency list representation of the graph based on the provided pairs. Each student is a node, and if two students don't like each other, there is an edge between them in the graph.
BFS to Assign Students to Teams:

Perform a BFS traversal starting from each unvisited student. If the student is not assigned to a team yet, assign them to Team 1 (nodes[node] = 1).
Traverse through the graph using BFS, assigning opposite teams to students who don't like each other.
If a student is already assigned to a team and that team is the same as the one the BFS algorithm tries to assign, it means there is a conflict and a valid solution is not possible.
Output the Result:

Output the members of each team by iterating through the students.
Print the members of Team 1 (students assigned to Team 1) and then the members of Team 2 (students assigned to Team 2).
*/