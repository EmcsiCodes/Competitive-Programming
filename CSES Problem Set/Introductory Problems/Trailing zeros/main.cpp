#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int res = 0;
    int t = 5;
    while(t<=n){
        res += n/t;
        t *= 5;
    }
    cout<<res;
    return 0;
}