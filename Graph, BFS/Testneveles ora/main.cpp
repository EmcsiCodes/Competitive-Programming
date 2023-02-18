#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[200000];

void topSort(int n){
    vector<int> res,res2;
    vector<int> inDegree(n+1,0);
    queue<int> q;
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            inDegree[j]++;
        }
    }
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0){
            q.push(i);
            res.push_back(i);
            res2.push_back(i);
        }
    }
    bool multipleAns = false;
    if(q.size()>1) {
        multipleAns = true;
        int i = res2.size() - 1;
        swap(res2[i],res2[i-1]);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
                res.push_back(i);
                res2.push_back(i);
            }
        }
        if(q.size() > 1 && !multipleAns){
            multipleAns = true;
            int i = res2.size() - 1;
            swap(res2[i],res2[i-1]);
        }
    }
    if(res.size()!=n){
        cout<<0;
        return;
    }
    if(!multipleAns){
        cout<<1<<'\n';
        for(auto i:res) cout<<i<<" ";
        return;
    }
    cout<<2<<'\n';
    for(auto i:res) cout<<i<<" ";
    cout<<'\n';
    for(auto i:res2) cout<<i<<" ";
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    topSort(n);
    return 0;
}
/*
5 7
3 1
3 5
3 2
1 4
1 2
1 5
5 4
*/