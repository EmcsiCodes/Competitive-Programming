#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,m,x,db=0;
    cin>>n>>m>>x;
    map<int,int> ma;
    for(int i=1; i<=n+m; i++){
        int x,y;
        cin>>x>>y;
        if(ma[x]!=0) {
                ma[x]=min(y,ma[x]);
        }
        else ma[x]=y;
    }

    for(auto it : ma){
        if(it.second<x) db++;
    }
    cout<<db<<endl;
    for(auto it : ma){
        if(it.second<x) cout<<it.first<<" ";
    }
    return 0;
}
