#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector< pair<int,int> > rails[201];
vector<int> railNodes[10001];
bool connectedRails[201][201] = {false};

void BFS(int startNode,int endNode,int railNum){
    queue<int> q;
    vector<bool> visited(railNum+1,false);
    vector<int> dis(railNum+1,0);
    vector< pair<int,int> > parent(railNum+1,{0,0});
    for(auto i:railNodes[startNode]){
        q.push(i);
        visited[i] = true;
    }
    vector<int> possibleEnd;
    for(auto i:railNodes[endNode]){
        possibleEnd.push_back(i);
    }
    while(!q.empty()){
        int rail = q.front();
        q.pop();
        for(auto i:rails[rail]){
            if(!visited[i.first]){
                visited[i.first] = true;
                q.push(i.first);
                dis[i.first] = dis[rail] + 1;
                parent[i.first] = {rail,i.second};
            }
        }
    }
    int minDis = 1000000;
    int railIndex = 0;
    for(auto i:possibleEnd){
        if(minDis > dis[i]){
            minDis = dis[i];
            railIndex = i;
        }
    }
    stack<int> res;
    pair<int,int> i = {railIndex,endNode};
    i = parent[i.first];
    while(i.first>0){
        res.push(i.second);
        i = parent[i.first];
    }
    cout<<res.size()<<'\n';
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    cout<<'\b';
}

int main()
{
    int nodeNum,railNum,startNode,endNode;
    cin>>nodeNum>>railNum>>startNode>>endNode;
    for(int i=1; i<=railNum; i++){
        int m;
        cin>>m;
        for(int j=1; j<=m; j++){
            int x;
            cin>>x;
            railNodes[x].push_back(i);
        }
    }
//a vasutakat node-okka alakitjuk, elmentjuk 2 vasut metszetet, ha 2 vasut metszi egymast, van ut a ket node kozott.
    for(int i=1; i<=nodeNum; i++){
        if(railNodes[i].size()>1){
            for(auto j = 0; j < railNodes[i].size(); j++){
                for(auto p = j + 1; p < railNodes[i].size(); p++){
                    int x = railNodes[i][j];
                    int y = railNodes[i][p];                
                    if(!connectedRails[x][y]){
                        rails[x].push_back({y,i});
                        rails[y].push_back({x,i});
                        connectedRails[x][y] = true;
                        connectedRails[y][x] = true;
                    }
                }
            }    
        }
    }
    BFS(startNode,endNode,railNum);
    return 0;
}
/*
16 5 10 16
6 11 10 9 3 4 5
5 5 4 6 12 13
6 1 2 3 6 7 8
3 14 4 15
2 8 16
*/