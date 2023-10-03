#include <iostream>
#include <vector>

using namespace std;

struct in{
    int dis;
    int h;
};

int main()
{
    int n;
    cin>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int i=0;
    int mostTree = 0;
    int mostTreeI = 0;
    int minCut = 0;
    while(i<v.size()){
        int maxDis = v[i].h + v[i].dis;
        int fallenTree = 0, currI = i + 1;
        while(i<v.size() && maxDis>v[i].dis){
            maxDis = max(maxDis, v[i].h + v[i].dis);
            fallenTree++;
            i++;
        }
        if(fallenTree > mostTree){
            mostTree = fallenTree;
            mostTreeI = currI;
        }
        minCut++;
    }
    cout<<minCut<<'\n'<<mostTreeI;
    return 0;
}
/*
5
0 6
3 1
5 2
8 1
15 10
*/