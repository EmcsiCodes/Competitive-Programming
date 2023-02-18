#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    map<int,int> m;
    cin>>n;
    for(int i=1; i<=3; i++){
        int x;
        cin>>x;
        for(int j=1; j<=x; j++){
            int y; cin>>y;
            m[y]++;
        }
    }
    int c=0;
    for(auto i:m){
        if(i.second==2) c++;
    }
    cout<<c<<endl;
    for(auto i:m){
        if(i.second==2) cout<<i.first<<" ";
    }
    return 0;
}
