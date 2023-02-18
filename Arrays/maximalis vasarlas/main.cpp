#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    set<long long> s;
    unordered_map<long long,int> u1,u2;
    for(int i=1; i<=n; i++){
        long long x;
        int y;
        cin>>x>>y;
        u1[x]=y;
        s.insert(x);
    }
    for(int i=1; i<=m; i++){
        long long x;
        int y;
        cin>>x>>y;
        u2[x]=y;
        s.insert(x);
    }
    for(auto it : s){
        cout<<max(u1[it],u2[it])<<" ";
    }
    cout<<endl;
    for(auto it : s){
        cout<<u1[it]+u2[it]<<" ";
    }
    return 0;
}
