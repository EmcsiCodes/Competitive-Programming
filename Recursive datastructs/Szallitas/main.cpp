#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> w(n+1,0), cap(n+1,0), degree(n+1,0), truckCap(n+1,0), truckNum(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        w[i] = x;
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        cap[i] = x;
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        degree[x]++;
    }
    queue<int> q;
    int totaltrucks = 0;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int newTrucks = 0;
        int node = q.front();
        q.pop();
        int next = adj[node][0];
        int weight = w[node] - cap[node];
        if(weight > 0){
            if(truckCap[node]<weight) newTrucks = weight%k <= truckCap[node] ? weight/k : weight/k + 1;
            truckCap[node] = truckCap[node] + newTrucks * k - weight;
            totaltrucks += newTrucks;
            truckNum[node] += newTrucks;
        } else {
            if(truckNum[node] * k - truckCap[node] + w[node] <= cap[node]) truckCap[node] = truckNum[node] * k;
            else truckCap[node] += (cap[node] - w[node]);
        }
        truckCap[next] += truckCap[node];
        truckNum[next] += truckNum[node];
        degree[next]--;
        if(degree[next] == 0 && next!=0) q.push(next);
        else if(degree[next] == 0){
            cout<<truckNum[node]<<'\n'<<truckNum[node] * k - truckCap[node];
        }
    }
    return 0;
}
/*
9 10
8 3 2 20 11 7 4 9 5
5 7 4 10 6 4 4 5 3
2 3 0 3 3 2 4 4 6
*/