#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<bool> nonTricut(2*n+2,true);
    vector<int> dis(2*n+2,0);
    int l = 0;
    for(int i=1; i<=n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        nonTricut[x] = false;
        dis[x] = dis[x] + 1;
        dis[y] = dis[x];
        dis[z] = dis[x];
        l = max(l,max(x,max(y,z)));
    }
    int maxCutNum = 0, minCutNum = 100000000;
    vector<int> nonCut, maxCut, minCut;
    for(int i=1; i<=l; i++){
        minCutNum = min(minCutNum, dis[i]);
        maxCutNum = max(maxCutNum, dis[i]);
        if(nonTricut[i]) nonCut.push_back(i);
    }
    for(int i=1; i<=l; i++){
        if(minCutNum == dis[i]) minCut.push_back(i);
        if(maxCutNum == dis[i]) maxCut.push_back(i);
    }
    cout<<maxCut.size()<<" ";
    for(auto i:maxCut) cout<<i<<" ";
    cout<<'\n';
    cout<<minCut.size()<<" ";
    for(auto i:minCut) cout<<i<<" ";
    cout<<'\n';
    cout<<nonCut.size()<<" ";
    for(auto i:nonCut) cout<<i<<" ";
    return 0;
}
/*
4
1 2 3
2 4 5
4 6 7
7 8 9
*/