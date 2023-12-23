#include <iostream>
using namespace std;

#define ll long long
int main()
{
    int n;
    cin>>n;
    ll res = 1;
    for(int i=1; i<=n; i++){
        res = (res*2)%1000000007;
    }
    cout<<res;
    return 0;
}