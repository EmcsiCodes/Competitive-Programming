#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[20001];


void BFS(int node,int n,vector< pair<int,int> > &dis){
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i].first = dis[node].first + 1;
            }
        }
    }
}

void findEndPoint(int start,int end,int n,vector<int> &pred){
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                pred[i] = node;
                if(i == end){
                    return;
                }
            }
        }
    }
}

void meetPoint(int n,int A,int B){
    vector< pair<int,int> > dis1(n+1,{0,0}), dis2(n+1,{0,0});
    for(int i=1; i<=n; i++){
        dis1[i].second = i;
        dis2[i].second = i;
    }
    BFS(A,n,dis1);
    BFS(B,n,dis2);
    sort(dis2.begin(),dis2.end());
    for(auto i:dis2){
        if(i.first > 0 && dis1[i.second].first!=0){
            cout<<i.second<<" "<<dis1[i.second].first<<" "<<dis2[i.second].first<<endl;
            vector<int> pred(n+1,-1);
            vector<int> path;
            findEndPoint(A,i.second,n,pred);
            int crawl = i.second;
            path.push_back(crawl);
            while (pred[crawl] != -1) {
                path.push_back(pred[crawl]);
                crawl = pred[crawl];
            }
            for (int i = path.size() - 1; i >= 0; i--){
                cout << path[i] << " ";
            }
            cout<<'/b'<<'/n';
            vector<int> pred(n+1,-1);
            vector<int> path;
            findEndPoint(B,i.second,n,pred);
            int crawl = i.second;
            path.push_back(crawl);
            while (pred[crawl] != -1) {
                path.push_back(pred[crawl]);
                crawl = pred[crawl];
            }
            for (int i = path.size() - 1; i >= 0; i--){
                cout << path[i] << " ";
            }
            cout<<'/b'<<'/n';
            return;
        }
    }
    cout<<0;
}

int main()
{
    int n,m,A,B;
    cin>>n>>m>>A>>B;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    return 0;
}