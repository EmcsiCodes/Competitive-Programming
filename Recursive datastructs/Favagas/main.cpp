#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

void DFS(int node,vector<bool> &visited, vector<int> &infNum,vector<int>&nodeNum){
    visited[node] = true;
    int currNode = 0;
    int currInf = 0;
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS(i,visited,infNum,nodeNum);
            currNode += nodeNum[i];
            currInf += infNum[i];
        }
    }
    nodeNum[node] += currNode;
    infNum[node] += currInf;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<bool> infected(n+1,false), visited(n+1,false);
    vector<int> infNum(n+1,0), nodeNum(n+1,1);
    for(int i=1; i<=n; i++){
        int x,y,z,q;
        cin>>x>>y>>z>>q;
        if(z!=-1) adj[x].push_back(z);
        if(q!=-1) adj[x].push_back(q);
        if(y == 1) {
            infected[x] = true;
            infNum[x]++;
        }
    }
    DFS(0,visited,infNum,nodeNum);
    int cuts = 1;
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push({nodeNum[0],infNum[0]});
    vector<int> res;
    int totalCuts = 0;
    while(true){
        auto node = pq.top();
        pq.pop();
        if(infected[node.first]) continue; 
        int currInf = node.second;
        int next = adj[node.first][0];
        if(next!=0 || next!=currInf){
            if(cuts == k){
                while(!pq.empty()){
                    res.push_back(pq.top().);
                    pq.pop();
                }
                totalCuts = 
            }
        } else {
            while(currInf == node.second){
                int left = adj[node.first][0];
                int right = adj[node.first].size() == 2 ? adj[node.first][1] : n;
                if(infNum[left] == currInf) node = {left,currInf};
                else if(infNum[right] == currInf) node = {right,currInf};
                else {
                    pq.push({nodeNum[node.first],node.second});
                    break;
                }
            }
        }
    }
    return 0;
}