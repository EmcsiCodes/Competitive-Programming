#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,b;
    bool v1[10001],v2[10001],v3[10001];
    cin>>n>>b;
    for(int i=1; i<=n; i++){
        v1[i]=false;
        v2[i]=false;
        v3[i]=false;
    }
    for(int i=0; i<b; i++){
        int x,y;
        cin>>x>>y;
        if(x==1) v1[y] = 1;
        if(x==2) v2[y] = 1;
        if(x==3) v3[y] = 1;
    }
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(!(v1[i]==true && v2[i]==true && v3[i]==true) && (v1[i]==true || v2[i]==true || v3[i]==true)) res.push_back(i);
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i<<" ";
    return 0;
}