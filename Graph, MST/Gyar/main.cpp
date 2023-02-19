#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct nodes
{
    int node1;
    int node2;
    int d;
};
struct Compare
{
    bool operator()(nodes &p1, nodes &p2)
    {
        return p1.d > p2.d;
    }
};

vector<int> parent(20001, 0), s(20001, 1);
vector<bool> startNodes(20001, false);
priority_queue<nodes, vector<nodes>, Compare> pq;

int find(int a)
{
    int root = a;
    while (root != parent[root])
        root = parent[root];
    while (a != root)
    {
        int next = parent[a];
        parent[a] = root;
        a = next;
    }
    return root;
}

void Unite(int a, int b)
{
    int root1 = find(a);
    int root2 = find(b);
    if (s[root1] < s[root2])
    {
        parent[root1] = parent[root2];
        s[root2] += s[root1];
    }
    else
    {
        parent[root2] = parent[root1];
        s[root1] += s[root2];
    }
}

int main()
{
    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        pq.push({x, y, z});
    }

    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        startNodes[x] = true;
        s[x] = 25000;
    }

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int totalDis = 0;
    vector<pair<int, int>> res;
    while (!pq.empty())
    {
        nodes curr = pq.top();
        pq.pop();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        if (root1 != root2 && !(s[root1]>=25000 && s[root2]>=25000))
        {
            Unite(curr.node1, curr.node2);
            totalDis += curr.d;
            res.push_back({curr.node1, curr.node2});
        }
    }
    cout << totalDis << endl;
    for (auto i : res)
        cout << i.first << " " << i.second << endl;

    return 0;
}
/*
6 2 7
1 2 5
1 3 3
2 4 2
3 4 4
2 5 3
2 6 8
5 6 1
1 6
*/