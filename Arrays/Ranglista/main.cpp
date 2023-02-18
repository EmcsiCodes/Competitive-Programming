#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n,l,k=1;
    cin>>n>>l;
    set< pair<int,int> > s;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        for(int j=1; j<=x; j++){
            int y;
            cin>>y;
            s.insert(make_pair(y,k));
        }
        k++;
    }
    map<int,int> m;
    int l1=l;
    for(auto it=s.rbegin(); it!=s.rend(); it++){
        m[it->second]++;
        l1--;
        if(l1==0) break;
    }
    int o=0,index=0;
    for(auto it:m) {
        if(it.second>o){
            index=it.first;
            o=it.second;
        }
    }
    cout<<index<<endl;
    for(auto it=s.rbegin(); it!=s.rend(); it++){
        cout<<it->first<<endl;
        l--;
        if(l==0) break;
    }
    return 0;
}
