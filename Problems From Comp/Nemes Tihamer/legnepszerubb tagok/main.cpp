#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[10001];
stack<int> s[10001];
void findCycles(int node,vector<int>&disc,vector<bool>&cyclic,int time){
    disc[node] = time;
    s[node].push(node);
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findCycles(i,disc,cyclic,time+1);
            if(cyclic[i] && s[i].size() + 1 > s[node].size()) {
                s[i].push(node);
                s[node] = s[i];
                cyclic[node] = !cyclic[node];
            }
        } else if(time - disc[i] + 1 > s[i].size()) {
            cyclic[node] = true;
            cyclic[i] = true;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
    }
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> cyclic(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) findCycles(i,disc,cyclic,1);
    }
    int maxCycle = 0;
    int maxCycleIndex = 0;
    for(int i=1; i<=n; i++){
        if(s[i].size()>maxCycle){
            maxCycle = s[i].size();
            maxCycleIndex = i;
        }
    }
    cout<<maxCycle<<'\n';
    while(!s[maxCycleIndex].empty()){
        cout<<s[maxCycleIndex].top()<<" ";
        s[maxCycleIndex].pop();
    }
    return 0;
}