#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> words[21];
map<string, vector<string> > adj;
map<string, bool> visited;
map<string,int> dis;
bool found = false;

bool connect(int l){
    bool nextConnect = false;
    for(int i=0; i<words[l].size(); i++){
        string p = words[l][i].substr(0,l-1);
        if(adj.find(p)!=adj.end()){
            adj[words[l][i]].push_back(p);
            adj[p].push_back(words[l][i]);
            nextConnect = true;
        }
    }
    return nextConnect;
}

void BFS(string start,string end, int n){

    queue<string> q;
    q.push(start);

    while(!q.empty()){
        string node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(visited[i] == false){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
    }
    if(!found) {
        if(dis[end]!=0) cout<<dis[end]<<'\n';
        else cout<<-1<<'\n';
    }
    int wordNum = 0;
    for(auto i:dis){
        if(i.second!=0) wordNum++;
    }
    cout<<wordNum;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        if(visited.find(s)==visited.end()){
            visited[s] = false;
            dis[s] = 0;
            words[s.length()].push_back(s);
        }
    }
    char rule;
    cin>>rule;
    string start, end;
    cin>>start>>end;
    if(end.size()<start.size()) {
        found = true;
        cout<<-1<<'\n';
    }
    if(rule == 'A' && start.size()!=end.size()) {
        found = true;
        cout<<-1<<'\n';
    }
    int l = start.length();

    for(int i=0; i<words[l].size() - 1; i++){
        for(int j=i+1; j<words[l].size(); j++){
            if(words[l][i]!=words[l][j]){
                int diff = 0;
                bool canConnect = true;
                for(int p = 0; p<l; p++){
                    if(words[l][i][p]!=words[l][j][p]) diff++;
                    if(diff>1) {
                        canConnect = false;
                        break;
                    }
                }
                if(canConnect){
                    adj[words[l][i]].push_back(words[l][j]);
                    adj[words[l][j]].push_back(words[l][i]);
                }
            }
        }
    }
    if(rule == 'B'){
        l = start.length() + 1;
        while(connect(l)) l++;
    }
    BFS(start,end,n);
    /*for(auto i:adj){
        cout<<i.first<<": ";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
/*
7
OKOS
ÁKOS
ÁKOM
OKOD
ÁLOM
ALOM
HALOM
A
OKOS
ÁLOM
*/