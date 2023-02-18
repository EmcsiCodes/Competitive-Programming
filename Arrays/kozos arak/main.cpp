#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map <int,int> p1,p2;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        p1[x]=1;
    }
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        p2[x]=1;
    }
    int maxx=0,minn=1001;
    for(auto it : p1){
        if(p2[it.first]==1) {
            maxx=max(maxx,it.first);
            minn=min(minn,it.first);
        }
    }
    if(minn==1001) cout<<0<<" "<<0<<endl;
    else cout<<minn<<" "<<maxx;
    return 0;
}
/*
4 3
100 500 200 300
200 300 200

*/
