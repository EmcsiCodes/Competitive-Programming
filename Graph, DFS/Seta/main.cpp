/*#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

vector< pair<int,int> > nodes;
unordered_map<int,int> comp;
vector<int> adj[100001];
set<int> subg[100001];
stack<int> s;
void SCC(int node,vector<int>&disc,vector<int>&low,vector<bool>&onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,onStack);
            low[node] = min(low[node],low[i]);
        } else if(onStack[i]) low[node] = min(low[node],disc[i]);
    }
    if(low[node] == disc[node]){
        int num = 1;
        while(s.top()!=node){
            num++;
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        nodes.push_back({node,num});
        comp[node] = node;
        onStack[node] = node;
        s.pop();
    }
}

void makeSubGraph(int n,int start){
    vector<int> disc(n+1,0),low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,onStack);
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            int x = comp[i], y = comp[j];
            if(x!=y) subg[x].insert(y);
        }
    }
}

void DijkstraAlgo(int n,int start,int finish){
    vector<int> dis(n+1,0);
    priority_queue< pair<int,int> > pq;
    dis[comp[start]] = nodes[comp[start]].second;
    pq.push({dis[comp[start]],comp[start]});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto i:subg[node]){
            if(dis[i] < dis[node] + nodes[i].second){
                dis[i] = dis[node] + nodes[i].second;
                pq.push({dis[i],i});
            }
        }
    }
    cout<<dis[comp[finish]];
}

int main()
{
    int n,m,start,finish;
    cin>>n>>m>>start>>finish;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    makeSubGraph(n,start);
    DijkstraAlgo(n,start,finish);
    return 0;
}*/
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#define N 100001
using namespace std;
int n, m, kezd, veg;
vector<int> a[N];
vector<int> disc(N, -1), low(N, -1), parent(N, -1);
vector<bool> stackMember(N, false);
stack<int> st;
int t = 0;
int compIndex = 0;
vector<int> comp[N];
vector<int> color(N);
int ans = 0;
int endNode;
int startNode;

void tarjan(int node)
{
    low[node] = disc[node] = t;
    t++;
    st.push(node);
    stackMember[node] = true;

    for (int adj : a[node])
    {
        if (disc[adj] == -1)
        {
            tarjan(adj);

            low[node] = min(low[node], low[adj]);
        }
        else if (stackMember[adj])
        {
            low[node] = min(low[node], disc[adj]);
        }
    }

    int w = 0;
    if (low[node] == disc[node])
    {
        while (st.top() != node)
        {
            w = st.top();
            stackMember[w] = false;
            comp[compIndex].push_back(w);
            color[w] = compIndex;
            st.pop();
        }
        w = st.top();
        comp[compIndex].push_back(w);
        color[w] = compIndex;
        stackMember[w] = false;
        st.pop();
        compIndex++;
    }
}

void solve()
{
    //vector<int> g[compIndex];
    vector<int> gSize(compIndex);

    for (int i = 0; i < compIndex; i++)
    {
        vector<bool> used(compIndex, false);
        for (int j : comp[i])
        {
            if (j == veg)
            {
                endNode = i;
            }
            if (j == kezd)
            {
                startNode = i;
            }
            for (int adj : a[j])
            {
               // if (color[adj] != color[j] and !used[color[adj]])
                //{
                //    g[i].push_back(color[adj]);
               //     used[color[adj]] = true;
              //  }
            }
            gSize[i]++;
        }
    }
    vector<int> dist = gSize;
    set<pair<int, int>> q;
    pair<int, int> s = {gSize[startNode], startNode};
    q.insert(s);



    while (!q.empty())
    {
        s = *q.rbegin();
        q.erase(s);
        int node = s.second;
        int distance = dist[node];
       // for (int adj : g[node])
        //{
            // cout<<adj<<" ";
          //  if (gSize[adj] + distance > dist[adj])
           // {
               /// dist[adj] = gSize[adj] + distance;
               // q.insert({dist[adj], adj});
           // }
       // }
        // cout<<endl;
    }
    ans = dist[endNode];
}

int main()
{
    cin >> n >> m >> kezd >> veg;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    tarjan(kezd);
    solve();
    cout << ans << endl;
    return 0;
}
/*
10 15 2 6
1 2
2 3
3 1
2 4
1 10
3 8
9 5
3 5
5 6
6 7
7 5
3 9
10 7
8 9
9 8
*/