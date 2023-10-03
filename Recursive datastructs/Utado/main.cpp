#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n;
struct f{
    int node1;
    int node2;
    int frequency;
};

struct Compare{
    bool operator()(f const& p1, f const& p2){
        return p1.frequency < p2.frequency;
    }
};

vector<int> adj[50001];
priority_queue<f, vector<f>, Compare> freqEdge;

int DFS(int node,vector<bool>&visited){
    visited[node] = true;
    int freq = 1;
    for(auto i:adj[node]){
        if(!visited[i]){
            int curr = DFS(i,visited);
            freqEdge.push({node,i,(curr * (n - curr))});
            freq += curr;
        }
    }
    return freq;
}

int main()
{
    ifstream in("szia.in");
    ofstream out("szia.out");
    in>>n;
    for(int i=1; i<n; i++){
        int x,y;
        in>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> prices;
    for(int i=1; i<n; i++){
        int x;
        in>>x;
        prices.push_back(x);
    }
    int start = 0;
    int totalPrice = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 1){
            start = i;
            break;
        }
    }
    vector<f> res;
    vector<bool> visited(n+1,false);
    DFS(start,visited);
    sort(prices.begin(),prices.end(), greater<int>());
    auto it = prices.begin();
    while(!freqEdge.empty()){
        //cout<<freqEdge.top().frequency<<endl;
        totalPrice = (totalPrice%32609 + ((freqEdge.top().frequency%32609 * 2)%32609 * (*it)%32609)%32609)%32609;
        res.push_back({freqEdge.top().node1, freqEdge.top().node2, (*it)});
        it++;
        freqEdge.pop();
    }
    out<<totalPrice%32609<<'\n';
    for(auto i:res) {
       out<<i.node1<<" "<<i.node2<<" "<<i.frequency<<'\n';
    }
    return 0;
}
/*
6
1 0
1 2
2 3
1 4
2 5
5 6 3 1 1
*/