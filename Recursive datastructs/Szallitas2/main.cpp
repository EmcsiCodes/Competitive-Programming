#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> adj[20001];
multiset< pair<int,int> > maxRoute[20001], res;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> degree(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        degree[x]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0) {
            q.push(i);
            maxRoute[i].insert({0,i});
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int next = adj[node][0];
        degree[next]--;
        auto currBest = maxRoute[node].end();
        currBest--;
        maxRoute[next].insert({currBest->first + 1, currBest->second});
        if(maxRoute[node].size()>1){
            for(auto it = maxRoute[node].begin(); it!=currBest; it++){
                res.insert(*it);
            }
        }
        if(degree[next] == 0) {
            q.push(next);
            if(next == 0) {
                res.insert({maxRoute[next].rbegin()->first - 1,maxRoute[next].rbegin()->second});
                q.pop();
            }
        }
    }
    int total = 0;
    vector<int> start;
    for(auto it = res.rbegin(); it!=res.rend() && k!=0; it++){
        total += it->first;
        start.push_back(it->second);
        k--;
    }
    cout<<total<<'\n';
    for(auto i:start) cout<<i<<" ";
    return 0;
}