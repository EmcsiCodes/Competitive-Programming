#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

void BFS(int start,int n){
    queue<int> q;
    vector<bool> visited(n+1,false);
    visited[start] = true;
    q.push(start);
    int backnode = q.back();
    int mostPeople = 0;
    int mostPeopleI = 0;
    int day = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }            
        if(backnode == node){
            backnode = q.back();
            day++;
            if(mostPeople < q.size()){
                mostPeople = q.size();
                mostPeopleI = day;
            }
            
        }
    }
    cout<<mostPeopleI;
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
    return 0;
}
/*
12
1 2
1 3
2 4
2 5
3 6
5 7
5 8
6 9
6 10
10 11
10 12
*/