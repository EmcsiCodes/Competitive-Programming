#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[4001];
int maxDis = 0;
int maxDisIndex = 0;
int A = 0,B = 0, numA = 0,numB = 0;

void BFS(int start,int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0), path(n+1,0);
    queue<int> q;
    int num = 0;
    q.push(start);
    visited[start] = true;
    visited[A] = true;
    visited[B] = true;
    while(!q.empty()){
        num++;
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
                path[i] = node;
                if(dis[i] > maxDis){
                    maxDis = dis[i];
                    maxDisIndex = i;
                }
            }
        }
    }
    if(start != 1 && A==0){
        int mid = maxDis / 2;
        A = maxDisIndex;
        for(int i=1; i<mid; i++){
            A = path[A];
        }
        B = path[A];
    }
    if(start == A){
        numA = num;
    }
    if(start == B){
        numB = num;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(1,n);
    BFS(maxDisIndex,n);
    BFS(A,n);
    BFS(B,n);
    cout<<abs(numA - numB);
    return 0;
}
/*

*/