#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[200001];

int main()
{
    int n;
    cin>>n;
    vector<int> outdegree(n+1,0);
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
        outdegree[x]++;
    }
    queue<int> q;
    q.push(1);
    vector<int> dis(n+1,1); 
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            dis[i] = dis[node] + 1;
            q.push(i);
        }
    }
    int minColor = 1000000;
    for(int i=1; i<=n; i++){
        if(outdegree[i] == 0) minColor = min(minColor, dis[i]);
    }
    cout<<minColor<<'\n';
    vector<int> color(n+1,0);
    q.push(1);
    color[1] = minColor;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            color[i] = color[node] == 1 ? 1 : color[node] - 1;
            q.push(i);
        }
    }
    for(int i=1; i<=n; i++) cout<<color[i]<<" ";
    return 0;
}