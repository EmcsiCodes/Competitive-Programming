#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> adj[201];
int deletedEdge[201][201] = {false};
stack<int> s;
void makeAcyclic(int node,vector<int> &disc,vector<int> &low,vector<bool> &onStack,vector<bool> &canReachFinish){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            makeAcyclic(i,disc,low,onStack,canReachFinish);
            if(canReachFinish[i]) canReachFinish[node] = true;
            low[node] = min(low[node],low[i]);
        } else {
            if(onStack[i]){
                if(disc[i] <= low[node]){
                    low[node] = disc[i];
                    deletedEdge[node][i] = true;
                }
            }
            if(canReachFinish[i]) canReachFinish[node] = true;
        }
    }
    if(low[node] == disc[node]){
        while(s.top()!=node){
            onStack[s.top()] = false;
            s.pop();
        }
        onStack[s.top()] = false;
        s.pop();
    }
}

void topSort(int start,int end,int n,vector<bool> canReachFinish){
    vector<int> inDegree(n+1,0), IND(n+1,0), res;
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(!deletedEdge[i][j] && canReachFinish[i] && canReachFinish[j]){
                IND[j]++;
                inDegree[j]++;
            }
        }
    }
    queue<int> q;
    q.push(start);
    int in = 0, out = 0;
    res.push_back(start);
    while(!q.empty() && !(q.size()==1 && q.front() == end)){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(canReachFinish[i]){
                out++;
                inDegree[i]--;
            }
            if(inDegree[i] == 0 && canReachFinish[i]){
                in += IND[i];
                q.push(i);
            }
        }
        if(q.size() == 1 && q.front()!=end && in == out){
            res.push_back(q.front());
        }
    }
    res.push_back(end);
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
}

int main()
{
    int n,m,start,end;
    cin>>n>>start>>end>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> disc(n+1,0),low(n+1,0);
    vector<bool> onStack(n+1,false), canReachFinish(n+1,false);
    canReachFinish[end] = true;
    makeAcyclic(start,disc,low,onStack,canReachFinish);
    topSort(start,end,n,canReachFinish);
    /*for(int i=1; i<=n; i++){
        for(auto j:adj[i]) if(deletedEdge[i][j]) cout<<i<<"->"<<j<<endl;
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        if(canReachFinish[i]) cout<<i<<" ";
    }*/
    return 0;
}
/*
6
1 6
7
1 2
1 3
2 4
3 4
4 5
5 2
5 6
*/