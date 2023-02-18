#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[20001];
vector<int> outDegree(20001,0);
vector<long long> peopleOnNode(20001,0);
void topSort(int n){
    queue<int> q;
    peopleOnNode[n] = 1;
    q.push(n);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            outDegree[i]--;
            peopleOnNode[i] += peopleOnNode[node];
            if(outDegree[i] == 0) q.push(i);
        }
    }
    cout<<peopleOnNode[1];
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x;
        cin>>x;
        for(int j=1; j<=x; j++){
            int y;
            cin>>y;
            adj[y].push_back(i);
            outDegree[i]++;
        }
    }
    topSort(n);
    return 0;
}