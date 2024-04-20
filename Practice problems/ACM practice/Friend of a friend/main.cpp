#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>

using namespace std;
ifstream in("fof.in");
ofstream out("fof.out");


bool comp(vector<int> a,vector<int> b){
    return a[1] > b[1];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> g[1001];
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        vector<vector<int>> v;
        unordered_map<int,int> ump;
        for(int j : g[i]){
            for(int k : g[j]){
                if(k != i) ump[k]++;   
            }
        }
        for(auto e : ump){
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end(), comp);
        for(auto e : v){
            cout<<e[0]<<" ";
        }
        cout<<endl;
    }
}
/*
2 3
1 2
2 3
*/