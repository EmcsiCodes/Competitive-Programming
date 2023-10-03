#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
using namespace std;

#define LL long long

struct edges{
    LL freq;
    int weight;
};

LL findFreq(int n,int node,vector<bool>&visited,vector< pair<int,int> > adj[],queue<edges>&q){
    visited[node] = true;
    LL currFreq = 1;
    for(auto i:adj[node]){
        if(!visited[i.first]){
            LL f = findFreq(n,i.first,visited,adj,q);
            q.push({(f * (n-f))%9999991,i.second});
            currFreq += f;
        }
    }
    return currFreq;
}

int main()
{
    ifstream in("arbori3.in");
    ofstream out("arbori3.out");
    int n;
    while(in>>n && n!=0){
        vector< pair<int,int> > adj[100001];
        queue<edges> q;
        LL c = 1;
        for(int i = 1; i < n; i++){
            c = (c * i)%9999991;
            int x,y,z;
            in>>x>>y>>z;
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }
        c = (c * 2)%9999991;
        int start = 0;
        for(int i=1; i<=n; i++){
            if(adj[i].size() == 1){
                start = i;
                break;
            }
        }
        vector<bool> visited(n+1,false);
        findFreq(n,start,visited,adj,q);
        LL res = 0;
        while(!q.empty()){
            res = (res + ((c * q.front().freq)%9999991 * q.front().weight)%9999991)%9999991;
            q.pop();
        }
        out<<res<<'\n';
    }
    return 0;
}