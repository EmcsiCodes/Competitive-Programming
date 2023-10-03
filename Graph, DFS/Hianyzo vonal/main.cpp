#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//Same problem as the "Erosen osszefuggove tetel"
vector<int> adj[10001];
stack<int> s;
pair<int,int> res;
void findSCCs(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack,vector<int> inDegree,vector<int> outDegree){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    currStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findSCCs(i,disc,low,currStack,inDegree,outDegree);
            low[node] = min(low[node], low[i]);
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(disc[node] == low[node]){
        int currSCCin = 0;
        int currSCCout = 0;
        while(s.top()!=node){
            currSCCin += inDegree[s.top()];
            currSCCout += outDegree[s.top()];
            currStack[s.top()] = false;
            //cout<<s.top()<<" ";
            s.pop();
        }
        currSCCin += inDegree[s.top()];
        currSCCout += outDegree[s.top()];
        currStack[s.top()] = false;
        //cout<<s.top()<<" , in:";
        s.pop();
        //cout<<currSCCin<<", out:"<<currSCCout<<endl;
        if(currSCCin > currSCCout) res.first = node;
        if(currSCCout > currSCCin) res.second = node;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> inDegree(n+1,0), outDegree(n+1,0), disc(n+1,0), low(n+1,0);
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
        outDegree[x]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) findSCCs(i,disc,low,currStack,inDegree,outDegree);
    }
    cout<<res.first<<" "<<res.second;
    return 0;
}
/*
11 14
1 2
2 3
3 1
2 4
4 5
5 6
6 7
7 5
4 8
8 9
9 4
4 10
10 11
11 4
*/