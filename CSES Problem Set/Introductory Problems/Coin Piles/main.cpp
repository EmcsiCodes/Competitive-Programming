#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int testnum;
    cin>>testnum;
    for(int i=0; i<testnum; i++){
        int a,b;
        cin>>a>>b;
        if(a == 0 && b == 0) {
            cout<<"YES"<<'\n';
            continue;
        }
        if((a+b)%3!=0 || b<ceil(a/2) || a<ceil(b/2) || a == 0 || b == 0) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
    return 0;
}