#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int,int> > adj[100001];

void solve(int n,int tomPos,int k,int endNode){
    vector<bool> visited(n+1,false);
    vector<int> disForTom(n+1,-1);
    vector<bool> canFinish(n+1,false);
    disForTom[tomPos] = 0;
    visited[tomPos] = true;
    queue<int> q;
    q.push(tomPos);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first] && i.second == 2){
                visited[i.first] = true;
                q.push(i.first);
                disForTom[i.first] = disForTom[node] + 1;
            }
        }
    }
    fill(visited.begin(),visited.end(),false);
    visited[endNode] = true;
    q.push(endNode);
    priority_queue< pair<int,int> > pq;
    canFinish[endNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first] && i.first!=tomPos){
                //cout<<i.first<<" ";
                visited[i.first] = true;
                canFinish[i.first] = true;
                if(disForTom[i.first] == -1){
                    q.push(i.first);
                } else pq.push({disForTom[i.first],i.first});
            }
        }
    }
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            //cout<<i.first<<", dis:"<<disForTom[i.first]<<", "<<disForTom[node] - 1;
            if(i.first!=tomPos && !visited[i.first] && disForTom[node] != 1
            && disForTom[i.first] <= disForTom[node] - 1){
                //cout<<"jofele";
                canFinish[i.first] = true;
                pq.push({disForTom[i.first],i.first});
                disForTom[i.first] = disForTom[node] - 1;
            }
            //cout<<endl;
        }
    }
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        if(canFinish[x]) cout<<"IGEN"<<'\n';
        else cout<<"NEM"<<'\n';
    }
}

int main()
{
    int n,m,tomPos,k,endNode;
    cin>>n>>m>>tomPos>>k>>endNode;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }    
    if(tomPos == endNode){
        for(int i=1; i<=k; i++){
            int x;
            cin>>x;
            cout<<"NEM"<<'\n';
        }
        return 0;
    }
    solve(n,tomPos,k,endNode);
    return 0;
}