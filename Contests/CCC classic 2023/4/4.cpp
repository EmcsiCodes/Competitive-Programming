#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;
#define inf 100000000
char a[300][300];

ofstream db("debug.out");

int invc = 0;

int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<pair<int, int>> paths;

pair<int, int> parent[300][300];

void findPath(int x1, int y1, int n, char a[][300])
{
    bool visited[250][250];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;
    parent[x1][y1] = {-1, -1};
    while (!q.empty())
    {
        // cout<<"whilean"<<endl;
        pair<int, int> node = q.front();
        visited[node.first][node.second] = true;
        //  cout<<node.first<<" "<<node.second<<endl;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx, ny;
            nx = node.first + dx[i];
            ny = node.second + dy[i];
            if (!visited[nx][ny] && a[nx][ny] == 'W' && nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                q.push({nx, ny});
               // cout << node.first  << "," << node.second << " -> " << ny << "," << nx << endl;
                parent[nx][ny] = {node.first, node.second};
                visited[nx][ny] = true;
            }
        }
    }
    cout << "szia";
}

int main()
{
    ifstream f("level4_5.in");
    ofstream g("level4_5.out");
    int n;
    f >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f >> a[i][j];
        }
    }
    int x1, y1, x2, y2;
    int count;
    f >> count;
    string ss;
    getline(f, ss);
    while (count--)
    {
        char c;
        f >> y1 >> c >> x1 >> y2 >> c >> x2;
        cout << y1 << " " << x1 << " " << y2 << " " << x2 << endl;
        memset(parent, 0, sizeof(parent));
        parent[x1][y1] = {-1,-1};
        findPath(x1, y1, n, a);
        vector<pair<int, int>> ans;
        int px = x2, py = y2;
        while (px != -1)
        {
            ans.push_back({px, py});
            cout << px << " " << py << endl;
            int s = px;
            px = parent[px][py].first;
            py = parent[s][py].second;
        }
       // cout << "eredmeny : ";
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            g << ans[i].second << "," << ans[i].first << " ";
        }
        g << endl;
    }
    return 0;
}
