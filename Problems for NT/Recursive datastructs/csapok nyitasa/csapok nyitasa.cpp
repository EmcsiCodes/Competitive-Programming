#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> adj[100001];

vector<int> BFS(int start, int n) {
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = node;
                q.push(i);
            }
        }
    }
    return parent;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int m;
    cin >> m;
    queue<int> q;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    vector<int> parent = BFS(1, n);
    set<int> res;
    while (!q.empty()) {
        int root = q.front();
        q.pop();
        if (parent[root] != 0) {
            root = parent[root];
            res.insert(root);
            q.push(root);
        }
    }
    cout << res.size() << '\n';
    for (auto i : res) cout << i << " ";
    return 0;
}