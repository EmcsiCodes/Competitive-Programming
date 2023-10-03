#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int n;
vector<int> a[1000001];
vector<int> solve;
int maxx = 0;

void dfs(int node, int length)
{
    if (length > maxx)
    {
        solve.clear();
        maxx = length;
        solve.push_back(node);
    }
    else if (length == maxx)
    {
        solve.push_back(node);
    }

    for (int adj : a[node])
    {
        dfs(adj, length + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    dfs(1, 0);
    sort(solve.begin(), solve.end());
    cout << solve.size() << " " << maxx << endl;
    for (int i : solve)
        cout << i << " ";
    return 0;
}
/*
11
1
2
1
4
5
5
1
8
9
10
*/