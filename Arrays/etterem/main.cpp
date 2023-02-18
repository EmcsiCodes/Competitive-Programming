#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    map<int,int> m;
    cin>>n;
    for(int i=1; i<=n;i++){
        int k;
        cin>>k;
        for(int j=1; j<=k; j++){
            int x,y;
            cin>>x>>y;
            m[x]+=y;
        }
    }
    cout<<m.size()<<endl;
    for(auto i=m.begin(); i!=m.end(); i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
/*
3
2 100 3 400 7
2 400 3 200 5
3 1357 3 42 42 100 2
*/
    return 0;
}
