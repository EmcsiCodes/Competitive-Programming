#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
The problem is about tracking the spread of gossip among a group of students over a series of days. The spread of gossip follows certain rules, and the goal is to determine the maximum number of students who know the gossip on a particular day and identify the first day when this maximum is reached.

The input includes the number of students (N), the number of friendships (M), and the number of students who know the gossip on the first day (K). The friendships between students are then described, followed by the friendships between students who know the gossip initially.

The program needs to output the maximum number of students who know the gossip on any given day and the day when this maximum is first reached. Additionally, it should output how many students know the gossip on each day from the start until the first day when the maximum is reached.

Example:
Input:
4 4 1
1
1 2
2 3
2 4
3 4
Output:
4
5
1 1 3 3 4
Explanation:

Day 1: Student 1 knows the gossip.
Day 2: Students 2, 3, and 4 know the gossip.
Day 3: Students 1, 3, and 4 know the gossip.
Day 4: Students 2, 3, and 4 know the gossip.
Day 5: All students know the gossip.
Constraints:

1 ≤ N ≤ 105
1 ≤ M ≤ 2 * 105
1 ≤ K ≤ N

*/
vector<int> adj[100001];

void BFS(int n,queue<int> q){
    int layer = 1;
    int lastNode = q.back();
    vector<int> res;
    res.push_back(q.size());
    while(layer!=200000 || !q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            q.push(i);
        }
        if(lastNode != q.back()){
            lastNode = q.back();
            res.push_back(q.size());
            layer++;
            if(q.size() == n) break;
        }
    }
    int maxPletyka = 0;
    int maxPletykaIndex = 0;
    for(int i=0; i<res.size(); i++){
        if(res[i] > maxPletyka){
            maxPletyka = res[i];
            maxPletykaIndex = i;
        }
    }
    cout<<maxPletyka<<'\n'<<maxPletykaIndex + 1<<'\n';
    for(int i=0; i<=maxPletykaIndex; i++){
        cout<<res[i]<<" ";
    }
    cout<<'\b';
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    queue<int> q;
    for(int i=1; i<=k; i++) {
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(n,q);
    return 0;
}
/*
This program addresses the problem of tracking the spread of gossip among a group of students over a series of days, aiming to determine the maximum number of students who know the gossip on a particular day and identify the first day when this maximum is reached.

Approach:
The program starts by reading the input, including the number of students (N), the number of friendships (M), and the number of students who know the gossip on the first day (K). It also collects the friendships between students and the students who know the gossip initially.
The program simulates the spread of gossip using breadth-first search (BFS) starting from the students who initially know the gossip.
It iterates over each day, considering the current set of students who know the gossip and finding their friends who don't yet know it.
The simulation continues until all students know the gossip or until 200,000 days.
At each step, it keeps track of the maximum number of students who know the gossip and the corresponding day when this maximum is reached.
Finally, it outputs the maximum number of students who know the gossip on any given day, the day when this maximum is first reached, and the number of students who know the gossip on each day.
Explanation:
The program simulates the spread of gossip using BFS.
It starts with the students who initially know the gossip and explores their friends in layers, considering one day at a time.
It counts the number of students who know the gossip each day and keeps track of the maximum count and the corresponding day.
The simulation continues until all students know the gossip or until reaching the maximum allowed day.
It then outputs the required results, including the maximum number of students who know the gossip on any given day, the day when this maximum is first reached, and the number of students who know the gossip on each day.
This program effectively simulates the gossip spread and provides the maximum number of students who know the gossip on any given day and the day when this maximum is first reached.
*/