#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
The problem is about determining the number of countries occupied by aggressive countries after a certain number of years. Each year, a non-aggressive country can occupy all its non-aggressive neighbors that have no other aggressive neighbors, and then annex them. The goal is to calculate the number of countries occupied by each aggressive country after a certain number of years.

The input includes the number of countries (N), the number of aggressive countries (R), and the number of years (K). The countries are identified by numbers from 1 to N, with the first R being aggressive countries. The subsequent lines describe the neighbors of each country.

The program needs to output, for each aggressive country, the number of countries it occupied after K years and list those countries.

Example:
Input:
11 3 2
4 7 0
4 5 8 9 0
10 0
1 2 5 7 8 0
2 4 6 9 10 0
5 10 0
1 4 8 11 0
2 4 7 0
2 5 10 0
3 5 6 9 0
7 0
Output:
2 7 11
3 5 8 9
1 10

*/
int aggressiveParent[30001];
vector<int> adj[30001];
queue<int> q;
vector< pair<bool,int> > visited;

bool valid(int i,int node,int currLayer){
    if(!visited[i].first) {    
        for(auto j:adj[i]){
            if(visited[j].second!=currLayer && j!=node) return false;
        }
        return true;
    }
    return false;
}

void BFS(int n,int r,int k){
    int layer = 1;
    int last = r;
    while(!q.empty() && layer<=k){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(valid(i,node,layer)){
                visited[i].first = true;
                q.push(i);
                aggressiveParent[i] = aggressiveParent[node];
            }
        }
        if(node == last){
            layer++;
            last = q.back();
        }
    }
    vector<int> res[30001];
    for(int i=1; i<=n; i++){
        if(aggressiveParent[i] != i){
            res[aggressiveParent[i]].push_back(i);
        }
    }
    for(int i=1; i<=r; i++){
        cout<<res[i].size()<<" ";
        for(auto j:res[i]) cout<<j<<" ";
        cout<<'\b'<<'\n';
    }
}

int main()
{
    int n,r,k;
    cin>>n>>r>>k;
    visited.push_back({false,0});
    for(int i=1; i<=n; i++){
        int x;
        visited.push_back({false,1});
        if(i<=r) {
            q.push(i);
            visited[i].first = true;
            visited[i].second = 0;
            aggressiveParent[i] = i;
        }
        while(cin>>x && x!=0){
            adj[i].push_back(x);
        }
    }
    BFS(n,r,k);
    return 0;
}
/*
This program addresses the problem of determining the number of countries occupied by aggressive countries after a certain number of years. The task involves a simulation-like approach where non-aggressive countries can be occupied by their non-aggressive neighbors that have no other aggressive neighbors.

Approach:
The program begins by reading the input, including the number of countries (N), the number of aggressive countries (R), and the number of years (K). It also collects the neighbors of each country.
It simulates the occupation process for K years. In each year, it checks non-aggressive neighbors of each aggressive country and marks them as occupied if they meet certain conditions.
The conditions for a country to be occupied are that it should be non-aggressive, have no other aggressive neighbors, and haven't been visited in the current year's simulation.
The simulation iterates through layers of countries based on their distance from the aggressive countries.
The program maintains a parent array to keep track of the aggressive country that occupied a non-aggressive country.
After the simulation, it organizes the occupied countries based on the aggressive country that occupied them.
Finally, it outputs the number of occupied countries for each aggressive country and lists those countries.
Explanation:
The program processes each aggressive country (from 1 to R) as the starting point.
For each starting aggressive country, it traverses the neighbors in layers, marking non-aggressive countries for occupation based on the conditions.
It keeps track of the aggressive country that occupies each non-aggressive country.
After the simulation, it organizes the occupied countries based on the aggressive country that occupied them and outputs the results.
This program simulates the occupation process based on the given rules, resulting in the number of countries occupied by each aggressive country after K years.
*/