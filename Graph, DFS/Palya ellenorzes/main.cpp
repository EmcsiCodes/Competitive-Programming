#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[20001];
vector<int> outDegree(20001,0);
int maxPeople = 0;
void topSort(int n){
    queue<int> q;
    int backNode = 1;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            outDegree[i]--;
            if(outDegree[i] == 0) q.push(i);
        }
        if(backNode!=q.back()){
            backNode = q.back();
            int s = q.size();
            maxPeople = max(maxPeople,s);
        }
    }
    cout<<maxPeople;
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
            adj[i].push_back(y);
            outDegree[i]++;
        }
    }
    topSort(n);
    return 0;
}